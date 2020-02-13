/****************************************************************************
** Meta object code from reading C++ file 'extengroupform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../extengroupform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'extengroupform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_extengroupForm_t {
    QByteArrayData data[12];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_extengroupForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_extengroupForm_t qt_meta_stringdata_extengroupForm = {
    {
QT_MOC_LITERAL(0, 0, 14), // "extengroupForm"
QT_MOC_LITERAL(1, 15, 13), // "signal_isshow"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 16), // "signal_scan_show"
QT_MOC_LITERAL(4, 47, 11), // "INVOICETYPE"
QT_MOC_LITERAL(5, 59, 4), // "type"
QT_MOC_LITERAL(6, 64, 23), // "on_toolButton_5_clicked"
QT_MOC_LITERAL(7, 88, 21), // "on_toolButton_clicked"
QT_MOC_LITERAL(8, 110, 23), // "on_toolButton_2_clicked"
QT_MOC_LITERAL(9, 134, 23), // "on_toolButton_3_clicked"
QT_MOC_LITERAL(10, 158, 23), // "on_toolButton_6_clicked"
QT_MOC_LITERAL(11, 182, 23) // "on_toolButton_4_clicked"

    },
    "extengroupForm\0signal_isshow\0\0"
    "signal_scan_show\0INVOICETYPE\0type\0"
    "on_toolButton_5_clicked\0on_toolButton_clicked\0"
    "on_toolButton_2_clicked\0on_toolButton_3_clicked\0"
    "on_toolButton_6_clicked\0on_toolButton_4_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_extengroupForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,
      10,    0,   62,    2, 0x08 /* Private */,
      11,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void extengroupForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        extengroupForm *_t = static_cast<extengroupForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_isshow(); break;
        case 1: _t->signal_scan_show((*reinterpret_cast< INVOICETYPE(*)>(_a[1]))); break;
        case 2: _t->on_toolButton_5_clicked(); break;
        case 3: _t->on_toolButton_clicked(); break;
        case 4: _t->on_toolButton_2_clicked(); break;
        case 5: _t->on_toolButton_3_clicked(); break;
        case 6: _t->on_toolButton_6_clicked(); break;
        case 7: _t->on_toolButton_4_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (extengroupForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&extengroupForm::signal_isshow)) {
                *result = 0;
            }
        }
        {
            typedef void (extengroupForm::*_t)(INVOICETYPE );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&extengroupForm::signal_scan_show)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject extengroupForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_extengroupForm.data,
      qt_meta_data_extengroupForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *extengroupForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *extengroupForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_extengroupForm.stringdata0))
        return static_cast<void*>(const_cast< extengroupForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int extengroupForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void extengroupForm::signal_isshow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void extengroupForm::signal_scan_show(INVOICETYPE _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
