/****************************************************************************
** Meta object code from reading C++ file 'qxtpop3_p.h'
**
** Created: Thu 21. Mar 18:57:35 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qxtpop3_p.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qxtpop3_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QxtPop3Private[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   16,   15,   15, 0x0a,
      62,   15,   15,   15, 0x0a,
      77,   15,   15,   15, 0x0a,
      90,   15,   15,   15, 0x0a,
     105,  100,   15,   15, 0x0a,
     120,   15,   15,   15, 0x0a,
     132,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QxtPop3Private[] = {
    "QxtPop3Private\0\0err\0"
    "socketError(QAbstractSocket::SocketError)\0"
    "disconnected()\0socketRead()\0dequeue()\0"
    "code\0terminate(int)\0encrypted()\0"
    "authenticated()\0"
};

void QxtPop3Private::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QxtPop3Private *_t = static_cast<QxtPop3Private *>(_o);
        switch (_id) {
        case 0: _t->socketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 1: _t->disconnected(); break;
        case 2: _t->socketRead(); break;
        case 3: _t->dequeue(); break;
        case 4: _t->terminate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->encrypted(); break;
        case 6: _t->authenticated(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QxtPop3Private::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QxtPop3Private::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QxtPop3Private,
      qt_meta_data_QxtPop3Private, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QxtPop3Private::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QxtPop3Private::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QxtPop3Private::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QxtPop3Private))
        return static_cast<void*>(const_cast< QxtPop3Private*>(this));
    if (!strcmp(_clname, "QxtPrivate<QxtPop3>"))
        return static_cast< QxtPrivate<QxtPop3>*>(const_cast< QxtPop3Private*>(this));
    return QObject::qt_metacast(_clname);
}

int QxtPop3Private::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
