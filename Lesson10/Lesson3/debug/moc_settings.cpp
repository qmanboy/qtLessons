/****************************************************************************
** Meta object code from reading C++ file 'settings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../settings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Settings_t {
    QByteArrayData data[21];
    char stringdata0[246];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Settings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Settings_t qt_meta_stringdata_Settings = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Settings"
QT_MOC_LITERAL(1, 9, 10), // "addHotKeys"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 17), // "QVector<QString>&"
QT_MOC_LITERAL(4, 39, 4), // "keys"
QT_MOC_LITERAL(5, 44, 8), // "sendLang"
QT_MOC_LITERAL(6, 53, 8), // "language"
QT_MOC_LITERAL(7, 62, 11), // "newSendLang"
QT_MOC_LITERAL(8, 74, 18), // "updateHostKeysView"
QT_MOC_LITERAL(9, 93, 16), // "QVector<HotKey>*"
QT_MOC_LITERAL(10, 110, 17), // "updatedKeysVector"
QT_MOC_LITERAL(11, 128, 10), // "darkScheme"
QT_MOC_LITERAL(12, 139, 11), // "lightScheme"
QT_MOC_LITERAL(13, 151, 15), // "on_click_accept"
QT_MOC_LITERAL(14, 167, 8), // "set_lang"
QT_MOC_LITERAL(15, 176, 4), // "lang"
QT_MOC_LITERAL(16, 181, 12), // "fill_hotkeys"
QT_MOC_LITERAL(17, 194, 5), // "Hkeys"
QT_MOC_LITERAL(18, 200, 15), // "set_dark_scheme"
QT_MOC_LITERAL(19, 216, 16), // "set_light_scheme"
QT_MOC_LITERAL(20, 233, 12) // "disable_lang"

    },
    "Settings\0addHotKeys\0\0QVector<QString>&\0"
    "keys\0sendLang\0language\0newSendLang\0"
    "updateHostKeysView\0QVector<HotKey>*\0"
    "updatedKeysVector\0darkScheme\0lightScheme\0"
    "on_click_accept\0set_lang\0lang\0"
    "fill_hotkeys\0Hkeys\0set_dark_scheme\0"
    "set_light_scheme\0disable_lang"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Settings[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       5,    1,   77,    2, 0x06 /* Public */,
       7,    0,   80,    2, 0x06 /* Public */,
       8,    1,   81,    2, 0x06 /* Public */,
      11,    0,   84,    2, 0x06 /* Public */,
      12,    0,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   86,    2, 0x08 /* Private */,
      14,    1,   87,    2, 0x0a /* Public */,
      16,    1,   90,    2, 0x0a /* Public */,
      18,    0,   93,    2, 0x0a /* Public */,
      19,    0,   94,    2, 0x0a /* Public */,
      20,    0,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, 0x80000000 | 9,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Settings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Settings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addHotKeys((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        case 1: _t->sendLang((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->newSendLang(); break;
        case 3: _t->updateHostKeysView((*reinterpret_cast< QVector<HotKey>*(*)>(_a[1]))); break;
        case 4: _t->darkScheme(); break;
        case 5: _t->lightScheme(); break;
        case 6: _t->on_click_accept(); break;
        case 7: _t->set_lang((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->fill_hotkeys((*reinterpret_cast< QVector<HotKey>*(*)>(_a[1]))); break;
        case 9: _t->set_dark_scheme(); break;
        case 10: _t->set_light_scheme(); break;
        case 11: _t->disable_lang(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Settings::*)(QVector<QString> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::addHotKeys)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Settings::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::sendLang)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Settings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::newSendLang)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Settings::*)(QVector<HotKey> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::updateHostKeysView)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Settings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::darkScheme)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Settings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::lightScheme)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Settings::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Settings.data,
    qt_meta_data_Settings,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Settings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Settings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Settings.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Settings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Settings::addHotKeys(QVector<QString> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Settings::sendLang(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Settings::newSendLang()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Settings::updateHostKeysView(QVector<HotKey> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Settings::darkScheme()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Settings::lightScheme()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
