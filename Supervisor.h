#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include <QObject>
#include <QTimer>
#include <QThread>
#include <QQuickWindow>
#include "GlobalHeader.h"
#include "DBHandler.h"

typedef struct{
    int x;
    int y;
}ST_POINT;

typedef struct{
    QVector<ST_POINT>   line;
    QString     color;
    double      width;
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
