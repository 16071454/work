/****************************************************************************
** Meta object code from reading C++ file 'scanoptionform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../scanoptionform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scanoptionform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_scanoptionForm_t {
    QByteArrayData data[10];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_scanoptionForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_scanoptionForm_t qt_meta_stringdata_scanoptionForm = {
    {
QT_MOC_LITERAL(0, 0, 14), // "scanoptionForm"
QT_MOC_LITERAL(1, 15, 20), // "signal_continue_scan"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 17), // "signal_reset_data"
QT_MOC_LITERAL(4, 55, 20), // "signal_check_invoice"
QT_MOC_LITERAL(5, 76, 17), // "signal_read_excel"
QT_MOC_LITERAL(6, 94, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 116, 23), // "on_toolButton_3_clicked"
QT_MOC_LITERAL(8, 140, 23), // "on_toolButton_2_clicked"
QT_MOC_LITERAL(9, 164, 27) // "on_toolButton_reset_clicked"

    },
    "scanoptionForm\0signal_continue_scan\0"
    "\0signal_reset_data\0signal_check_invoice\0"
    "signal_read_excel\0on_pushButton_clicked\0"
    "on_toolButton_3_clicked\0on_toolButton_2_clicked\0"
    "on_toolButton_reset_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_scanoptionForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void scanoptionForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        scanoptionForm *_t = static_cast<scanoptionForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_continue_scan(); break;
        case 1: _t->signal_reset_data(); break;
        case 2: _t->signal_check_invoice(); break;
        case 3: _t->signal_read_excel(); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_toolButton_3_clicked(); break;
        case 6: _t->on_toolButton_2_clicked(); break;
        case 7: _t->on_toolButton_reset_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (scanoptionForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&scanoptionForm::signal_continue_scan)) {
                *result = 0;
            }
        }
        {
            typedef void (scanoptionForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&scanoptionForm::signal_reset_data)) {
                *result = 1;
            }
        }
        {
            typedef void (scanoptionForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&scanoptionForm::signal_check_invoice)) {
                *result = 2;
            }
        }
        {
            typedef void (scanoptionForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&scanoptionForm::signal_read_excel)) {
                *result = 3;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject scanoptionForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_scanoptionForm.data,
      qt_meta_data_scanoptionForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *scanoptionForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *scanoptionForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_scanoptionForm.stringdata0))
        return static_cast<void*>(const_cast< scanoptionForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int scanoptionForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void scanoptionForm::signal_continue_scan()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void scanoptionForm::signal_reset_data()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void scanoptionForm::signal_check_invoice()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void scanoptionForm::signal_read_excel()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
