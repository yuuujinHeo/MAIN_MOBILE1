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
    QByteArrayData data[105];
    char stringdata0[1114];
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
QT_MOC_LITERAL(3, 20, 7), // "setTray"
QT_MOC_LITERAL(4, 28, 5), // "tray1"
QT_MOC_LITERAL(5, 34, 5), // "tray2"
QT_MOC_LITERAL(6, 40, 5), // "tray3"
QT_MOC_LITERAL(7, 46, 6), // "moveTo"
QT_MOC_LITERAL(8, 53, 10), // "target_num"
QT_MOC_LITERAL(9, 64, 1), // "x"
QT_MOC_LITERAL(10, 66, 1), // "y"
QT_MOC_LITERAL(11, 68, 2), // "th"
QT_MOC_LITERAL(12, 71, 9), // "movePause"
QT_MOC_LITERAL(13, 81, 10), // "moveResume"
QT_MOC_LITERAL(14, 92, 7), // "moveJog"
QT_MOC_LITERAL(15, 100, 2), // "vx"
QT_MOC_LITERAL(16, 103, 2), // "vy"
QT_MOC_LITERAL(17, 106, 3), // "vth"
QT_MOC_LITERAL(18, 110, 8), // "moveStop"
QT_MOC_LITERAL(19, 119, 10), // "moveManual"
QT_MOC_LITERAL(20, 130, 11), // "setVelocity"
QT_MOC_LITERAL(21, 142, 3), // "vel"
QT_MOC_LITERAL(22, 146, 5), // "velth"
QT_MOC_LITERAL(23, 152, 10), // "getBattery"
QT_MOC_LITERAL(24, 163, 8), // "getState"
QT_MOC_LITERAL(25, 172, 10), // "getErrcode"
QT_MOC_LITERAL(26, 183, 9), // "getcurLoc"
QT_MOC_LITERAL(27, 193, 12), // "getcurTarget"
QT_MOC_LITERAL(28, 206, 14), // "QVector<float>"
QT_MOC_LITERAL(29, 221, 16), // "getImageChunkNum"
QT_MOC_LITERAL(30, 238, 12), // "getImageSize"
QT_MOC_LITERAL(31, 251, 12), // "getImageData"
QT_MOC_LITERAL(32, 264, 22), // "QVector<unsigned char>"
QT_MOC_LITERAL(33, 287, 3), // "num"
QT_MOC_LITERAL(34, 291, 11), // "getMapState"
QT_MOC_LITERAL(35, 303, 10), // "getMapname"
QT_MOC_LITERAL(36, 314, 11), // "getMapWidth"
QT_MOC_LITERAL(37, 326, 12), // "getMapHeight"
QT_MOC_LITERAL(38, 339, 12), // "getGridWidth"
QT_MOC_LITERAL(39, 352, 9), // "getOrigin"
QT_MOC_LITERAL(40, 362, 12), // "QVector<int>"
QT_MOC_LITERAL(41, 375, 14), // "getLocationNum"
QT_MOC_LITERAL(42, 390, 16), // "getLocationTypes"
QT_MOC_LITERAL(43, 407, 12), // "getLocationx"
QT_MOC_LITERAL(44, 420, 12), // "getLocationy"
QT_MOC_LITERAL(45, 433, 13), // "getLocationth"
QT_MOC_LITERAL(46, 447, 9), // "getRobotx"
QT_MOC_LITERAL(47, 457, 9), // "getRoboty"
QT_MOC_LITERAL(48, 467, 10), // "getRobotth"
QT_MOC_LITERAL(49, 478, 10), // "getPathNum"
QT_MOC_LITERAL(50, 489, 8), // "getPathx"
QT_MOC_LITERAL(51, 498, 8), // "getPathy"
QT_MOC_LITERAL(52, 507, 9), // "getPathth"
QT_MOC_LITERAL(53, 517, 13), // "getCanvasSize"
QT_MOC_LITERAL(54, 531, 11), // "getRedoSize"
QT_MOC_LITERAL(55, 543, 8), // "getLineX"
QT_MOC_LITERAL(56, 552, 5), // "index"
QT_MOC_LITERAL(57, 558, 8), // "getLineY"
QT_MOC_LITERAL(58, 567, 12), // "getLineColor"
QT_MOC_LITERAL(59, 580, 12), // "getLineWidth"
QT_MOC_LITERAL(60, 593, 9), // "startLine"
QT_MOC_LITERAL(61, 603, 5), // "color"
QT_MOC_LITERAL(62, 609, 5), // "width"
QT_MOC_LITERAL(63, 615, 7), // "setLine"
QT_MOC_LITERAL(64, 623, 8), // "stopLine"
QT_MOC_LITERAL(65, 632, 4), // "undo"
QT_MOC_LITERAL(66, 637, 4), // "redo"
QT_MOC_LITERAL(67, 642, 9), // "clear_all"
QT_MOC_LITERAL(68, 652, 9), // "getMapURL"
QT_MOC_LITERAL(69, 662, 9), // "setMapURL"
QT_MOC_LITERAL(70, 672, 3), // "url"
QT_MOC_LITERAL(71, 676, 10), // "getDBvalue"
QT_MOC_LITERAL(72, 687, 4), // "name"
QT_MOC_LITERAL(73, 692, 8), // "TOOL_NUM"
QT_MOC_LITERAL(74, 701, 10), // "TOOL_MOUSE"
QT_MOC_LITERAL(75, 712, 10), // "TOOL_BRUSH"
QT_MOC_LITERAL(76, 723, 11), // "TOOL_ERASER"
QT_MOC_LITERAL(77, 735, 6), // "UI_CMD"
QT_MOC_LITERAL(78, 742, 11), // "UI_CMD_NONE"
QT_MOC_LITERAL(79, 754, 17), // "UI_CMD_MOVE_TABLE"
QT_MOC_LITERAL(80, 772, 12), // "UI_CMD_PAUSE"
QT_MOC_LITERAL(81, 785, 13), // "UI_CMD_RESUME"
QT_MOC_LITERAL(82, 799, 16), // "UI_CMD_MOVE_WAIT"
QT_MOC_LITERAL(83, 816, 18), // "UI_CMD_MOVE_CHARGE"
QT_MOC_LITERAL(84, 835, 21), // "UI_CMD_PICKUP_CONFIRM"
QT_MOC_LITERAL(85, 857, 8), // "UI_STATE"
QT_MOC_LITERAL(86, 866, 13), // "UI_STATE_NONE"
QT_MOC_LITERAL(87, 880, 14), // "UI_STATE_READY"
QT_MOC_LITERAL(88, 895, 15), // "UI_STATE_MOVING"
QT_MOC_LITERAL(89, 911, 15), // "UI_STATE_PAUSED"
QT_MOC_LITERAL(90, 927, 15), // "UI_STATE_PICKUP"
QT_MOC_LITERAL(91, 943, 15), // "UI_STATE_CHARGE"
QT_MOC_LITERAL(92, 959, 13), // "LOCATION_TYPE"
QT_MOC_LITERAL(93, 973, 8), // "LOC_WAIT"
QT_MOC_LITERAL(94, 982, 10), // "LOC_CHARGE"
QT_MOC_LITERAL(95, 993, 11), // "LOC_TABLE_1"
QT_MOC_LITERAL(96, 1005, 11), // "LOC_TABLE_2"
QT_MOC_LITERAL(97, 1017, 11), // "LOC_TABLE_3"
QT_MOC_LITERAL(98, 1029, 11), // "LOC_TABLE_4"
QT_MOC_LITERAL(99, 1041, 11), // "LOC_TABLE_5"
QT_MOC_LITERAL(100, 1053, 11), // "LOC_TABLE_6"
QT_MOC_LITERAL(101, 1065, 11), // "LOC_TABLE_7"
QT_MOC_LITERAL(102, 1077, 11), // "LOC_TABLE_8"
QT_MOC_LITERAL(103, 1089, 11), // "LOC_TABLE_9"
QT_MOC_LITERAL(104, 1101, 12) // "LOC_TABLE_10"

    },
    "Supervisor\0onTimer\0\0setTray\0tray1\0"
    "tray2\0tray3\0moveTo\0target_num\0x\0y\0th\0"
    "movePause\0moveResume\0moveJog\0vx\0vy\0"
    "vth\0moveStop\0moveManual\0setVelocity\0"
    "vel\0velth\0getBattery\0getState\0getErrcode\0"
    "getcurLoc\0getcurTarget\0QVector<float>\0"
    "getImageChunkNum\0getImageSize\0"
    "getImageData\0QVector<unsigned char>\0"
    "num\0getMapState\0getMapname\0getMapWidth\0"
    "getMapHeight\0getGridWidth\0getOrigin\0"
    "QVector<int>\0getLocationNum\0"
    "getLocationTypes\0getLocationx\0"
    "getLocationy\0getLocationth\0getRobotx\0"
    "getRoboty\0getRobotth\0getPathNum\0"
    "getPathx\0getPathy\0getPathth\0getCanvasSize\0"
    "getRedoSize\0getLineX\0index\0getLineY\0"
    "getLineColor\0getLineWidth\0startLine\0"
    "color\0width\0setLine\0stopLine\0undo\0"
    "redo\0clear_all\0getMapURL\0setMapURL\0"
    "url\0getDBvalue\0name\0TOOL_NUM\0TOOL_MOUSE\0"
    "TOOL_BRUSH\0TOOL_ERASER\0UI_CMD\0UI_CMD_NONE\0"
    "UI_CMD_MOVE_TABLE\0UI_CMD_PAUSE\0"
    "UI_CMD_RESUME\0UI_CMD_MOVE_WAIT\0"
    "UI_CMD_MOVE_CHARGE\0UI_CMD_PICKUP_CONFIRM\0"
    "UI_STATE\0UI_STATE_NONE\0UI_STATE_READY\0"
    "UI_STATE_MOVING\0UI_STATE_PAUSED\0"
    "UI_STATE_PICKUP\0UI_STATE_CHARGE\0"
    "LOCATION_TYPE\0LOC_WAIT\0LOC_CHARGE\0"
    "LOC_TABLE_1\0LOC_TABLE_2\0LOC_TABLE_3\0"
    "LOC_TABLE_4\0LOC_TABLE_5\0LOC_TABLE_6\0"
    "LOC_TABLE_7\0LOC_TABLE_8\0LOC_TABLE_9\0"
    "LOC_TABLE_10"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Supervisor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      51,   14, // methods
       0,    0, // properties
       4,  366, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  269,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       3,    3,  270,    2, 0x02 /* Public */,
       7,    1,  277,    2, 0x02 /* Public */,
       7,    3,  280,    2, 0x02 /* Public */,
      12,    0,  287,    2, 0x02 /* Public */,
      13,    0,  288,    2, 0x02 /* Public */,
      14,    3,  289,    2, 0x02 /* Public */,
      18,    0,  296,    2, 0x02 /* Public */,
      19,    0,  297,    2, 0x02 /* Public */,
      20,    2,  298,    2, 0x02 /* Public */,
      23,    0,  303,    2, 0x02 /* Public */,
      24,    0,  304,    2, 0x02 /* Public */,
      25,    0,  305,    2, 0x02 /* Public */,
      26,    0,  306,    2, 0x02 /* Public */,
      27,    0,  307,    2, 0x02 /* Public */,
      29,    0,  308,    2, 0x02 /* Public */,
      30,    0,  309,    2, 0x02 /* Public */,
      31,    1,  310,    2, 0x02 /* Public */,
      34,    0,  313,    2, 0x02 /* Public */,
      35,    0,  314,    2, 0x02 /* Public */,
      36,    0,  315,    2, 0x02 /* Public */,
      37,    0,  316,    2, 0x02 /* Public */,
      38,    0,  317,    2, 0x02 /* Public */,
      39,    0,  318,    2, 0x02 /* Public */,
      41,    0,  319,    2, 0x02 /* Public */,
      42,    0,  320,    2, 0x02 /* Public */,
      43,    0,  321,    2, 0x02 /* Public */,
      44,    0,  322,    2, 0x02 /* Public */,
      45,    0,  323,    2, 0x02 /* Public */,
      46,    0,  324,    2, 0x02 /* Public */,
      47,    0,  325,    2, 0x02 /* Public */,
      48,    0,  326,    2, 0x02 /* Public */,
      49,    0,  327,    2, 0x02 /* Public */,
      50,    0,  328,    2, 0x02 /* Public */,
      51,    0,  329,    2, 0x02 /* Public */,
      52,    0,  330,    2, 0x02 /* Public */,
      53,    0,  331,    2, 0x02 /* Public */,
      54,    0,  332,    2, 0x02 /* Public */,
      55,    1,  333,    2, 0x02 /* Public */,
      57,    1,  336,    2, 0x02 /* Public */,
      58,    1,  339,    2, 0x02 /* Public */,
      59,    1,  342,    2, 0x02 /* Public */,
      60,    2,  345,    2, 0x02 /* Public */,
      63,    2,  350,    2, 0x02 /* Public */,
      64,    0,  355,    2, 0x02 /* Public */,
      65,    0,  356,    2, 0x02 /* Public */,
      66,    0,  357,    2, 0x02 /* Public */,
      67,    0,  358,    2, 0x02 /* Public */,
      68,    0,  359,    2, 0x02 /* Public */,
      69,    1,  360,    2, 0x02 /* Public */,
      71,    1,  363,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,    9,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,   15,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   21,   22,
    QMetaType::Float,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    0x80000000 | 28,
    QMetaType::Int,
    QMetaType::UInt,
    0x80000000 | 32, QMetaType::Int,   33,
    QMetaType::Bool,
    QMetaType::QString,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Float,
    0x80000000 | 40,
    QMetaType::Int,
    0x80000000 | 40,
    0x80000000 | 28,
    0x80000000 | 28,
    0x80000000 | 28,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Int,
    0x80000000 | 28,
    0x80000000 | 28,
    0x80000000 | 28,
    QMetaType::Int,
    QMetaType::Int,
    0x80000000 | 40, QMetaType::Int,   56,
    0x80000000 | 40, QMetaType::Int,   56,
    QMetaType::QString, QMetaType::Int,   56,
    QMetaType::Double, QMetaType::Int,   56,
    QMetaType::Void, QMetaType::QString, QMetaType::Double,   61,   62,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   70,
    QMetaType::QString, QMetaType::QString,   72,

 // enums: name, alias, flags, count, data
      73,   73, 0x0,    3,  386,
      77,   77, 0x0,    7,  392,
      85,   85, 0x0,    6,  406,
      92,   92, 0x0,   12,  418,

 // enum data: key, value
      74, uint(Supervisor::TOOL_MOUSE),
      75, uint(Supervisor::TOOL_BRUSH),
      76, uint(Supervisor::TOOL_ERASER),
      78, uint(Supervisor::UI_CMD_NONE),
      79, uint(Supervisor::UI_CMD_MOVE_TABLE),
      80, uint(Supervisor::UI_CMD_PAUSE),
      81, uint(Supervisor::UI_CMD_RESUME),
      82, uint(Supervisor::UI_CMD_MOVE_WAIT),
      83, uint(Supervisor::UI_CMD_MOVE_CHARGE),
      84, uint(Supervisor::UI_CMD_PICKUP_CONFIRM),
      86, uint(Supervisor::UI_STATE_NONE),
      87, uint(Supervisor::UI_STATE_READY),
      88, uint(Supervisor::UI_STATE_MOVING),
      89, uint(Supervisor::UI_STATE_PAUSED),
      90, uint(Supervisor::UI_STATE_PICKUP),
      91, uint(Supervisor::UI_STATE_CHARGE),
      93, uint(Supervisor::LOC_WAIT),
      94, uint(Supervisor::LOC_CHARGE),
      95, uint(Supervisor::LOC_TABLE_1),
      96, uint(Supervisor::LOC_TABLE_2),
      97, uint(Supervisor::LOC_TABLE_3),
      98, uint(Supervisor::LOC_TABLE_4),
      99, uint(Supervisor::LOC_TABLE_5),
     100, uint(Supervisor::LOC_TABLE_6),
     101, uint(Supervisor::LOC_TABLE_7),
     102, uint(Supervisor::LOC_TABLE_8),
     103, uint(Supervisor::LOC_TABLE_9),
     104, uint(Supervisor::LOC_TABLE_10),

       0        // eod
};

