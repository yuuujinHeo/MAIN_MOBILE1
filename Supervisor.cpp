#include "Supervisor.h"
#include <QQmlApplicationEngine>
#include <QKeyEvent>
#include <iostream>
#include <QTextCodec>
#include <QSslSocket>

extern QObject *object;

extern QObject *object;
using namespace std;
Supervisor::Supervisor(QObject *parent)
    : QObject(parent)
{
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(onTimer()));
    timer->start(200);
    canvas.clear();
    flag_clear = 0;
    //Keep watching...
    setWindow(qobject_cast<QQuickWindow*>(object));

    dbHandler = new DBHandler();
}

void Supervisor::setWindow(QQuickWindow *Window){
    mMain = Window;
}

int Supervisor::getCanvasSize(){
    return canvas.size();
}
int Supervisor::getRedoSize(){
    qDebug() <<canvas_redo.size();
    return canvas_redo.size();
}
QVector<int> Supervisor::getLineX(int index){
    QVector<int>    temp_x;
    for(int i=0; i<canvas[index].line.size(); i++){
        temp_x.push_back(canvas[index].line[i].x);
    }
    return temp_x;
}
QVector<int> Supervisor::getLineY(int index){
    QVector<int>    temp_y;
    for(int i=0; i<canvas[index].line.size(); i++){
        temp_y.push_back(canvas[index].line[i].y);
    }
    return temp_y;
}

QString Supervisor::getLineColor(int index){
    if(index < canvas.size()){
        return canvas[index].color;
    }
    return "";
}

double Supervisor::getLineWidth(int index){
    if(index < canvas.size()){
        return canvas[index].width;
    }
    return 0;
}


void Supervisor::setLine(int x, int y){
    ST_POINT temp_point;
    temp_point.x = x;
    temp_point.y = y;
    temp_line.line.push_back(temp_point);

}

void Supervisor::startLine(QString color, double width){
    temp_line.line.clear();
    temp_line.color = color;
    temp_line.width = width;

    qDebug() << "startLine : " << color << width;
}
void Supervisor::stopLine(){
    canvas.push_back(temp_line);
    canvas_redo.clear();
}

void Supervisor::undo(){
    ST_LINE temp;
    if(canvas.size() > 0){
        temp = canvas.back();
        canvas.pop_back();
        canvas_redo.push_back(temp);

        qDebug() << "UNDO [canvas size = "<<canvas.size() << "] redo size = " << canvas_redo.size();
    }
}

void Supervisor::redo(){
    if(canvas_redo.size() > 0){
        if(flag_clear == 1){
            flag_clear = 0;
            if(canvas.size() > 0){

            }else{
                canvas = canvas_redo;
                canvas_redo.clear();
            }
        }else{
            canvas.push_back(canvas_redo.back());
            canvas_redo.pop_back();
        }
        qDebug() << "REDO [canvas size = "<<canvas.size() << "] redo size = " << canvas_redo.size();
    }
}

QString Supervisor::getMapURL(){
    return dbHandler->DBbase["map_url"];
}

void Supervisor::setMapURL(QString url){
    dbHandler->editDataBase("map_url",url);
}

QString Supervisor::getDBvalue(QString name){
    return dbHandler->DBbase[name];
}

void Supervisor::clear_all(){
    canvas_redo.clear();
    for(int i=0; i<canvas.size(); i++){
        canvas_redo.push_back(canvas[i]);
        flag_clear = 1;
    }
    canvas.clear();
    qDebug() << "CLEAR [canvas size = "<<canvas.size() << "] redo size = " << canvas_redo.size();

}




