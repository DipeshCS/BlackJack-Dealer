#-------------------------------------------------
#
# Project created by QtCreator 2015-08-19T00:47:03
#
#-------------------------------------------------

QT       += core gui network xml
QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dealer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    peer.cpp \
    message.cpp \
    table.cpp \
    card.cpp \
    dealer.cpp \
    player.cpp \
    decider.cpp

HEADERS  += mainwindow.h \
    peer.h \
    message.h \
    table.h \
    card.h \
    dealer.h \
    player.h \
    decider.h

FORMS    += mainwindow.ui