void Supervisor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Supervisor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onTimer(); break;
        case 1: _t->setTray((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->moveTo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->moveTo((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 4: _t->movePause(); break;
        case 5: _t->moveResume(); break;
        case 6: _t->moveJog((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 7: _t->moveStop(); break;
        case 8: _t->moveManual(); break;
        case 9: _t->setVelocity((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 10: { float _r = _t->getBattery();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 11: { int _r = _t->getState();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: { int _r = _t->getErrcode();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 13: { int _r = _t->getcurLoc();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 14: { QVector<float> _r = _t->getcurTarget();
            if (_a[0]) *reinterpret_cast< QVector<float>*>(_a[0]) = std::move(_r); }  break;
        case 15: { int _r = _t->getImageChunkNum();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 16: { uint _r = _t->getImageSize();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 17: { QVector<unsigned char> _r = _t->getImageData((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVector<unsigned char>*>(_a[0]) = std::move(_r); }  break;
        case 18: { bool _r = _t->getMapState();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 19: { QString _r = _t->getMapname();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 20: { int _r = _t->getMapWidth();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 21: { int _r = _t->getMapHeight();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 22: { float _r = _t->getGridWidth();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 23: { QVector<int> _r = _t->getOrigin();
            if (_a[0]) *reinterpret_cast< QVector<int>*>(_a[0]) = std::move(_r); }  break;
        case 24: { int _r = _t->getLocationNum();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 25: { QVector<int> _r = _t->getLocationTypes();
            if (_a[0]) *reinterpret_cast< QVector<int>*>(_a[0]) = std::move(_r); }  break;
        case 26: { QVector<float> _r = _t->getLocationx();
            if (_a[0]) *reinterpret_cast< QVector<float>*>(_a[0]) = std::move(_r); }  break;
        case 27: { QVector<float> _r = _t->getLocationy();
            if (_a[0]) *reinterpret_cast< QVector<float>*>(_a[0]) = std::move(_r); }  break;
        case 28: { QVector<float> _r = _t->getLocationth();
            if (_a[0]) *reinterpret_cast< QVector<float>*>(_a[0]) = std::move(_r); }  break;
        case 29: { float _r = _t->getRobotx();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 30: { float _r = _t->getRoboty();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 31: { float _r = _t->getRobotth();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 32: { int _r = _t->getPathNum();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 33: { QVector<float> _r = _t->getPathx();
            if (_a[0]) *reinterpret_cast< QVector<float>*>(_a[0]) = std::move(_r); }  break;
        case 34: { QVector<float> _r = _t->getPathy();
            if (_a[0]) *reinterpret_cast< QVector<float>*>(_a[0]) = std::move(_r); }  break;
        case 35: { QVector<float> _r = _t->getPathth();
            if (_a[0]) *reinterpret_cast< QVector<float>*>(_a[0]) = std::move(_r); }  break;
        case 36: { int _r = _t->getCanvasSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 37: { int _r = _t->getRedoSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 38: { QVector<int> _r = _t->getLineX((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVector<int>*>(_a[0]) = std::move(_r); }  break;
        case 39: { QVector<int> _r = _t->getLineY((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVector<int>*>(_a[0]) = std::move(_r); }  break;
        case 40: { QString _r = _t->getLineColor((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 41: { double _r = _t->getLineWidth((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 42: _t->startLine((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 43: _t->setLine((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 44: _t->stopLine(); break;
        case 45: _t->undo(); break;
        case 46: _t->redo(); break;
        case 47: _t->clear_all(); break;
        case 48: { QString _r = _t->getMapURL();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 49: _t->setMapURL((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 50: { QString _r = _t->getDBvalue((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
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
        if (_id < 51)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 51;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 51)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 51;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
