#ifndef VERDESKTOP_H
#define VERDESKTOP_H

#include <QObject>
#include <QDesktopWidget>

class VerDesktop : public QObject
{
    Q_OBJECT
public:
    explicit VerDesktop(QObject *parent = 0);
    float getVerDesktop();

signals:

public slots:
};

#endif // VERDESKTOP_H
