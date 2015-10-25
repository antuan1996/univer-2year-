/****************************************************************************
** Meta object code from reading C++ file 'setter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../graf/setter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_setter_t {
    QByteArrayData data[10];
    char stringdata[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_setter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_setter_t qt_meta_stringdata_setter = {
    {
QT_MOC_LITERAL(0, 0, 6), // "setter"
QT_MOC_LITERAL(1, 7, 12), // "data_changed"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 7), // "sendfid"
QT_MOC_LITERAL(4, 29, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(5, 53, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 75, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(7, 107, 5), // "index"
QT_MOC_LITERAL(8, 113, 22), // "on_radioButton_toggled"
QT_MOC_LITERAL(9, 136, 7) // "checked"

    },
    "setter\0data_changed\0\0sendfid\0"
    "on_pushButton_2_clicked\0on_pushButton_clicked\0"
    "on_comboBox_currentIndexChanged\0index\0"
    "on_radioButton_toggled\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_setter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   44,    2, 0x06 /* Public */,
       3,    1,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   54,    2, 0x08 /* Private */,
       5,    0,   55,    2, 0x08 /* Private */,
       6,    1,   56,    2, 0x08 /* Private */,
       8,    1,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor, QMetaType::QColor, QMetaType::Bool,    2,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Bool,    9,

       0        // eod
};

void setter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        setter *_t = static_cast<setter *>(_o);
        switch (_id) {
        case 0: _t->data_changed((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->sendfid((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_radioButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (setter::*_t)(QColor , QColor , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&setter::data_changed)) {
                *result = 0;
            }
        }
        {
            typedef void (setter::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&setter::sendfid)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject setter::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_setter.data,
      qt_meta_data_setter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *setter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *setter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_setter.stringdata))
        return static_cast<void*>(const_cast< setter*>(this));
    return QWidget::qt_metacast(_clname);
}

int setter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void setter::data_changed(QColor _t1, QColor _t2, bool _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void setter::sendfid(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
