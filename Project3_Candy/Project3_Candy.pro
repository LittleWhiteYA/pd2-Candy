#-------------------------------------------------
#
# Project created by QtCreator 2015-06-09T19:16:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project3_Candy
TEMPLATE = app


SOURCES += main.cpp\
        game.cpp \
    square.cpp \
    result.cpp

HEADERS  += game.h \
    square.h \
    result.h

FORMS    += game.ui \
    result.ui

RESOURCES += \
    resource.qrc

DISTFILES +=
