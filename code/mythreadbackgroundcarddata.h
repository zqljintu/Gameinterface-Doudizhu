#ifndef MYTHREADBACKGROUNDCARDDATA_H
#define MYTHREADBACKGROUNDCARDDATA_H
#include <QThread>


class MyThreadBackgroundCardData : public QThread
{
public:
    MyThreadBackgroundCardData();
    void run();
private:
    struct CardData{
        int CardSize0;
        int CardSize1;
        int CardWeight;
    };
};

#endif // MYTHREADBACKGROUNDCARDDATA_H
