/****************************************************************************
** Meta object code from reading C++ file 'qxtrpcservice_p.h'
**
** Created: Thu 21. Mar 19:10:21 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qxtrpcservice_p.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qxtrpcservice_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QxtRPCServicePrivate[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      29,   22,   21,   21, 0x0a,
      65,   22,   21,   21, 0x0a,
     107,  104,   21,   21, 0x0a,
     127,   21,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QxtRPCServicePrivate[] = {
    "QxtRPCServicePrivate\0\0dev,id\0"
    "clientConnected(QIODevice*,quint64)\0"
    "clientDisconnected(QIODevice*,quint64)\0"
    "id\0clientData(quint64)\0serverData()\0"
};

void QxtRPCServicePrivate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QxtRPCServicePrivate *_t = static_cast<QxtRPCServicePrivate *>(_o);
        switch (_id) {
        case 0: _t->clientConnected((*reinterpret_cast< QIODevice*(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2]))); break;
        case 1: _t->clientDisconnected((*reinterpret_cast< QIODevice*(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2]))); break;
        case 2: _t->clientData((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 3: _t->serverData(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QxtRPCServicePrivate::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QxtRPCServicePrivate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QxtRPCServicePrivate,
      qt_meta_data_QxtRPCServicePrivate, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QxtRPCServicePrivate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QxtRPCServicePrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QxtRPCServicePrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QxtRPCServicePrivate))
        return static_cast<void*>(const_cast< QxtRPCServicePrivate*>(this));
    if (!strcmp(_clname, "QxtPrivate<QxtRPCService>"))
        return static_cast< QxtPrivate<QxtRPCService>*>(const_cast< QxtRPCServicePrivate*>(this));
    return QObject::qt_metacast(_clname);
}

int QxtRPCServicePrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
