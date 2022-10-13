#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include <QObject>
#include <QTimer>
#include <QThread>
#include <QQuickWindow>

typedef struct{
    int x;
    int y;
}ST_POINT;

typedef struct{
    QVector<ST_POINT>   line;
}ST_LINE;

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
    Q_ENUMS(TOOL_NUM);

    //Outlet Functions
    Q_INVOKABLE QVector<int> getLineX(int index);
    Q_INVOKABLE QVector<int> getLineY(int index);

    Q_INVOKABLE void startLine();
    Q_INVOKABLE void setLine(int x, int y);
    Q_INVOKABLE void stopLine();

//    Logger *logger;
//    DBHandler  *dbHandler;
    QVector<ST_LINE>    canvas;
    ST_LINE   temp_line;
public slots:
    void onTimer();

private:
    QTimer *timer;
    QQuickWindow *mMain;
};

#endif // SUPERVISOR_H
