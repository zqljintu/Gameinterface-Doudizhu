#include "mainwindow.h"
#include<QTime>
#include <random>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    verDesktop=new VerDesktop(this);
    ver=verDesktop->getVerDesktop();
    setNoFrameWidgetAndManySeting();
    setBaseWidgetOnMainWindow();
}

MainWindow::~MainWindow()
{

}
void MainWindow::setNoFrameWidgetAndManySeting()
{
    this->setMaximumSize(1310*ver,910*ver);
    this->setMinimumSize(1310*ver,910*ver);
    this->setWindowFlags(Qt::FramelessWindowHint|windowFlags());
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    const int x=5*ver;
    Q_UNUSED(event);
    QPainterPath yinying_path;
    yinying_path.setFillRule(Qt::WindingFill);
    yinying_path.addRect(x,x,this->width()-2*x,this->height()-2*x);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    QColor color(0,0,0,15);
    for(int i=0;i<x;i++)
    {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRect(x-i, x-i, this->width()-(x-i)*2, this->height()-(x-i)*2);
        color.setAlpha(150 - qSqrt(i)*50);
        painter.setPen(color);
        painter.drawPath(path);
    }
}
void MainWindow::setBaseWidgetOnMainWindow()
{
    baseWidget=new BaseWidget(this);
}




















