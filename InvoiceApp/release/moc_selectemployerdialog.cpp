/****************************************************************************
** Meta object code from reading C++ file 'selectemployerdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../selectemployerdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectemployerdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_selectemployerDialog_t {
    QByteArrayData data[9];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_selectemployerDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_selectemployerDialog_t qt_meta_stringdata_selectemployerDialog = {
    {
QT_MOC_LITERAL(0, 0, 20), // "selectemployerDialog"
QT_MOC_LITERAL(1, 21, 15), // "onReturnPressed"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 8), // "linetext"
QT_MOC_LITERAL(4, 47, 21), // "settingTableunChanged"
QT_MOC_LITERAL(5, 69, 3), // "row"
QT_MOC_LITERAL(6, 73, 3), // "col"
QT_MOC_LITERAL(7, 77, 27), // "on_pushButtoncancel_clicked"
QT_MOC_LITERAL(8, 105, 19) // "settingTableChanged"

    },
    "selectemployerDialog\0onReturnPressed\0"
    "\0linetext\0settingTableunChanged\0row\0"
    "col\0on_pushButtoncancel_clicked\0"
    "settingTableChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_selectemployerDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    2,   37,    2, 0x0a /* Public */,
       7,    0,   42,    2, 0x08 /* Private */,
       8,    2,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,

       0        // eod
};

void selectemployerDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        selectemployerDialog *_t = static_cast<selectemployerDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onReturnPressed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->settingTableunChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->on_pushButtoncancel_clicked(); break;
        case 3: _t->settingTableChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject selectemployerDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_selectemployerDialog.data,
      qt_meta_data_selectemployerDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *selectemployerDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *selectemployerDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_selectemployerDialog.stringdata0))
        return static_cast<void*>(const_cast< selectemployerDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int selectemployerDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