////////////////////////////////////////////////////////////////////////////////////////
void Supervisor::onTimer(){
    static int tmr_cnt = 0;
    static int test_cnt = 0;
    static int flag = 0;
    if(tmr_cnt++ > 50){
        if(flag == 0){
//            qDebug() << "HERE";
//            flag = 1;
//            QMetaObject::invokeMethod(mMain,"initdone");
//            QMetaObject::invokeMethod(mMain,"gotiniterror");
        }
    }

    switch(ui_cmd){
    case UI_CMD_MOVE_TABLE:{
        if(lcm.robot.state == ROBOT_STATE_READY){
            if(isaccepted){
                // pickup
                qDebug() << "do pickup";
                ui_state = UI_STATE_PICKUP;
                isaccepted = false;
            }else{
                // move start
                if(lcm.robot.tray_num[0] != 0){
                    lcm.moveTo(LOC_CHARGE + lcm.robot.tray_num[0]);
                }else if(lcm.robot.tray_num[1] != 0){
                    lcm.moveTo(LOC_CHARGE + lcm.robot.tray_num[1]);
                }else if(lcm.robot.tray_num[2] != 0){
                    lcm.moveTo(LOC_CHARGE + lcm.robot.tray_num[2]);
                }else{
                    // move done -> move to wait
                    ui_cmd = UI_CMD_MOVE_WAIT;
                }
            }
        }else if(lcm.robot.state == ROBOT_STATE_MOVING){
            // moving
            if(isaccepted){

            }else{
                qDebug() << "robot moving start";
                isaccepted = true;
                ui_state = UI_STATE_MOVING;
                QMetaObject::invokeMethod(mMain,"initdone");
//                QMetaObject::invokeMethod(mMain, "movelocation");
            }
        }
        break;
    }
    case UI_CMD_MOVE_WAIT:{
        if(lcm.robot.state == ROBOT_STATE_READY){
            if(isaccepted){
                // move done
                ui_cmd = UI_CMD_NONE;
                ui_state = UI_STATE_READY;
                isaccepted = false;
            }else{
                lcm.moveTo(LOC_WAIT);
            }
        }else if(lcm.robot.state == ROBOT_STATE_MOVING){
            // moving
            isaccepted = true;
            ui_state = UI_STATE_MOVING;
        }
        break;
    }
    case UI_CMD_MOVE_CHARGE:{
        if(lcm.robot.state == ROBOT_STATE_READY){
            if(isaccepted){
                // move done
                ui_cmd = UI_CMD_NONE;
                ui_state = UI_STATE_CHARGE;
                isaccepted = false;
            }else{
                lcm.moveTo(LOC_CHARGE);
            }
        }else if(lcm.robot.state == ROBOT_STATE_MOVING){
            // moving
            isaccepted = true;
            ui_state = UI_STATE_MOVING;
        }
        break;
    }
    case UI_CMD_PAUSE:{
        if(lcm.robot.state == ROBOT_STATE_MOVING || lcm.robot.state == ROBOT_STATE_AVOID){
            lcm.movePause();
        }else if(lcm.robot.state == ROBOT_STATE_PAUSED){
            // pause success
            ui_cmd = UI_CMD_NONE;
        }
        break;
    }
    case UI_CMD_RESUME:{
        if(lcm.robot.state == ROBOT_STATE_PAUSED){
            lcm.moveResume();
        }else{
            // resume success
            ui_cmd = UI_CMD_NONE;
        }
        break;
    }
    case UI_CMD_PICKUP_CONFIRM:{
        int curNum = 0;
        for(int i=0; i<NUM_TRAY; i++){
            if(lcm.robot.tray_num[i] == curNum){
                lcm.robot.tray_num[i] = 0;
            }else if(curNum == 0){
                curNum = lcm.robot.tray_num[i];
                lcm.robot.tray_num[i] = 0;
            }
        }
        ui_cmd = UI_CMD_MOVE_TABLE;
        break;
    }
    default:{

    }
    }
}


void Supervisor::setTray(int tray1, int tray2, int tray3){
    plog->write("[UI-FUNCTION] SET TRAY : "+QString().sprintf("%d, %d, %d",tray1,tray2,tray3));
    lcm.robot.tray_num[0] = tray1;
    lcm.robot.tray_num[1] = tray2;
    lcm.robot.tray_num[2] = tray3;
    ui_cmd = UI_CMD_MOVE_TABLE;
}

