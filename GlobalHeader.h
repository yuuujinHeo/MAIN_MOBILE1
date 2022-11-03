#ifndef GLOBALHEADER_H
#define GLOBALHEADER_H

#include "Logger.h"
extern Logger *plog;

typedef struct{
    int x;
    int y;
}ST_POINT;

typedef struct{
    QVector<ST_POINT>   line;
    QString     color;
    double      width;
}ST_LINE;



#define NUM_TRAY 3
typedef struct{
    float x;
    float y;
    float th;
}ST_POSE;
typedef struct{
    int chunkSize;
    int imageSize;
    QVector<QVector<unsigned char>> data;

    QString map_name;
    int width;
    int height;
    float gridwidth;
    int origin[2];
    int locationSize;
    QVector<int> locationTypes;
    QVector<ST_POSE> locationsPose;
}ST_MAP;

typedef struct{
    //from Robot
    float battery;
    int state;
    int err_code;
    ST_POSE curPose;
    int curLocation;
    ST_POSE curTarget;
    int pathSize;
    QVector<ST_POSE> curPath;

    //mine
    int tray_num[NUM_TRAY];
    ST_POSE targetPose;
}ST_ROBOT;

enum ROBOT_CMD{
    ROBOT_CMD_NONE = 0,
    ROBOT_CMD_MOVE_LOCATION,
    ROBOT_CMD_MOVE_TARGET,
    ROBOT_CMD_MOVE_JOG,
    ROBOT_CMD_MOVE_MANUAL,
    ROBOT_CMD_MOVE_PAUSE,
    ROBOT_CMD_MOVE_STOP,
    ROBOT_CMD_SET_VELOCITY
};


enum ROBOT_STATE{
    ROBOT_STATE_NONE = 0,
    ROBOT_STATE_READY,
    ROBOT_STATE_MOVING,
    ROBOT_STATE_AVOID,
    ROBOT_STATE_PAUSED
};

#endif // GLOBALHEADER_H
