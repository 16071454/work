/****************************************************************************
** Meta object code from reading C++ file 'scanverticalform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../scanverticalform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scanverticalform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ScanVerticalForm_t {
    QByteArrayData data[9];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScanVerticalForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScanVerticalForm_t qt_meta_stringdata_ScanVerticalForm = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ScanVerticalForm"
QT_MOC_LITERAL(1, 17, 19), // "signal_modify_label"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 11), // "INVOICETYPE"
QT_MOC_LITERAL(4, 50, 21), // "on_toolButton_clicked"
QT_MOC_LITERAL(5, 72, 23), // "on_toolButton_2_clicked"
QT_MOC_LITERAL(6, 96, 23), // "on_toolButton_3_clicked"
QT_MOC_LITERAL(7, 120, 23), // "on_toolButton_4_clicked"
QT_MOC_LITERAL(8, 144, 23) // "on_toolButton_5_clicked"

    },
    "ScanVerticalForm\0signal_modify_label\0"
    "\0INVOICETYPE\0on_toolButton_clicked\0"
    "on_toolButton_2_clicked\0on_toolButton_3_clicked\0"
    "on_toolButton_4_clicked\0on_toolButton_5_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScanVerticalForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   47,    2, 0x08 /* Private */,
       5,    0,   48,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ScanVerticalForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScanVerticalForm *_t = static_cast<ScanVerticalForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_modify_label((*reinterpret_cast< INVOICETYPE(*)>(_a[1]))); break;
        case 1: _t->on_toolButton_clicked(); break;
        case 2: _t->on_toolButton_2_clicked(); break;
        case 3: _t->on_toolButton_3_clicked(); break;
        case 4: _t->on_toolButton_4_clicked(); break;
        case 5: _t->on_toolButton_5_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ScanVerticalForm::*_t)(INVOICETYPE );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScanVerticalForm::signal_modify_label)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ScanVerticalForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ScanVerticalForm.data,
      qt_meta_data_ScanVerticalForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ScanVerticalForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScanVerticalForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ScanVerticalForm.stringdata0))
        return static_cast<void*>(const_cast< ScanVerticalForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int ScanVerticalForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ScanVerticalForm::signal_modify_label(INVOICETYPE _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
