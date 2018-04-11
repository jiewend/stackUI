/****************************************************************************
** Meta object code from reading C++ file 'usermainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../usermainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usermainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UserMainWindow_t {
    QByteArrayData data[19];
    char stringdata0[273];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserMainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserMainWindow_t qt_meta_stringdata_UserMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "UserMainWindow"
QT_MOC_LITERAL(1, 15, 20), // "sendDatatoMainWindow"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 13), // "sendNewNodeID"
QT_MOC_LITERAL(4, 51, 27), // "send_recvmessage_to_handler"
QT_MOC_LITERAL(5, 79, 19), // "on_btn_mini_clicked"
QT_MOC_LITERAL(6, 99, 20), // "on_btn_close_clicked"
QT_MOC_LITERAL(7, 120, 15), // "mousePressEvent"
QT_MOC_LITERAL(8, 136, 12), // "QMouseEvent*"
QT_MOC_LITERAL(9, 149, 1), // "e"
QT_MOC_LITERAL(10, 151, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(11, 166, 17), // "AddNewNodeHandler"
QT_MOC_LITERAL(12, 184, 9), // "NewNodeID"
QT_MOC_LITERAL(13, 194, 15), // "ShowChatWindows"
QT_MOC_LITERAL(14, 210, 7), // "ChatWID"
QT_MOC_LITERAL(15, 218, 18), // "RecvMessageHandler"
QT_MOC_LITERAL(16, 237, 4), // "qstr"
QT_MOC_LITERAL(17, 242, 8), // "SourceID"
QT_MOC_LITERAL(18, 251, 21) // "on_Pushbutton_clicked"

    },
    "UserMainWindow\0sendDatatoMainWindow\0"
    "\0sendNewNodeID\0send_recvmessage_to_handler\0"
    "on_btn_mini_clicked\0on_btn_close_clicked\0"
    "mousePressEvent\0QMouseEvent*\0e\0"
    "mouseMoveEvent\0AddNewNodeHandler\0"
    "NewNodeID\0ShowChatWindows\0ChatWID\0"
    "RecvMessageHandler\0qstr\0SourceID\0"
    "on_Pushbutton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserMainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       3,    1,   72,    2, 0x06 /* Public */,
       4,    2,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   80,    2, 0x09 /* Protected */,
       6,    0,   81,    2, 0x09 /* Protected */,
       7,    1,   82,    2, 0x09 /* Protected */,
      10,    1,   85,    2, 0x09 /* Protected */,
      11,    1,   88,    2, 0x09 /* Protected */,
      13,    1,   91,    2, 0x09 /* Protected */,
      15,    2,   94,    2, 0x09 /* Protected */,
      18,    0,   99,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   16,   17,
    QMetaType::Void,

       0        // eod
};

void UserMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserMainWindow *_t = static_cast<UserMainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendDatatoMainWindow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sendNewNodeID((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->send_recvmessage_to_handler((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->on_btn_mini_clicked(); break;
        case 4: _t->on_btn_close_clicked(); break;
        case 5: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->AddNewNodeHandler((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->ShowChatWindows((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->RecvMessageHandler((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->on_Pushbutton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UserMainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserMainWindow::sendDatatoMainWindow)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (UserMainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserMainWindow::sendNewNodeID)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (UserMainWindow::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserMainWindow::send_recvmessage_to_handler)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject UserMainWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_UserMainWindow.data,
      qt_meta_data_UserMainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UserMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UserMainWindow.stringdata0))
        return static_cast<void*>(const_cast< UserMainWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int UserMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void UserMainWindow::sendDatatoMainWindow(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UserMainWindow::sendNewNodeID(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UserMainWindow::send_recvmessage_to_handler(QString _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
