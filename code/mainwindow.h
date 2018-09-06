#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <qmath.h>
#include "basewidget.h"
#include "verdesktop.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    float ver;
    VerDesktop *verDesktop;//调整分辨率问题
    void setNoFrameWidgetAndManySeting();//实现窗口的大小，无边框，阴影等等。
    const BaseWidget *baseWidget;
    void setBaseWidgetOnMainWindow();//将BaseWidget定义在MainWIndow上。
    void paintEvent(QPaintEvent *event);
};

#endif // MAINWINDOW_H
