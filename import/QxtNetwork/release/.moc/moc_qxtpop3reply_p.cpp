/****************************************************************************
** Meta object code from reading C++ file 'qxtpop3reply_p.h'
**
** Created: Thu 21. Mar 18:57:37 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qxtpop3reply_p.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qxtpop3reply_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QxtPop3ReplyPrivate[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QxtPop3ReplyPrivate[] = {
    "QxtPop3ReplyPrivate\0\0timedOut()\0"
};

void QxtPop3ReplyPrivate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QxtPop3ReplyPrivate *_t = static_cast<QxtPop3ReplyPrivate *>(_o);
        switch (_id) {
        case 0: _t->timedOut(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QxtPop3ReplyPrivate::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QxtPop3ReplyPrivate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QxtPop3ReplyPrivate,
      qt_meta_data_QxtPop3ReplyPrivate, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QxtPop3ReplyPrivate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QxtPop3ReplyPrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QxtPop3ReplyPrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QxtPop3ReplyPrivate))
        return static_cast<void*>(const_cast< QxtPop3ReplyPrivate*>(this));
    if (!strcmp(_clname, "QxtPrivate<QxtPop3Reply>"))
        return static_cast< QxtPrivate<QxtPop3Reply>*>(const_cast< QxtPop3ReplyPrivate*>(this));
    return QObject::qt_metacast(_clname);
}

int QxtPop3ReplyPrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
