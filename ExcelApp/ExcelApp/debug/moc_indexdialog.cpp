/****************************************************************************
** Meta object code from reading C++ file 'indexdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../indexdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'indexdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IndexDialog_t {
    QByteArrayData data[8];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IndexDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IndexDialog_t qt_meta_stringdata_IndexDialog = {
    {
QT_MOC_LITERAL(0, 0, 11), // "IndexDialog"
QT_MOC_LITERAL(1, 12, 19), // "signal_show_scanlog"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 22), // "slot_clear_tablewidget"
QT_MOC_LITERAL(4, 56, 14), // "slot_setSumpic"
QT_MOC_LITERAL(5, 71, 7), // "strlist"
QT_MOC_LITERAL(6, 79, 22), // "slot_only_insert_table"
QT_MOC_LITERAL(7, 102, 4) // "code"

    },
    "IndexDialog\0signal_show_scanlog\0\0"
    "slot_clear_tablewidget\0slot_setSumpic\0"
    "strlist\0slot_only_insert_table\0code"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IndexDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   35,    2, 0x0a /* Public */,
       4,    1,   36,    2, 0x0a /* Public */,
       6,    1,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantList,    5,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void IndexDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IndexDialog *_t = static_cast<IndexDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_show_scanlog(); break;
        case 1: _t->slot_clear_tablewidget(); break;
        case 2: _t->slot_setSumpic((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 3: _t->slot_only_insert_table((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IndexDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IndexDialog::signal_show_scanlog)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject IndexDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_IndexDialog.data,
      qt_meta_data_IndexDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IndexDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IndexDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IndexDialog.stringdata0))
        return static_cast<void*>(const_cast< IndexDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int IndexDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void IndexDialog::signal_show_scanlog()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
