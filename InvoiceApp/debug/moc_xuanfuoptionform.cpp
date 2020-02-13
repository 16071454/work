/****************************************************************************
** Meta object code from reading C++ file 'xuanfuoptionform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../xuanfuoptionform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xuanfuoptionform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_xuanfuoptionForm_t {
    QByteArrayData data[10];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_xuanfuoptionForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_xuanfuoptionForm_t qt_meta_stringdata_xuanfuoptionForm = {
    {
QT_MOC_LITERAL(0, 0, 16), // "xuanfuoptionForm"
QT_MOC_LITERAL(1, 17, 15), // "signal_show_pic"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 17), // "signal_delete_pic"
QT_MOC_LITERAL(4, 52, 18), // "signal_jiangji_pic"
QT_MOC_LITERAL(5, 71, 9), // "slot_show"
QT_MOC_LITERAL(6, 81, 9), // "slot_hide"
QT_MOC_LITERAL(7, 91, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(8, 113, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(9, 137, 23) // "on_pushButton_3_clicked"

    },
    "xuanfuoptionForm\0signal_show_pic\0\0"
    "signal_delete_pic\0signal_jiangji_pic\0"
    "slot_show\0slot_hide\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_xuanfuoptionForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void xuanfuoptionForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        xuanfuoptionForm *_t = static_cast<xuanfuoptionForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_show_pic(); break;
        case 1: _t->signal_delete_pic(); break;
        case 2: _t->signal_jiangji_pic(); break;
        case 3: _t->slot_show(); break;
        case 4: _t->slot_hide(); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->on_pushButton_2_clicked(); break;
        case 7: _t->on_pushButton_3_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (xuanfuoptionForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&xuanfuoptionForm::signal_show_pic)) {
                *result = 0;
            }
        }
        {
            typedef void (xuanfuoptionForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&xuanfuoptionForm::signal_delete_pic)) {
                *result = 1;
            }
        }
        {
            typedef void (xuanfuoptionForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&xuanfuoptionForm::signal_jiangji_pic)) {
                *result = 2;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject xuanfuoptionForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_xuanfuoptionForm.data,
      qt_meta_data_xuanfuoptionForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *xuanfuoptionForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *xuanfuoptionForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_xuanfuoptionForm.stringdata0))
        return static_cast<void*>(const_cast< xuanfuoptionForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int xuanfuoptionForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void xuanfuoptionForm::signal_show_pic()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void xuanfuoptionForm::signal_delete_pic()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void xuanfuoptionForm::signal_jiangji_pic()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
