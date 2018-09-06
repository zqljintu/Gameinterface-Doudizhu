#include "basewidget.h"
#include <QPropertyAnimation>

BaseWidget::BaseWidget(QWidget *parent) : QWidget(parent)
{
    verDesktop=new VerDesktop(this);
    ver=verDesktop->getVerDesktop();
    setBaseWidgetSizeAndBackground();
    setCardBaseWidgetOnBaseWidget();
    setPersonPixmapLabel();
    connect(cardBaseWidget,SIGNAL(hideCardssssLabel()),this,SLOT(getHideCardsss()));
    connect(openGameButton,SIGNAL(clicked(bool)),this,SLOT(openGameButtonSlot()));
    connect(getDizhuButton,SIGNAL(clicked(bool)),this,SLOT(getDizhuButtonSlot()));
    connect(abandonDizhuButton,SIGNAL(clicked(bool)),SLOT(abandonDizhuButtonSlot()));
    connect(chupaiButton,SIGNAL(clicked(bool)),this,SLOT(chupaiButtonSlot()));
    connect(buyaoButton,SIGNAL(clicked(bool)),this,SLOT(buyaoButtonSlot()));
}
void BaseWidget::setBaseWidgetSizeAndBackground()
{
    this->setGeometry(5*ver,5*ver,1300*ver,900*ver);
    this->setMinimumSize(1300*ver,900*ver);
    this->setMaximumSize(1300*ver,900*ver);
}
void BaseWidget::changeBaseBackgroundPicture()
{
}
void BaseWidget::setNormalBaseBackgroundPicture()
{
}
void BaseWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPixmap background0;
    background0.load(":/res/image/basebackground0.png");
    background0.scaled(1300*ver,900*ver);
    QPainter painter(this);
    painter.save();
    painter.drawPixmap(0,0,1300*ver,900*ver,background0);
    painter.restore();
}
void BaseWidget::setPersonPixmapLabel()
{
    dizhuLabel=new QLabel(this);
    nongmin0Label=new QLabel(this);
    nongmin1Label=new QLabel(this);
    cardsAllLabel=new QLabel(this);
    openGameButton=new QPushButton(this);
    rightCardAllLabel=new QLabel(this);
    leftCardAllLabel=new QLabel(this);
    leftCardSizeWidget=new QWidget(this);
    leftCardSizeLabel=new QLabel(leftCardSizeWidget);
    rightCardSizeWidget=new QWidget(this);
    rightCardSizeLabel=new QLabel(rightCardSizeWidget);
    getDizhuButton=new QPushButton(this);
    abandonDizhuButton=new QPushButton(this);
    chupaiButton=new QPushButton(this);
    buyaoButton=new QPushButton(this);
    QPixmap nongmin0Pix(":/res/image/nongmin0.png");
    nongmin0Label->setGeometry(0,280*ver,155*ver,210*ver);
    nongmin0Label->setPixmap(nongmin0Pix.scaled(155*ver,210*ver));
    QPixmap nongmin1Pix(":/res/image/nongmin1.png");
    nongmin1Label->setGeometry(1148*ver,280*ver,155*ver,210*ver);
    nongmin1Label->setPixmap(nongmin1Pix.scaled(155*ver,210*ver));
    QPixmap dizhuPix(":/res/image/dizhu.png");
    dizhuLabel->setGeometry(10*ver,603*ver,170*ver,240*ver);
    dizhuLabel->setPixmap(dizhuPix);
    QPixmap cardsssPix(":/res/image/cardsss.png");
    cardsAllLabel->setGeometry(550*ver,370*ver,150*ver,150*ver);
    cardsAllLabel->setPixmap(cardsssPix.scaled(150*ver,150*ver));
    cardsAllLabel->setScaledContents(true);
    QPixmap rightCardsssPix(":/res/image/rightcardsss.png");
    rightCardAllLabel->setPixmap(rightCardsssPix.scaled(150*ver,110*ver));
    rightCardAllLabel->setGeometry(155*ver,370*ver,150*ver,110*ver);
    rightCardAllLabel->hide();
    QPixmap leftCardssPix(":/res/image/leftcardsss.png");
    leftCardAllLabel->setPixmap(leftCardssPix.scaled(150*ver,110*ver));
    leftCardAllLabel->setGeometry(1005*ver,370*ver,150*ver,110*ver);
    leftCardAllLabel->hide();
    cardsAllLabel->hide();
    openGameButton->setGeometry(550*ver,370*ver,100*ver,50*ver);
    openGameButton->setText(tr("开始游戏"));
    rightCardSizeWidget->setGeometry(240*ver,275*ver,50*ver,50*ver);
    rightCardSizeLabel->setGeometry(0,0,50*ver,50*ver);
    rightCardSizeLabel->setText(tr("左部牌数"));
    leftCardSizeWidget->setGeometry(1012*ver,275*ver,50*ver,50*ver);
    leftCardSizeLabel->setGeometry(0,0,50*ver,50*ver);
    leftCardSizeLabel->setText(tr("右部牌数"));
    getDizhuButton->setGeometry(450*ver,475*ver,100*ver,50*ver);
    getDizhuButton->setText(tr("抢地主"));
    getDizhuButton->hide();
    abandonDizhuButton->setGeometry(650*ver,475*ver,100*ver,50*ver);
    abandonDizhuButton->setText("不抢");
    abandonDizhuButton->hide();
    chupaiButton->setGeometry(450*ver,475*ver,100*ver,50*ver);
    chupaiButton->setText("出牌");
    chupaiButton->hide();
    buyaoButton->setGeometry(650*ver,475*ver,100*ver,50*ver);
    buyaoButton->setText("不要");
    buyaoButton->hide();
}
void BaseWidget::showChuOrBuyaoButton()
{
    chupaiButton->show();
    buyaoButton->show();
}
void BaseWidget::setCardBaseWidgetOnBaseWidget()
{
    cardBaseWidget=new CardsBaseWidget(this);
    cardBaseWidget->show();
}
void BaseWidget::getHideCardsss()
{
    rightCardAllLabel->show();
    leftCardAllLabel->show();
    cardsAllLabel->hide();
    getDizhuButton->show();
    abandonDizhuButton->show();
}
void BaseWidget::openGameButtonSlot()
{
    getRandomCardNumList();
    setUserRandomCardNumList();
    sortUserRandomCardNumList();
    cardsAllLabel->show();
    QPropertyAnimation *animation0=new QPropertyAnimation(cardsAllLabel,"geometry");
    animation0->setDuration(6000);
    animation0->setStartValue(QRect(550*ver,370*ver,150*ver,150*ver));
    animation0->setEndValue(QRect(550*ver,420*ver,150*ver,100*ver));
    animation0->start(QAbstractAnimation::DeleteWhenStopped);
    cardBaseWidget->openGame();
    openGameButton->hide();
}
void BaseWidget::writeLeftCardSize(int size)
{
    leftCardAllLabel->setText(QString::number(size));
}
void BaseWidget::writeRightCardSize(int size)
{
    rightCardAllLabel->setText(QString::number(size));
}
void BaseWidget::getRandomCardNumList()
{
    int i,j;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for(i=0;i<54;i++)//生成54个随机数
    {
        numbersList.append(qrand()%54);
        bool flag=true;
        while(flag)
        {
            for(j=0;j<i;j++)
            {
                if(numbersList[i]==numbersList[j])
                {
                    break;
                }
            }
            if(j<i)
            {
                numbersList[i]=rand()%54;
            }
            if(j==i)
            {
                flag=!flag;
            }
        }
    }
}
void BaseWidget::setUserRandomCardNumList()
{
    for(int i=0;i<17;i++)
    {
        userNumCardList.append(numbersList[i]);
    }
    for(int i=17;i<34;i++)
    {
        nongmin0NumCardList.append(numbersList[i]);
    }
    for(int i=34;i<51;i++)
    {
        nongmin1NumCardList.append(numbersList[i]);
    }
}
void BaseWidget::sortUserRandomCardNumList()
{
    qDebug()<<"11111111111111111111111";
    qDebug()<<userNumCardList.size();
    qDebug()<<"11111111111111111111111";
    cardBaseWidget->writeCardsSize(userNumCardList.size());
    qSort(userNumCardList.begin(),userNumCardList.end());
    for(int i=0;i<userNumCardList.size();i++)
    {
        qDebug()<<userNumCardList[i];
        cardBaseWidget->vector_card.at(i)->writeCardNum(userNumCardList[i]);
        cardBaseWidget->vector_card.at(i)->cardLabel->clear();
        cardBaseWidget->vector_card.at(i)->setGeometryAndLabel();
    }
}
void BaseWidget::getDizhuButtonSlot()//用户抢完地主后重新刷新牌面显示并且加入三张牌
{
    userNumCardList.append(numbersList[51]);
    userNumCardList.append(numbersList[52]);
    userNumCardList.append(numbersList[53]);
    qDeleteAll(cardBaseWidget->vector_card);
    cardBaseWidget->vector_card.clear();
    cardBaseWidget->writeCardsSize(userNumCardList.size());
    qSort(userNumCardList.begin(),userNumCardList.end());
    cardBaseWidget->setGeometryAndLabels();
    qDebug()<<"22222222222222222222222";
    qDebug()<<userNumCardList.size();
    qDebug()<<"22222222222222222222222";
    for(int i=0;i<userNumCardList.size();i++)
    {
        cardBaseWidget->vector_card.at(i)->writeCardNum(userNumCardList[i]);
        cardBaseWidget->vector_card.at(i)->cardLabel->clear();
        cardBaseWidget->vector_card.at(i)->setGeometryAndLabel();
        cardBaseWidget->vector_card.at(i)->setNoAnimation();
    }
    getDizhuButton->hide();
    abandonDizhuButton->hide();
    showChuOrBuyaoButton();
}
void BaseWidget::abandonDizhuButtonSlot()
{
    nongmin0NumCardList.append(numbersList[51]);
    nongmin0NumCardList.append(numbersList[52]);
    nongmin0NumCardList.append(numbersList[53]);
    getDizhuButton->hide();
    abandonDizhuButton->hide();
    showChuOrBuyaoButton();
}
void BaseWidget::chupaiButtonSlot()//出牌动作的实现，以及后台数据分析进行。
{
    int size=cardBaseWidget->readCardsSize();
    for(int i=0;i<size;i++)
    {
        if(cardBaseWidget->vector_card.at(i)->isup==true)
        {
            int value=cardBaseWidget->vector_card.at(i)->readCardNum();
            userNumCardList.removeOne(value);
            continue;
        }
    }
    qDeleteAll(cardBaseWidget->vector_card);
    cardBaseWidget->vector_card.clear();
    cardBaseWidget->writeCardsSize(userNumCardList.size());
    qSort(userNumCardList.begin(),userNumCardList.end());
    cardBaseWidget->setGeometryAndLabels();
    qDebug()<<"33333333333333333333333";
    qDebug()<<userNumCardList.size();
    qDebug()<<"33333333333333333333333";
    for(int i=0;i<userNumCardList.size();i++)
    {
        cardBaseWidget->vector_card.at(i)->writeCardNum(userNumCardList[i]);
        cardBaseWidget->vector_card.at(i)->cardLabel->clear();
        cardBaseWidget->vector_card.at(i)->setGeometryAndLabel();
        cardBaseWidget->vector_card.at(i)->setNoAnimation();
    }
    chupaiButton->hide();
    buyaoButton->hide();
}
void BaseWidget::buyaoButtonSlot()
{
    chupaiButton->hide();
    buyaoButton->hide();
}


















