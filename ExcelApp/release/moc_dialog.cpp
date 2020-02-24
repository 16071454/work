/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ExcelApp/dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Dialog_t {
    QByteArrayData data[18];
    char stringdata0[267];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_t qt_meta_stringdata_Dialog = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Dialog"
QT_MOC_LITERAL(1, 7, 19), // "signal_start_thread"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 4), // "path"
QT_MOC_LITERAL(4, 33, 15), // "signal_scan_end"
QT_MOC_LITERAL(5, 49, 3), // "str"
QT_MOC_LITERAL(6, 53, 17), // "signal_show_index"
QT_MOC_LITERAL(7, 71, 24), // "signal_clear_tablewidget"
QT_MOC_LITERAL(8, 96, 23), // "signal_only_insert_code"
QT_MOC_LITERAL(9, 120, 24), // "signal_change_label_text"
QT_MOC_LITERAL(10, 145, 15), // "slot_read_excel"
QT_MOC_LITERAL(11, 161, 13), // "onDibAcquired"
QT_MOC_LITERAL(12, 175, 6), // "pixmap"
QT_MOC_LITERAL(13, 182, 18), // "slot_reset_alldata"
QT_MOC_LITERAL(14, 201, 14), // "onSelectButton"
QT_MOC_LITERAL(15, 216, 9), // "onEndScan"
QT_MOC_LITERAL(16, 226, 24), // "slot_addcompare_excldata"
QT_MOC_LITERAL(17, 251, 15) // "slot_back_index"

    },
    "Dialog\0signal_start_thread\0\0path\0"
    "signal_scan_end\0str\0signal_show_index\0"
    "signal_clear_tablewidget\0"
    "signal_only_insert_code\0"
    "signal_change_label_text\0slot_read_excel\0"
    "onDibAcquired\0pixmap\0slot_reset_alldata\0"
    "onSelectButton\0onEndScan\0"
    "slot_addcompare_excldata\0slot_back_index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       6,    0,   85,    2, 0x06 /* Public */,
       7,    0,   86,    2, 0x06 /* Public */,
       8,    1,   87,    2, 0x06 /* Public */,
       9,    0,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   91,    2, 0x0a /* Public */,
      11,    1,   92,    2, 0x0a /* Public */,
      13,    0,   95,    2, 0x0a /* Public */,
      14,    0,   96,    2, 0x0a /* Public */,
      15,    0,   97,    2, 0x0a /* Public */,
      16,    1,   98,    2, 0x0a /* Public */,
      17,    0,  101,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QVariantList,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPixmap,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,

       0        // eod
};

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Dialog *_t = static_cast<Dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_start_thread((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->signal_scan_end((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 2: _t->signal_show_index(); break;
        case 3: _t->signal_clear_tablewidget(); break;
        case 4: _t->signal_only_insert_code((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->signal_change_label_text(); break;
        case 6: _t->slot_read_excel(); break;
        case 7: _t->onDibAcquired((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 8: _t->slot_reset_alldata(); break;
        case 9: _t->onSelectButton(); break;
        case 10: _t->onEndScan(); break;
        case 11: _t->slot_addcompare_excldata((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->slot_back_index(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Dialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Dialog::signal_start_thread)) {
                *result = 0;
            }
        }
        {
            typedef void (Dialog::*_t)(QVariantList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Dialog::signal_scan_end)) {
                *result = 1;
            }
        }
        {
            typedef void (Dialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Dialog::signal_show_index)) {
                *result = 2;
            }
        }
        {
            typedef void (Dialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Dialog::signal_clear_tablewidget)) {
                *result = 3;
            }
        }
        {
            typedef void (Dialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Dialog::signal_only_insert_code)) {
                *result = 4;
            }
        }
        {
            typedef void (Dialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Dialog::signal_change_label_text)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject Dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialog.data,
      qt_meta_data_Dialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog.stringdata0))
        return static_cast<void*>(const_cast< Dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Dialog::signal_start_thread(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Dialog::signal_scan_end(QVariantList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Dialog::signal_show_index()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Dialog::signal_clear_tablewidget()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void Dialog::signal_only_insert_code(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Dialog::signal_change_label_text()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
