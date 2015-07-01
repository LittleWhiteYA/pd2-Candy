#-------------------------------------------------
#
# Project created by QtCreator 2015-06-02T05:44:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SignalTest
TEMPLATE = app


SOURCES += main.cpp\
        signalwindow.cpp \
    signaldialog.cpp \
    bomb_stone.cpp \
    game.cpp \
    gametimer.cpp \
    horizon_stone.cpp \
    judger.cpp \
    normal_stone.cpp \
    result.cpp \
    score.cpp \
    star_stone.cpp \
    start.cpp \
    stone.cpp \
    vertical_stone.cpp \
    ../game.cpp \
    ../main.cpp \
    ../result.cpp \
    ../square.cpp

HEADERS  += signalwindow.h \
    signaldialog.h \
    bomb_stone.h \
    define.h \
    game.h \
    gametimer.h \
    horizon_stone.h \
    judger.h \
    normal_stone.h \
    result.h \
    score.h \
    star_stone.h \
    start.h \
    stone.h \
    vertical_stone.h \
    ../game.h \
    ../result.h

FORMS    += signalwindow.ui \
    signaldialog.ui \
    game.ui \
    result.ui \
    start.ui \
    ../game.ui \
    ../result.ui

SUBDIRS += \
    Crush.pro

RESOURCES += \
    layout.qrc

DISTFILES += \
    1.png \
    1_star.png \
    1-1.png \
    1-b.png \
    1-b-1.png \
    1-h.png \
    1-h-1.png \
    1-v.png \
    1-v-1.png \
    2.png \
    2_star.png \
    2-1.png \
    2-b.png \
    2-b-1.png \
    2-h.png \
    2-h-1.png \
    2-v.png \
    2-v-1.png \
    3.png \
    3_star.png \
    3-1.png \
    3-b.png \
    3-b-1.png \
    3-h.png \
    3-h-1.png \
    3-v.png \
    3-v-1.png \
    4.png \
    4-1.png \
    4-b.png \
    4-b-1.png \
    4-h.png \
    4-h-1.png \
    4-v.png \
    4-v-1.png \
    back.png \
    Fail.png \
    quit.png \
    restart.png \
    s.png \
    s-1.png \
    star.png \
    star_1.png \
    start.png \
    start-1.png \
    startback.png \
    stoneback.png \
    Time.png \
    Icon.ico \
    Crush.pro.user \
    Rules.txt
