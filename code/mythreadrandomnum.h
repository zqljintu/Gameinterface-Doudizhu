#ifndef MYTHREADRANDOMNUM_H
#define MYTHREADRANDOMNUM_H
#include <QThread>
#include <QDebug>
#include <QList>


class MyThreadRandomNum : public QThread
{
public:
    MyThreadRandomNum();
    void run();
    QList<int> getRandomCardList();//返回这个类型值
private:
    QList<int> numbersList;

protected:

};

#endif // MYTHREADRANDOMNUM_H
