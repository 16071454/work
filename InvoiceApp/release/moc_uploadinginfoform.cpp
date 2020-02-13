/****************************************************************************
** Meta object code from reading C++ file 'uploadinginfoform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../uploadinginfoform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uploadinginfoform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UploadingInfoForm_t {
    QByteArrayData data[11];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UploadingInfoForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UploadingInfoForm_t qt_meta_stringdata_UploadingInfoForm = {
    {
QT_MOC_LITERAL(0, 0, 17), // "UploadingInfoForm"
QT_MOC_LITERAL(1, 18, 21), // "signal_set_refundname"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 4), // "info"
QT_MOC_LITERAL(4, 46, 19), // "signal_start_thread"
QT_MOC_LITERAL(5, 66, 4), // "code"
QT_MOC_LITERAL(6, 71, 16), // "signal_setbutton"
QT_MOC_LITERAL(7, 88, 16), // "slot_getemployer"
QT_MOC_LITERAL(8, 105, 4), // "list"
QT_MOC_LITERAL(9, 110, 20), // "slot_repeat_fourcode"
QT_MOC_LITERAL(10, 131, 34) // "on_lineEdit_fourcode_returnPr..."

    },
    "UploadingInfoForm\0signal_set_refundname\0"
    "\0info\0signal_start_thread\0code\0"
    "signal_setbutton\0slot_getemployer\0"
    "list\0slot_repeat_fourcode\0"
    "on_lineEdit_fourcode_returnPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UploadingInfoForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   53,    2, 0x0a /* Public */,
       9,    0,   56,    2, 0x0a /* Public */,
      10,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UploadingInfoForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UploadingInfoForm *_t = static_cast<UploadingInfoForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_set_refundname((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->signal_start_thread((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->signal_setbutton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->slot_getemployer((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 4: _t->slot_repeat_fourcode(); break;
        case 5: _t->on_lineEdit_fourcode_returnPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UploadingInfoForm::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UploadingInfoForm::signal_set_refundname)) {
                *result = 0;
            }
        }
        {
            typedef void (UploadingInfoForm::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UploadingInfoForm::signal_start_thread)) {
                *result = 1;
            }
        }
        {
            typedef void (UploadingInfoForm::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UploadingInfoForm::signal_setbutton)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject UploadingInfoForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UploadingInfoForm.data,
      qt_meta_data_UploadingInfoForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UploadingInfoForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UploadingInfoForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UploadingInfoForm.stringdata0))
        return static_cast<void*>(const_cast< UploadingInfoForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int UploadingInfoForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void UploadingInfoForm::signal_set_refundname(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UploadingInfoForm::signal_start_thread(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UploadingInfoForm::signal_setbutton(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
