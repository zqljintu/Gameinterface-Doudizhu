#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QWidget>
#include <verdesktop.h>
#include <QPainter>
#include <QLabel>
#include <QTime>
#include<QPushButton>
#include"cardsbasewidget.h"
#include "mythreadrandomnum.h"

class BaseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BaseWidget(QWidget *parent = 0);
    void writeLeftCardSize(int size);//写入
    void writeRightCardSize(int size);//写入
    void showChuOrBuyaoButton();//显示出牌或者不出

private:
    float ver;
    VerDesktop *verDesktop;
    CardsBaseWidget *cardBaseWidget;
    void setCardBaseWidgetOnBaseWidget();//将cardbasewidget定义在BaseWidget
    void setBaseWidgetSizeAndBackground();//设定BaseWidget的界面大小
    void changeBaseBackgroundPicture();//改变默认背景图片
    void setNormalBaseBackgroundPicture();//设定默认的背景图片
    void paintEvent(QPaintEvent *event);//绘制背景图片
    QLabel *dizhuLabel;//地主
    QLabel *nongmin0Label;//农民1
    QLabel *nongmin1Label;//农民2
    QLabel *cardsAllLabel;//总牌数
    QLabel *rightCardAllLabel;//左方牌
    QLabel *leftCardAllLabel;//右方牌
    QWidget *rightCardSizeWidget;//左方牌数
    QWidget *leftCardSizeWidget;//右方牌数
    QLabel *rightCardSizeLabel;
    QLabel *leftCardSizeLabel;
    QPushButton *openGameButton;//开始游戏
    QPushButton *getDizhuButton;//抢地主
    QPushButton *abandonDizhuButton;//不抢地主
    QPushButton *chupaiButton;//出牌
    QPushButton *buyaoButton;//不要
    void setPersonPixmapLabel();//设定角色图片
    QList<int> numbersList;
    void getRandomCardNumList();//获取随机值
    QList<int> userNumCardList;//用户的牌数与号
    QList<int> nongmin0NumCardList;//农民0的牌数与号
    QList<int> nongmin1NumCardList;//农民的牌数与号
    void setUserRandomCardNumList();//为用户分配随机值
    void sortUserRandomCardNumList();//排序用户的牌
signals:

public slots:
    void getHideCardsss();//关闭label--cardsss
    void openGameButtonSlot();//开始游戏的slot
    void getDizhuButtonSlot();//抢地主的slot
    void abandonDizhuButtonSlot();//不抢的slot
    void chupaiButtonSlot();//出牌的slot
    void buyaoButtonSlot();//不要的slot
};

#endif // BASEWIDGET_H
