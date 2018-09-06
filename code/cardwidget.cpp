#include "cardwidget.h"
#include <QDebug>
#include <QMouseEvent>
#include <QPropertyAnimation>

cardWidget::cardWidget(QWidget *parent) : QWidget(parent)
{
    verDesktop=new VerDesktop(this);
    ver=verDesktop->getVerDesktop();
}
void cardWidget::setGeometryAndLabel()
{
    this->hide();
    int x=(cardNum/4)*100;//通过寻图算法找到相应的扑克面
    int y=(cardNum%4)*150;
    cardLabel=new QLabel(this);
    cardLabel->clear();
    QPixmap MMM(":/res/image/cards.png");//提供大图的扑克Pixmap
    QPixmap cardpix=MMM.copy(x,y,100*ver,150*ver);
    cardLabel->setGeometry(0,0,100*ver,150*ver);
    cardLabel->setPixmap(cardpix.scaled(100*ver,150*ver));
    cardLabel->setScaledContents(true);
}
void cardWidget::getAnimationFinished()
{
    emit animationFinished(cardID);
}
void cardWidget::writeCardNum(int Num)
{
    this->cardNum=Num;
}
int cardWidget::readCardNum()
{
    return cardNum;
}
void cardWidget::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    isup=!isup;
    emit mousePressSend(cardID);
    qDebug()<<cardID;
    qDebug()<<cardNum;
}
void cardWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}
void cardWidget::setAnimation()//提供了一个动画实现了发牌的动态展现
{
    this->show();
    QPropertyAnimation *animation0=new QPropertyAnimation(this,"geometry");
    QPropertyAnimation *animation1=new QPropertyAnimation(this->cardLabel,"geometry");
    animation0->setDuration(300);
    animation1->setDuration(300);
    animation0->setStartValue(QRect(350*ver,0,50*ver,75*ver));
    animation0->setEndValue(QRect(cardID*40*ver,120*ver,100*ver,150*ver));
    animation1->setStartValue(QRect(0,0,50*ver,75*ver));
    animation1->setEndValue(QRect(0,0,100*ver,150*ver));
    animation1->start(QAbstractAnimation::DeleteWhenStopped);
    animation0->start(QAbstractAnimation::DeleteWhenStopped);
    connect(animation0,SIGNAL(finished()),this,SLOT(getAnimationFinished()));
    connect(animation1,SIGNAL(finished()),this,SLOT(getAnimationFinished()));
}
void cardWidget::setNoAnimation()
{
    this->show();
    this->setGeometry(cardID*40*ver,120*ver,100*ver,150*ver);
}
