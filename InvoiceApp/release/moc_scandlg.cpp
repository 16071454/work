/****************************************************************************
** Meta object code from reading C++ file 'scandlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../scandlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scandlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_scandlg_t {
    QByteArrayData data[23];
    char stringdata0[284];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_scandlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_scandlg_t qt_meta_stringdata_scandlg = {
    {
QT_MOC_LITERAL(0, 0, 7), // "scandlg"
QT_MOC_LITERAL(1, 8, 19), // "signal_start_thread"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "path"
QT_MOC_LITERAL(4, 34, 4), // "name"
QT_MOC_LITERAL(5, 39, 7), // "company"
QT_MOC_LITERAL(6, 47, 9), // "pingzheng"
QT_MOC_LITERAL(7, 57, 8), // "scantype"
QT_MOC_LITERAL(8, 66, 15), // "_identification"
QT_MOC_LITERAL(9, 82, 15), // "signal_scan_end"
QT_MOC_LITERAL(10, 98, 21), // "QMap<QString,QString>"
QT_MOC_LITERAL(11, 120, 3), // "str"
QT_MOC_LITERAL(12, 124, 23), // "siganl_set_invoice_type"
QT_MOC_LITERAL(13, 148, 11), // "INVOICETYPE"
QT_MOC_LITERAL(14, 160, 17), // "signal_back_index"
QT_MOC_LITERAL(15, 178, 17), // "signal_show_index"
QT_MOC_LITERAL(16, 196, 13), // "onDibAcquired"
QT_MOC_LITERAL(17, 210, 6), // "pixmap"
QT_MOC_LITERAL(18, 217, 14), // "onSelectButton"
QT_MOC_LITERAL(19, 232, 4), // "type"
QT_MOC_LITERAL(20, 237, 9), // "onEndScan"
QT_MOC_LITERAL(21, 247, 19), // "slot_upload_invoice"
QT_MOC_LITERAL(22, 267, 16) // "slot_product_pic"

    },
    "scandlg\0signal_start_thread\0\0path\0"
    "name\0company\0pingzheng\0scantype\0"
    "_identification\0signal_scan_end\0"
    "QMap<QString,QString>\0str\0"
    "siganl_set_invoice_type\0INVOICETYPE\0"
    "signal_back_index\0signal_show_index\0"
    "onDibAcquired\0pixmap\0onSelectButton\0"
    "type\0onEndScan\0slot_upload_invoice\0"
    "slot_product_pic"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_scandlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,   64,    2, 0x06 /* Public */,
       9,    1,   77,    2, 0x06 /* Public */,
      12,    1,   80,    2, 0x06 /* Public */,
      14,    0,   83,    2, 0x06 /* Public */,
      15,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    1,   85,    2, 0x0a /* Public */,
      18,    1,   88,    2, 0x0a /* Public */,
      20,    0,   91,    2, 0x0a /* Public */,
      21,    0,   92,    2, 0x0a /* Public */,
      22,    1,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QPixmap,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void scandlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        scandlg *_t = static_cast<scandlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_start_thread((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 1: _t->signal_scan_end((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1]))); break;
        case 2: _t->siganl_set_invoice_type((*reinterpret_cast< INVOICETYPE(*)>(_a[1]))); break;
        case 3: _t->signal_back_index(); break;
        case 4: _t->signal_show_index(); break;
        case 5: _t->onDibAcquired((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 6: _t->onSelectButton((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->onEndScan(); break;
        case 8: _t->slot_upload_invoice(); break;
        case 9: _t->slot_product_pic((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (scandlg::*_t)(QString , QString , QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&scandlg::signal_start_thread)) {
                *result = 0;
            }
        }
        {
            typedef void (scandlg::*_t)(QMap<QString,QString> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&scandlg::signal_scan_end)) {
                *result = 1;
            }
        }
        {
            typedef void (scandlg::*_t)(INVOICETYPE );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&scandlg::siganl_set_invoice_type)) {
                *result = 2;
            }
        }
        {
            typedef void (scandlg::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&scandlg::signal_back_index)) {
                *result = 3;
            }
        }
        {
            typedef void (scandlg::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&scandlg::signal_show_index)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject scandlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_scandlg.data,
      qt_meta_data_scandlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *scandlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *scandlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_scandlg.stringdata0))
        return static_cast<void*>(const_cast< scandlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int scandlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void scandlg::signal_start_thread(QString _t1, QString _t2, QString _t3, QString _t4, QString _t5, QString _t6)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void scandlg::signal_scan_end(QMap<QString,QString> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void scandlg::siganl_set_invoice_type(INVOICETYPE _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void scandlg::signal_back_index()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void scandlg::signal_show_index()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
