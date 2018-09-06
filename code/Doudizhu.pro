#-------------------------------------------------
#
# Project created by QtCreator 2017-02-28T11:01:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Doudizhu
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    basewidget.cpp \
    verdesktop.cpp \
    cardwidget.cpp \
    cardsbasewidget.cpp \
    mythreadrandomnum.cpp \
    mythreadbackgroundcarddata.cpp

HEADERS  += mainwindow.h \
    basewidget.h \
    verdesktop.h \
    cardwidget.h \
    cardsbasewidget.h \
    mythreadrandomnum.h \
    mythreadbackgroundcarddata.h

FORMS +=

RESOURCES += \
    image.qrc
