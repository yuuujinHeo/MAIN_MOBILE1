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
