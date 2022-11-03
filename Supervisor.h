#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include <QObject>
#include <QTimer>
#include <QThread>
#include <QQuickWindow>
#include "GlobalHeader.h"
#include "DBHandler.h"
#include "LCMHandler.h"

class Supervisor : public QObject
{
    Q_OBJECT
public:
    explicit Supervisor(QObject *parent = nullptr);
    void setWindow(QQuickWindow *Window);
public:
    enum TOOL_NUM{
        TOOL_MOUSE = 0,
        TOOL_BRUSH,
        TOOL_ERASER
    };
    enum UI_CMD{
        UI_CMD_NONE = 0,
        UI_CMD_MOVE_TABLE,
        UI_CMD_PAUSE,
        UI_CMD_RESUME,
        UI_CMD_MOVE_WAIT,
        UI_CMD_MOVE_CHARGE,
        UI_CMD_PICKUP_CONFIRM
    };

    enum UI_STATE{
        UI_STATE_NONE = 0,
        UI_STATE_READY,
        UI_STATE_MOVING,
        UI_STATE_PAUSED,
        UI_STATE_PICKUP,
        UI_STATE_CHARGE
    };
    enum LOCATION_TYPE{
        LOC_WAIT = 1,
        LOC_CHARGE,
        LOC_TABLE_1,
        LOC_TABLE_2,
        LOC_TABLE_3,
        LOC_TABLE_4,
        LOC_TABLE_5,
        LOC_TABLE_6,
        LOC_TABLE_7,
        LOC_TABLE_8,
        LOC_TABLE_9,
        LOC_TABLE_10
    };

    Q_ENUMS(LOCATION_TYPE);
    Q_ENUMS(UI_STATE);
    Q_ENUMS(UI_CMD);
    Q_ENUMS(TOOL_NUM);


    //Scheduler
    int ui_cmd;
    int ui_state;

    //LCMHandler
    LCMHandler  lcm;
    bool isaccepted;

    //Mobile Move Functions
    Q_INVOKABLE void setTray(int tray1, int tray2, int tray3);
    Q_INVOKABLE void moveTo(int target_num);
    Q_INVOKABLE void moveTo(float x, float y, float th);
    Q_INVOKABLE void movePause();
    Q_INVOKABLE void moveResume();
    Q_INVOKABLE void moveJog(float vx, float vy, float vth);
    Q_INVOKABLE void moveStop();
    Q_INVOKABLE void moveManual();
    Q_INVOKABLE void setVelocity(float vel, float velth);

    Q_INVOKABLE float getBattery();
    Q_INVOKABLE int getState();
    Q_INVOKABLE int getErrcode();

    Q_INVOKABLE int getcurLoc();
    Q_INVOKABLE QVector<float> getcurTarget();

    Q_INVOKABLE int getImageChunkNum();
//    Q_INVOKABLE int getImageChunkSize();
    Q_INVOKABLE unsigned int getImageSize();
    Q_INVOKABLE QVector<unsigned char> getImageData(int num);

    Q_INVOKABLE bool getMapState();
    Q_INVOKABLE QString getMapname();
    Q_INVOKABLE int getMapWidth();
    Q_INVOKABLE int getMapHeight();
    Q_INVOKABLE float getGridWidth();
    Q_INVOKABLE QVector<int> getOrigin();
    Q_INVOKABLE int getLocationNum();
    Q_INVOKABLE QVector<int> getLocationTypes();
    Q_INVOKABLE QVector<float> getLocationx();
    Q_INVOKABLE QVector<float> getLocationy();
    Q_INVOKABLE QVector<float> getLocationth();

    Q_INVOKABLE float getRobotx();
    Q_INVOKABLE float getRoboty();
    Q_INVOKABLE float getRobotth();

    Q_INVOKABLE int getPathNum();
    Q_INVOKABLE QVector<float> getPathx();
    Q_INVOKABLE QVector<float> getPathy();
    Q_INVOKABLE QVector<float> getPathth();





    //Outlet Functions
    Q_INVOKABLE int getCanvasSize();
    Q_INVOKABLE int getRedoSize();
    Q_INVOKABLE QVector<int> getLineX(int index);
    Q_INVOKABLE QVector<int> getLineY(int index);
    Q_INVOKABLE QString getLineColor(int index);
    Q_INVOKABLE double getLineWidth(int index);

    Q_INVOKABLE void startLine(QString color, double width);
    Q_INVOKABLE void setLine(int x, int y);
    Q_INVOKABLE void stopLine();

    Q_INVOKABLE void undo();
    Q_INVOKABLE void redo();
    Q_INVOKABLE void clear_all();

    Q_INVOKABLE QString getMapURL();
    Q_INVOKABLE void setMapURL(QString url);

    Q_INVOKABLE QString getDBvalue(QString name);

    DBHandler  *dbHandler;
    QVector<ST_LINE>    canvas;
    QVector<ST_LINE>    canvas_redo;
    int flag_clear;
    ST_LINE   temp_line;


public slots:
    void onTimer();

private:
    QTimer *timer;
    QQuickWindow *mMain;
};

#endif // SUPERVISOR_H