void Supervisor::moveTo(int target_num){
    lcm.moveTo(target_num);
}
void Supervisor::moveTo(float x, float y, float th){
    lcm.moveTo(x,y,th);
}
void Supervisor::movePause(){
    lcm.movePause();
}
void Supervisor::moveResume(){
    lcm.moveResume();
}
void Supervisor::moveJog(float vx, float vy, float vth){
    lcm.moveJog(vx,vy,vth);
}
void Supervisor::moveStop(){
    lcm.moveStop();
}
void Supervisor::moveManual(){
    lcm.moveManual();
}
void Supervisor::setVelocity(float vel, float velth){
    lcm.setVelocity(vel,velth);
}

float Supervisor::getBattery(){
    return lcm.robot.battery;
}
int Supervisor::getState(){
    return lcm.robot.state;
}
int Supervisor::getErrcode(){
    return lcm.robot.err_code;
}

int Supervisor::getcurLoc(){
    return lcm.robot.curLocation;
}

QVector<float> Supervisor::getcurTarget(){
    QVector<float> temp;
    temp.push_back(lcm.robot.curTarget.x);
    temp.push_back(lcm.robot.curTarget.y);
    temp.push_back(lcm.robot.curTarget.th);
    return temp;
}
int Supervisor::getImageChunkNum(){
    return lcm.map.chunkSize;
}
unsigned int Supervisor::getImageSize(){
    return lcm.map.imageSize;
}
QVector<unsigned char> Supervisor::getImageData(int num){
    return lcm.map.data[num];
}

bool Supervisor::getMapState(){
    return lcm.isdownloadMap;
}
QString Supervisor::getMapname(){
    return lcm.map.map_name;
}
int Supervisor::getMapWidth(){
    return lcm.map.width;
}
int Supervisor::getMapHeight(){
    return lcm.map.height;
}
float Supervisor::getGridWidth(){
    return lcm.map.gridwidth;
}
QVector<int> Supervisor::getOrigin(){
    QVector<int> temp;
    temp.push_back(lcm.map.origin[0]);
    temp.push_back(lcm.map.origin[1]);
    return temp;
}
int Supervisor::getLocationNum(){
    return lcm.map.locationSize;
}
QVector<int> Supervisor::getLocationTypes(){
    return lcm.map.locationTypes;
}
QVector<float> Supervisor::getLocationx(){
    QVector<float> temp;
    for(int i=0; i<lcm.map.locationSize; i++){
        temp.push_back(lcm.map.locationsPose[i].x);
    }
    return temp;
}
QVector<float> Supervisor::getLocationy(){
    QVector<float> temp;
    for(int i=0; i<lcm.map.locationSize; i++){
        temp.push_back(lcm.map.locationsPose[i].y);
    }
    return temp;
}
QVector<float> Supervisor::getLocationth(){
    QVector<float> temp;
    for(int i=0; i<lcm.map.locationSize; i++){
        temp.push_back(lcm.map.locationsPose[i].th);
    }
    return temp;
}

float Supervisor::getRobotx(){
    return lcm.robot.curPose.x;
}
float Supervisor::getRoboty(){
    return lcm.robot.curPose.y;
}
float Supervisor::getRobotth(){
    return lcm.robot.curPose.th;
}

int Supervisor::getPathNum(){
    return lcm.robot.pathSize;
}
QVector<float> Supervisor::getPathx(){
    QVector<float> temp;
    for(int i=0; i<lcm.robot.pathSize; i++){
        temp.push_back(lcm.robot.curPath[i].x);
    }
    return temp;
}
QVector<float> Supervisor::getPathy(){
    QVector<float> temp;
    for(int i=0; i<lcm.robot.pathSize; i++){
        temp.push_back(lcm.robot.curPath[i].y);
    }
    return temp;
}
QVector<float> Supervisor::getPathth(){
    QVector<float> temp;
    for(int i=0; i<lcm.robot.pathSize; i++){
        temp.push_back(lcm.robot.curPath[i].th);
    }
    return temp;
}
