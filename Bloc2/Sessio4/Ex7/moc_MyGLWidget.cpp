/****************************************************************************
** Meta object code from reading C++ file 'MyGLWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MyGLWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyGLWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyGLWidget_t {
    QByteArrayData data[19];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyGLWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyGLWidget_t qt_meta_stringdata_MyGLWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MyGLWidget"
QT_MOC_LITERAL(1, 11, 11), // "enviaAngleX"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "angle"
QT_MOC_LITERAL(4, 30, 11), // "enviaAngleY"
QT_MOC_LITERAL(5, 42, 12), // "repAngleZoom"
QT_MOC_LITERAL(6, 55, 12), // "repModelPatr"
QT_MOC_LITERAL(7, 68, 6), // "select"
QT_MOC_LITERAL(8, 75, 12), // "repModelLego"
QT_MOC_LITERAL(9, 88, 14), // "repCameraPersp"
QT_MOC_LITERAL(10, 103, 12), // "repCameraOrt"
QT_MOC_LITERAL(11, 116, 9), // "repAngleX"
QT_MOC_LITERAL(12, 126, 9), // "repAngleY"
QT_MOC_LITERAL(13, 136, 9), // "repColorR"
QT_MOC_LITERAL(14, 146, 5), // "value"
QT_MOC_LITERAL(15, 152, 9), // "repColorG"
QT_MOC_LITERAL(16, 162, 9), // "repColorB"
QT_MOC_LITERAL(17, 172, 4), // "repW"
QT_MOC_LITERAL(18, 177, 4) // "repH"

    },
    "MyGLWidget\0enviaAngleX\0\0angle\0enviaAngleY\0"
    "repAngleZoom\0repModelPatr\0select\0"
    "repModelLego\0repCameraPersp\0repCameraOrt\0"
    "repAngleX\0repAngleY\0repColorR\0value\0"
    "repColorG\0repColorB\0repW\0repH"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGLWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   90,    2, 0x0a /* Public */,
       6,    1,   93,    2, 0x0a /* Public */,
       8,    1,   96,    2, 0x0a /* Public */,
       9,    1,   99,    2, 0x0a /* Public */,
      10,    1,  102,    2, 0x0a /* Public */,
      11,    1,  105,    2, 0x0a /* Public */,
      12,    1,  108,    2, 0x0a /* Public */,
      13,    1,  111,    2, 0x0a /* Public */,
      15,    1,  114,    2, 0x0a /* Public */,
      16,    1,  117,    2, 0x0a /* Public */,
      17,    1,  120,    2, 0x0a /* Public */,
      18,    1,  123,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,

       0        // eod
};

void MyGLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyGLWidget *_t = static_cast<MyGLWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->enviaAngleX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->enviaAngleY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->repAngleZoom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->repModelPatr((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->repModelLego((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->repCameraPersp((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->repCameraOrt((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->repAngleX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->repAngleY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->repColorR((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->repColorG((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->repColorB((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->repW((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->repH((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyGLWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGLWidget::enviaAngleX)) {
                *result = 0;
            }
        }
        {
            typedef void (MyGLWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGLWidget::enviaAngleY)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MyGLWidget::staticMetaObject = {
    { &QOpenGLWidget::staticMetaObject, qt_meta_stringdata_MyGLWidget.data,
      qt_meta_data_MyGLWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyGLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyGLWidget.stringdata0))
        return static_cast<void*>(const_cast< MyGLWidget*>(this));
    if (!strcmp(_clname, "QOpenGLFunctions_3_3_Core"))
        return static_cast< QOpenGLFunctions_3_3_Core*>(const_cast< MyGLWidget*>(this));
    return QOpenGLWidget::qt_metacast(_clname);
}

int MyGLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MyGLWidget::enviaAngleX(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyGLWidget::enviaAngleY(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
