/****************************************************************************
** Meta object code from reading C++ file 'recv_image.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "recv_image.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recv_image.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_recv_image_t {
    QByteArrayData data[6];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_recv_image_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_recv_image_t qt_meta_stringdata_recv_image = {
    {
QT_MOC_LITERAL(0, 0, 10), // "recv_image"
QT_MOC_LITERAL(1, 11, 15), // "showTestPicture"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 9), // "saveImage"
QT_MOC_LITERAL(4, 38, 11), // "saveImageAS"
QT_MOC_LITERAL(5, 50, 9) // "emptyTemp"

    },
    "recv_image\0showTestPicture\0\0saveImage\0"
    "saveImageAS\0emptyTemp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_recv_image[] = {

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
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void recv_image::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        recv_image *_t = static_cast<recv_image *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showTestPicture(); break;
        case 1: _t->saveImage(); break;
        case 2: _t->saveImageAS(); break;
        case 3: _t->emptyTemp(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject recv_image::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_recv_image.data,
      qt_meta_data_recv_image,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *recv_image::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *recv_image::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_recv_image.stringdata0))
        return static_cast<void*>(const_cast< recv_image*>(this));
    return QDialog::qt_metacast(_clname);
}

int recv_image::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
