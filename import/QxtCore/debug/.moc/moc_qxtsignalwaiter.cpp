/****************************************************************************
** Meta object code from reading C++ file 'qxtsignalwaiter.h'
**
** Created: Thu 21. Mar 19:10:16 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qxtsignalwaiter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qxtsignalwaiter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QxtSignalWaiter[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      32,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QxtSignalWaiter[] = {
    "QxtSignalWaiter\0\0signalCaught()\0"
    "cancelWait()\0"
};

void QxtSignalWaiter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QxtSignalWaiter *_t = static_cast<QxtSignalWaiter *>(_o);
        switch (_id) {
        case 0: _t->signalCaught(); break;
        case 1: _t->cancelWait(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QxtSignalWaiter::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QxtSignalWaiter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QxtSignalWaiter,
      qt_meta_data_QxtSignalWaiter, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QxtSignalWaiter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QxtSignalWaiter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QxtSignalWaiter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QxtSignalWaiter))
        return static_cast<void*>(const_cast< QxtSignalWaiter*>(this));
    return QObject::qt_metacast(_clname);
}

int QxtSignalWaiter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
