/****************************************************************************
** Meta object code from reading C++ file 'chatwindows.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../chatwindows.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatwindows.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ChatWindows_t {
    QByteArrayData data[15];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChatWindows_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChatWindows_t qt_meta_stringdata_ChatWindows = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ChatWindows"
QT_MOC_LITERAL(1, 12, 24), // "on_pushButton_send_click"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 19), // "on_btn_mini_clicked"
QT_MOC_LITERAL(4, 58, 20), // "on_btn_close_clicked"
QT_MOC_LITERAL(5, 79, 15), // "mousePressEvent"
QT_MOC_LITERAL(6, 95, 12), // "QMouseEvent*"
QT_MOC_LITERAL(7, 108, 1), // "e"
QT_MOC_LITERAL(8, 110, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(9, 125, 22), // "on_ToolButton8_clicked"
QT_MOC_LITERAL(10, 148, 6), // "add_bq"
QT_MOC_LITERAL(11, 155, 4), // "qstr"
QT_MOC_LITERAL(12, 160, 22), // "on_ToolButton9_clicked"
QT_MOC_LITERAL(13, 183, 16), // "show_and_sendjpg"
QT_MOC_LITERAL(14, 200, 22) // "on_ToolButton7_clicked"

    },
    "ChatWindows\0on_pushButton_send_click\0"
    "\0on_btn_mini_clicked\0on_btn_close_clicked\0"
    "mousePressEvent\0QMouseEvent*\0e\0"
    "mouseMoveEvent\0on_ToolButton8_clicked\0"
    "add_bq\0qstr\0on_ToolButton9_clicked\0"
    "show_and_sendjpg\0on_ToolButton7_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatWindows[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x09 /* Protected */,
       3,    0,   65,    2, 0x09 /* Protected */,
       4,    0,   66,    2, 0x09 /* Protected */,
       5,    1,   67,    2, 0x09 /* Protected */,
       8,    1,   70,    2, 0x09 /* Protected */,
       9,    0,   73,    2, 0x09 /* Protected */,
      10,    1,   74,    2, 0x09 /* Protected */,
      12,    0,   77,    2, 0x09 /* Protected */,
      13,    1,   78,    2, 0x09 /* Protected */,
      14,    0,   81,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,

       0        // eod
};

void ChatWindows::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChatWindows *_t = static_cast<ChatWindows *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_send_click(); break;
        case 1: _t->on_btn_mini_clicked(); break;
        case 2: _t->on_btn_close_clicked(); break;
        case 3: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 5: _t->on_ToolButton8_clicked(); break;
        case 6: _t->add_bq((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->on_ToolButton9_clicked(); break;
        case 8: _t->show_and_sendjpg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->on_ToolButton7_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ChatWindows::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ChatWindows.data,
      qt_meta_data_ChatWindows,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ChatWindows::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatWindows::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ChatWindows.stringdata0))
        return static_cast<void*>(const_cast< ChatWindows*>(this));
    return QWidget::qt_metacast(_clname);
}

int ChatWindows::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
