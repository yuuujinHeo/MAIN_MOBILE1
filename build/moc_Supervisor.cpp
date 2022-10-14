/****************************************************************************
** Meta object code from reading C++ file 'Supervisor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Supervisor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Supervisor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Supervisor_t {
    QByteArrayData data[21];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Supervisor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Supervisor_t qt_meta_stringdata_Supervisor = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Supervisor"
QT_MOC_LITERAL(1, 11, 7), // "onTimer"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 13), // "getCanvasSize"
QT_MOC_LITERAL(4, 34, 8), // "getLineX"
QT_MOC_LITERAL(5, 43, 12), // "QVector<int>"
QT_MOC_LITERAL(6, 56, 5), // "index"
QT_MOC_LITERAL(7, 62, 8), // "getLineY"
QT_MOC_LITERAL(8, 71, 12), // "getLineColor"
QT_MOC_LITERAL(9, 84, 12), // "getLineWidth"
QT_MOC_LITERAL(10, 97, 9), // "startLine"
QT_MOC_LITERAL(11, 107, 5), // "color"
QT_MOC_LITERAL(12, 113, 5), // "width"
QT_MOC_LITERAL(13, 119, 7), // "setLine"
QT_MOC_LITERAL(14, 127, 1), // "x"
QT_MOC_LITERAL(15, 129, 1), // "y"
QT_MOC_LITERAL(16, 131, 8), // "stopLine"
QT_MOC_LITERAL(17, 140, 8), // "TOOL_NUM"
QT_MOC_LITERAL(18, 149, 10), // "TOOL_MOUSE"
QT_MOC_LITERAL(19, 160, 10), // "TOOL_BRUSH"
QT_MOC_LITERAL(20, 171, 11) // "TOOL_ERASER"

    },
    "Supervisor\0onTimer\0\0getCanvasSize\0"
    "getLineX\0QVector<int>\0index\0getLineY\0"
    "getLineColor\0getLineWidth\0startLine\0"
    "color\0width\0setLine\0x\0y\0stopLine\0"
    "TOOL_NUM\0TOOL_MOUSE\0TOOL_BRUSH\0"
    "TOOL_ERASER"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Supervisor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       1,   84, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x02 /* Public */,
       4,    1,   61,    2, 0x02 /* Public */,
       7,    1,   64,    2, 0x02 /* Public */,
       8,    1,   67,    2, 0x02 /* Public */,
       9,    1,   70,    2, 0x02 /* Public */,
      10,    2,   73,    2, 0x02 /* Public */,
      13,    2,   78,    2, 0x02 /* Public */,
      16,    0,   83,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Int,
    0x80000000 | 5, QMetaType::Int,    6,
    0x80000000 | 5, QMetaType::Int,    6,
    QMetaType::QString, QMetaType::Int,    6,
    QMetaType::Double, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::Double,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   14,   15,
    QMetaType::Void,

 // enums: name, alias, flags, count, data
      17,   17, 0x0,    3,   89,

 // enum data: key, value
      18, uint(Supervisor::TOOL_MOUSE),
      19, uint(Supervisor::TOOL_BRUSH),
      20, uint(Supervisor::TOOL_ERASER),

       0        // eod
};

void Supervisor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Supervisor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onTimer(); break;
        case 1: { int _r = _t->getCanvasSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { QVector<int> _r = _t->getLineX((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVector<int>*>(_a[0]) = std::move(_r); }  break;
        case 3: { QVector<int> _r = _t->getLineY((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVector<int>*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->getLineColor((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { double _r = _t->getLineWidth((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->startLine((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 7: _t->setLine((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->stopLine(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Supervisor::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Supervisor.data,
    qt_meta_data_Supervisor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Supervisor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Supervisor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Supervisor.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Supervisor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
