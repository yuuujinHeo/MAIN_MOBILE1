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
    //Keep watching...
    setWindow(qobject_cast<QQuickWindow*>(object));
}
void Supervisor::onTimer(){
    static int tmr_cnt = 0;
    static int test_cnt = 0;
    static int flag = 0;
    if(tmr_cnt++ > 50){
        if(flag == 0){
            qDebug() << "HERE";
            flag = 1;
            QMetaObject::invokeMethod(mMain,"initdone");
//            QMetaObject::invokeMethod(mMain,"gotiniterror");
        }
    }
}

void Supervisor::setWindow(QQuickWindow *Window){
    mMain = Window;
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

void Supervisor::setLine(int x, int y){
    ST_POINT temp_point;
    temp_point.x = x;
    temp_point.y = y;
    temp_line.line.push_back(temp_point);
}

void Supervisor::startLine(){
    temp_line.line.clear();
}
void Supervisor::stopLine(){
    canvas.push_back(temp_line);

    for(int i=0; i<canvas.size(); i++){
        qDebug() << i << " th line =================";
        for(int j=0; j<canvas[i].line.size(); j++){
            cout << canvas[i].line[j].x;
        }
        cout << endl;
    }
}
