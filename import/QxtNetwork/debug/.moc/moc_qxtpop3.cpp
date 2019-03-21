/****************************************************************************
** Meta object code from reading C++ file 'qxtpop3.h'
**
** Created: Thu 21. Mar 19:13:30 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qxtpop3.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qxtpop3.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QxtPop3[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      25,   21,    8,    8, 0x05,
      54,    8,    8,    8, 0x05,
      66,   21,    8,    8, 0x05,
      95,    8,    8,    8, 0x05,
     111,   21,    8,    8, 0x05,
     144,    8,    8,    8, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_QxtPop3[] = {
    "QxtPop3\0\0connected()\0msg\0"
    "connectionFailed(QByteArray)\0encrypted()\0"
    "encryptionFailed(QByteArray)\0"
    "authenticated()\0authenticationFailed(QByteArray)\0"
    "disconnected()\0"
};

void QxtPop3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QxtPop3 *_t = static_cast<QxtPop3 *>(_o);
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->connectionFailed((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 2: _t->encrypted(); break;
        case 3: _t->encryptionFailed((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 4: _t->authenticated(); break;
        case 5: _t->authenticationFailed((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 6: _t->disconnected(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QxtPop3::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QxtPop3::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QxtPop3,
      qt_meta_data_QxtPop3, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QxtPop3::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QxtPop3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QxtPop3::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QxtPop3))
        return static_cast<void*>(const_cast< QxtPop3*>(this));
    return QObject::qt_metacast(_clname);
}

int QxtPop3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QxtPop3::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QxtPop3::connectionFailed(const QByteArray & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QxtPop3::encrypted()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QxtPop3::encryptionFailed(const QByteArray & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QxtPop3::authenticated()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void QxtPop3::authenticationFailed(const QByteArray & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QxtPop3::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
