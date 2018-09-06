#include "verdesktop.h"

VerDesktop::VerDesktop(QObject *parent) : QObject(parent)
{
}
float VerDesktop::getVerDesktop()
{
    QDesktopWidget dw;
    float ver=float(dw.screenGeometry().width())/float(1920);
    return ver;
}
