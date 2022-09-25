/****************************************************************************
** Meta object code from reading C++ file 'pathwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pathwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pathwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pathwidget_t {
    QByteArrayData data[14];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pathwidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pathwidget_t qt_meta_stringdata_pathwidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "pathwidget"
QT_MOC_LITERAL(1, 11, 8), // "openFile"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "path"
QT_MOC_LITERAL(4, 26, 14), // "modelRebuilded"
QT_MOC_LITERAL(5, 41, 3), // "str"
QT_MOC_LITERAL(6, 45, 13), // "rebuild_model"
QT_MOC_LITERAL(7, 59, 9), // "set_focus"
QT_MOC_LITERAL(8, 69, 14), // "set_dir_filter"
QT_MOC_LITERAL(9, 84, 7), // "chgDisk"
QT_MOC_LITERAL(10, 92, 5), // "index"
QT_MOC_LITERAL(11, 98, 17), // "on_double_clicked"
QT_MOC_LITERAL(12, 116, 11), // "QModelIndex"
QT_MOC_LITERAL(13, 128, 20) // "on_up_button_clicked"

    },
    "pathwidget\0openFile\0\0path\0modelRebuilded\0"
    "str\0rebuild_model\0set_focus\0set_dir_filter\0"
    "chgDisk\0index\0on_double_clicked\0"
    "QModelIndex\0on_up_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pathwidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   60,    2, 0x0a /* Public */,
       7,    1,   63,    2, 0x0a /* Public */,
       8,    1,   66,    2, 0x0a /* Public */,
       9,    1,   69,    2, 0x08 /* Private */,
      11,    1,   72,    2, 0x08 /* Private */,
      13,    0,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, 0x80000000 | 12,   10,
    QMetaType::Void,

       0        // eod
};

void pathwidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<pathwidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->modelRebuilded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->rebuild_model((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->set_focus((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->set_dir_filter((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->chgDisk((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_double_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_up_button_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (pathwidget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pathwidget::openFile)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (pathwidget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pathwidget::modelRebuilded)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject pathwidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_pathwidget.data,
    qt_meta_data_pathwidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *pathwidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pathwidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_pathwidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int pathwidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void pathwidget::openFile(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void pathwidget::modelRebuilded(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
