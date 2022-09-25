/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ColorTheme_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ColorTheme_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ColorTheme_t qt_meta_stringdata_ColorTheme = {
    {
QT_MOC_LITERAL(0, 0, 10) // "ColorTheme"

    },
    "ColorTheme"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ColorTheme[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ColorTheme::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ColorTheme::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ColorTheme.data,
    qt_meta_data_ColorTheme,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ColorTheme::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ColorTheme::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ColorTheme.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ColorTheme::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[61];
    char stringdata0[691];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 8), // "sendData"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "text"
QT_MOC_LITERAL(4, 26, 8), // "sendLang"
QT_MOC_LITERAL(5, 35, 4), // "lang"
QT_MOC_LITERAL(6, 40, 11), // "newSendLang"
QT_MOC_LITERAL(7, 52, 13), // "sendLangToSet"
QT_MOC_LITERAL(8, 66, 11), // "disableLang"
QT_MOC_LITERAL(9, 78, 11), // "sendHotKeys"
QT_MOC_LITERAL(10, 90, 16), // "QVector<HotKey>*"
QT_MOC_LITERAL(11, 107, 7), // "hotkeys"
QT_MOC_LITERAL(12, 115, 8), // "initLang"
QT_MOC_LITERAL(13, 124, 12), // "sendFilePath"
QT_MOC_LITERAL(14, 137, 4), // "path"
QT_MOC_LITERAL(15, 142, 19), // "sendFilePathToModel"
QT_MOC_LITERAL(16, 162, 10), // "updateLang"
QT_MOC_LITERAL(17, 173, 12), // "hotkeys_open"
QT_MOC_LITERAL(18, 186, 12), // "hotkeys_save"
QT_MOC_LITERAL(19, 199, 11), // "hotkeys_new"
QT_MOC_LITERAL(20, 211, 12), // "hotkeys_quit"
QT_MOC_LITERAL(21, 224, 13), // "hotkeys_print"
QT_MOC_LITERAL(22, 238, 8), // "setEmpty"
QT_MOC_LITERAL(23, 247, 5), // "empty"
QT_MOC_LITERAL(24, 253, 11), // "indexSignal"
QT_MOC_LITERAL(25, 265, 5), // "index"
QT_MOC_LITERAL(26, 271, 7), // "senData"
QT_MOC_LITERAL(27, 279, 3), // "dir"
QT_MOC_LITERAL(28, 283, 4), // "file"
QT_MOC_LITERAL(29, 288, 12), // "searchSignal"
QT_MOC_LITERAL(30, 301, 13), // "sendDirFilter"
QT_MOC_LITERAL(31, 315, 6), // "filter"
QT_MOC_LITERAL(32, 322, 11), // "create_menu"
QT_MOC_LITERAL(33, 334, 14), // "create_toolbar"
QT_MOC_LITERAL(34, 349, 9), // "font_slot"
QT_MOC_LITERAL(35, 359, 13), // "on_click_open"
QT_MOC_LITERAL(36, 373, 13), // "on_click_save"
QT_MOC_LITERAL(37, 387, 16), // "on_click_save_as"
QT_MOC_LITERAL(38, 404, 13), // "on_click_help"
QT_MOC_LITERAL(39, 418, 18), // "on_click_read_only"
QT_MOC_LITERAL(40, 437, 17), // "on_click_settings"
QT_MOC_LITERAL(41, 455, 10), // "print_slot"
QT_MOC_LITERAL(42, 466, 9), // "quit_slot"
QT_MOC_LITERAL(43, 476, 12), // "new_doc_slot"
QT_MOC_LITERAL(44, 489, 10), // "close_help"
QT_MOC_LITERAL(45, 500, 14), // "close_settings"
QT_MOC_LITERAL(46, 515, 8), // "set_lang"
QT_MOC_LITERAL(47, 524, 11), // "update_lang"
QT_MOC_LITERAL(48, 536, 19), // "set_filepath_to_tab"
QT_MOC_LITERAL(49, 556, 3), // "str"
QT_MOC_LITERAL(50, 560, 16), // "update_tabs_slot"
QT_MOC_LITERAL(51, 577, 22), // "set_cur_text_edit_slot"
QT_MOC_LITERAL(52, 600, 15), // "set_button_text"
QT_MOC_LITERAL(53, 616, 8), // "set_font"
QT_MOC_LITERAL(54, 625, 9), // "set_align"
QT_MOC_LITERAL(55, 635, 5), // "Align"
QT_MOC_LITERAL(56, 641, 5), // "align"
QT_MOC_LITERAL(57, 647, 14), // "custom_context"
QT_MOC_LITERAL(58, 662, 5), // "point"
QT_MOC_LITERAL(59, 668, 10), // "remove_tab"
QT_MOC_LITERAL(60, 679, 11) // "search_slot"

    },
    "MainWindow\0sendData\0\0text\0sendLang\0"
    "lang\0newSendLang\0sendLangToSet\0"
    "disableLang\0sendHotKeys\0QVector<HotKey>*\0"
    "hotkeys\0initLang\0sendFilePath\0path\0"
    "sendFilePathToModel\0updateLang\0"
    "hotkeys_open\0hotkeys_save\0hotkeys_new\0"
    "hotkeys_quit\0hotkeys_print\0setEmpty\0"
    "empty\0indexSignal\0index\0senData\0dir\0"
    "file\0searchSignal\0sendDirFilter\0filter\0"
    "create_menu\0create_toolbar\0font_slot\0"
    "on_click_open\0on_click_save\0"
    "on_click_save_as\0on_click_help\0"
    "on_click_read_only\0on_click_settings\0"
    "print_slot\0quit_slot\0new_doc_slot\0"
    "close_help\0close_settings\0set_lang\0"
    "update_lang\0set_filepath_to_tab\0str\0"
    "update_tabs_slot\0set_cur_text_edit_slot\0"
    "set_button_text\0set_font\0set_align\0"
    "Align\0align\0custom_context\0point\0"
    "remove_tab\0search_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      45,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      20,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  239,    2, 0x06 /* Public */,
       4,    1,  242,    2, 0x06 /* Public */,
       6,    0,  245,    2, 0x06 /* Public */,
       7,    1,  246,    2, 0x06 /* Public */,
       8,    0,  249,    2, 0x06 /* Public */,
       9,    1,  250,    2, 0x06 /* Public */,
      12,    1,  253,    2, 0x06 /* Public */,
      13,    1,  256,    2, 0x06 /* Public */,
      15,    1,  259,    2, 0x06 /* Public */,
      16,    0,  262,    2, 0x06 /* Public */,
      17,    0,  263,    2, 0x06 /* Public */,
      18,    0,  264,    2, 0x06 /* Public */,
      19,    0,  265,    2, 0x06 /* Public */,
      20,    0,  266,    2, 0x06 /* Public */,
      21,    0,  267,    2, 0x06 /* Public */,
      22,    1,  268,    2, 0x06 /* Public */,
      24,    1,  271,    2, 0x06 /* Public */,
      26,    2,  274,    2, 0x06 /* Public */,
      29,    0,  279,    2, 0x06 /* Public */,
      30,    1,  280,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      32,    0,  283,    2, 0x0a /* Public */,
      33,    0,  284,    2, 0x0a /* Public */,
      34,    0,  285,    2, 0x0a /* Public */,
      35,    0,  286,    2, 0x08 /* Private */,
      36,    0,  287,    2, 0x08 /* Private */,
      37,    0,  288,    2, 0x08 /* Private */,
      38,    0,  289,    2, 0x08 /* Private */,
      39,    0,  290,    2, 0x08 /* Private */,
      40,    0,  291,    2, 0x08 /* Private */,
      41,    0,  292,    2, 0x08 /* Private */,
      42,    0,  293,    2, 0x08 /* Private */,
      43,    0,  294,    2, 0x08 /* Private */,
      44,    0,  295,    2, 0x08 /* Private */,
      45,    0,  296,    2, 0x08 /* Private */,
      46,    1,  297,    2, 0x08 /* Private */,
      47,    1,  300,    2, 0x08 /* Private */,
      48,    1,  303,    2, 0x08 /* Private */,
      50,    0,  306,    2, 0x08 /* Private */,
      51,    1,  307,    2, 0x08 /* Private */,
      52,    1,  310,    2, 0x08 /* Private */,
      53,    0,  313,    2, 0x08 /* Private */,
      54,    1,  314,    2, 0x08 /* Private */,
      57,    1,  317,    2, 0x08 /* Private */,
      59,    1,  320,    2, 0x08 /* Private */,
      60,    0,  323,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   27,   28,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   31,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 55,   56,
    QMetaType::Void, QMetaType::QPoint,   58,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->sendLang((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->newSendLang(); break;
        case 3: _t->sendLangToSet((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->disableLang(); break;
        case 5: _t->sendHotKeys((*reinterpret_cast< QVector<HotKey>*(*)>(_a[1]))); break;
        case 6: _t->initLang((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->sendFilePath((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->sendFilePathToModel((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->updateLang(); break;
        case 10: _t->hotkeys_open(); break;
        case 11: _t->hotkeys_save(); break;
        case 12: _t->hotkeys_new(); break;
        case 13: _t->hotkeys_quit(); break;
        case 14: _t->hotkeys_print(); break;
        case 15: _t->setEmpty((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->indexSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->senData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 18: _t->searchSignal(); break;
        case 19: _t->sendDirFilter((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->create_menu(); break;
        case 21: _t->create_toolbar(); break;
        case 22: _t->font_slot(); break;
        case 23: _t->on_click_open(); break;
        case 24: _t->on_click_save(); break;
        case 25: _t->on_click_save_as(); break;
        case 26: _t->on_click_help(); break;
        case 27: _t->on_click_read_only(); break;
        case 28: _t->on_click_settings(); break;
        case 29: _t->print_slot(); break;
        case 30: _t->quit_slot(); break;
        case 31: _t->new_doc_slot(); break;
        case 32: _t->close_help(); break;
        case 33: _t->close_settings(); break;
        case 34: _t->set_lang((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 35: _t->update_lang((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 36: _t->set_filepath_to_tab((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 37: _t->update_tabs_slot(); break;
        case 38: _t->set_cur_text_edit_slot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->set_button_text((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 40: _t->set_font(); break;
        case 41: _t->set_align((*reinterpret_cast< Align(*)>(_a[1]))); break;
        case 42: _t->custom_context((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 43: _t->remove_tab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 44: _t->search_slot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QByteArray const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendLang)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::newSendLang)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendLangToSet)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::disableLang)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QVector<HotKey> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendHotKeys)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::initLang)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendFilePath)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendFilePathToModel)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::updateLang)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::hotkeys_open)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::hotkeys_save)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::hotkeys_new)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::hotkeys_quit)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::hotkeys_print)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::setEmpty)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::indexSignal)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::senData)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::searchSignal)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendDirFilter)) {
                *result = 19;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 45)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 45;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 45)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 45;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sendData(QByteArray const & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::sendLang(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::newSendLang()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::sendLangToSet(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::disableLang()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainWindow::sendHotKeys(QVector<HotKey> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::initLang(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::sendFilePath(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::sendFilePathToModel(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainWindow::updateLang()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void MainWindow::hotkeys_open()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void MainWindow::hotkeys_save()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void MainWindow::hotkeys_new()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void MainWindow::hotkeys_quit()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void MainWindow::hotkeys_print()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void MainWindow::setEmpty(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void MainWindow::indexSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void MainWindow::senData(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void MainWindow::searchSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}

// SIGNAL 19
void MainWindow::sendDirFilter(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
