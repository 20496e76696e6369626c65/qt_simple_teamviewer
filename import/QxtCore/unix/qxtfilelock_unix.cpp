#include "qxtfilelock.h"
/****************************************************************************
** Copyright (c) 2006 - 2011, the LibQxt project.
** See the Qxt AUTHORS file for a list of authors and copyright holders.
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
**     * Redistributions of source code must retain the above copyright
**       notice, this list of conditions and the following disclaimer.
**     * Redistributions in binary form must reproduce the above copyright
**       notice, this list of conditions and the following disclaimer in the
**       documentation and/or other materials provided with the distribution.
**     * Neither the name of the LibQxt project nor the
**       names of its contributors may be used to endorse or promote products
**       derived from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
** DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
** ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
** <http://libqxt.org>  <foundation@libqxt.org>
*****************************************************************************/

#include "qxtfilelock_p.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
/*include pthread to make errno threadsafe*/
#include <pthread.h>
#include <errno.h>
#include <QPointer>
#include <QMutableLinkedListIterator>
#include <QDebug>

/*!
 * \internal
 *  This class is used on *nix to register all locks created by a process
 *  and to let locks on *nix act like locks on Windows.
 */
class QxtFileLockRegistry
{
public:
    bool registerLock(QxtFileLock *lock);
    bool removeLock(QxtFileLock *lock);
    static QxtFileLockRegistry& instance();

private:
    QLinkedList < QPointer<QxtFileLock> > procLocks;
    QMutex registryMutex;
    QxtFileLockRegistry();
};

QxtFileLockRegistry::QxtFileLockRegistry()
{}

QxtFileLockRegistry& QxtFileLockRegistry::instance()
{
    static QxtFileLockRegistry instance;
    return instance;
}

/*!
 * \internal this function locks the lockregistry and checks if there is a collision between the process locks
 * \internal if there is no collision it inserts the lock into the registry and returns
 * \internal return true for success
 */
bool QxtFileLockRegistry::registerLock(QxtFileLock * lock)
{
    QMutexLocker locker(&this->registryMutex);

    QFile *fileToLock = lock ->file();

    if (fileToLock)
    {
        struct stat fileInfo;
        if (fstat(fileToLock->handle(), &fileInfo) < 0)
            return false;

        int newLockStart = lock ->offset();
        int newLockEnd = lock ->offset() + lock ->length();

        QMutableLinkedListIterator< QPointer<QxtFileLock> >iterator(this->procLocks);

        while (iterator.hasNext())
        {
            QPointer<QxtFileLock> currLock = iterator.next();
            if (currLock && currLock->file() && currLock->file()->isOpen())
            {
                struct stat currFileInfo;

                /*first check if the current lock is on the same file*/
                if (fstat(currLock->file()->handle(), &currFileInfo) < 0)
                {
                    /*that should never happen because a closing file should remove all locks*/
                    Q_ASSERT(false);
                    continue;
                }

                if (currFileInfo.st_dev == fileInfo.st_dev && currFileInfo.st_ino == fileInfo.st_ino)
                {
                    /*same file, check if our locks are in conflict*/
                    int currLockStart = currLock->offset();
                    int currLockEnd = currLock->offset() + currLock->length();

                    /*do we have to check for threads here?*/
                    if (newLockEnd >= currLockStart  && newLockStart <= currLockEnd)
                    {
                        //qDebug() << "we may have a collision";
                        //qDebug() << newLockEnd << " >= " << currLockStart << "  &&  " << newLockStart << " <= " << currLockEnd;

                        /*same lock region if one of both locks are exclusive we have a collision*/
                        if (lock ->mode() == QxtFileLock::WriteLockWait || lock ->mode() == QxtFileLock::WriteLock ||
                                currLock->mode() == QxtFileLock::WriteLockWait || currLock->mode() == QxtFileLock::WriteLock)
                        {
                            /*FIXED BUG #6 test rw_same() passes on Unix
                              keeping the old code for a while
                              */
                            return false;
#if 0
                           //qDebug() << "Okay if this is not the same thread using the same handle there is a collision";
                            /*the same thread  can lock the same region with the same handle*/

                            //qDebug() << "! (" << lock ->thread() << " == " << currLock->thread() << " && " << lock ->file()->handle() << " == " << currLock->file()->handle() << ")";

                            if (!(lock ->thread() == currLock->thread() && lock ->file()->handle() == currLock->file()->handle()))
                            {
                                qDebug() << "Collision";
                                return false;
                            }
#endif
                        }
                    }
                }
            }
            else //remove dead locks
                iterator.remove();
        }
        //qDebug() << "The lock is okay";
        /*here we can insert the lock into the list and return*/
        procLocks.append(QPointer<QxtFileLock>(lock));
        return true;

    }

    return false;
}

bool QxtFileLockRegistry::removeLock(QxtFileLock * lock)
{
    QMutexLocker locker(&this->registryMutex);
    procLocks.removeAll(lock);
    return true;
}

bool QxtFileLock::unlock()
{
    if (file() && file()->isOpen() && isActive())
    {
        /*first remove real lock*/
        int lockmode,  locktype;
        int result = -1;
        struct  flock lockDesc;

        lockmode = F_SETLK;
        locktype = F_UNLCK;

        errno = 0;
        do
        {
            lockDesc.l_type = locktype;
            lockDesc.l_whence = SEEK_SET;
            lockDesc.l_start = qxt_d().offset;
            lockDesc.l_len = qxt_d().length;
            lockDesc.l_pid = 0;
            result = fcntl(this->file()->handle(), lockmode, &lockDesc);
        }
        while (result && errno == EINTR);

        QxtFileLockRegistry::instance().removeLock(this);
        qxt_d().isLocked = false;
        return true;
    }
    return false;
}

bool QxtFileLock::lock()
{
    if (file() && file()->isOpen() && !isActive())
    {
        /*this has to block if we can get no lock*/

        bool locked = false;

        while (1)
        {
            locked = QxtFileLockRegistry::instance().registerLock(this);
            if (locked)
                break;
            else
            {
                if (qxt_d().mode == ReadLockWait || qxt_d().mode == WriteLockWait)
                    usleep(1000 * 5);
                else
                    return false;
            }
        }

        /*now get real lock*/
        int lockmode,
        locktype;

        int result = -1;

        struct  flock lockDesc;

        switch (qxt_d().mode)
        {
        case    ReadLock:
            lockmode = F_SETLK;
            locktype = F_RDLCK;
            break;

        case    ReadLockWait:
            lockmode = F_SETLKW;
            locktype = F_RDLCK;
            break;

        case    WriteLock:
            lockmode = F_SETLK;
            locktype = F_WRLCK;
            break;

        case    WriteLockWait:
            lockmode = F_SETLKW;
            locktype = F_WRLCK;
            break;

        default:
            QxtFileLockRegistry::instance().removeLock(this);
            return (false);
            break;
        }

        errno = 0;
        do
        {
            lockDesc.l_type = locktype;
            lockDesc.l_whence = SEEK_SET;
            lockDesc.l_start = qxt_d().offset;
            lockDesc.l_len = qxt_d().length;
            lockDesc.l_pid = 0;
            result = fcntl(this->file()->handle(), lockmode, &lockDesc);
        }
        while (result && errno == EINTR);

        /*we dot get the lock unregister from lockregistry and return*/
        if (result == -1)
        {
            QxtFileLockRegistry::instance().removeLock(this);
            return false;
        }

        qxt_d().isLocked = true;
        return true;
    }
    return false;
}
