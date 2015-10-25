#-------------------------------------------------
#
# Project created by QtCreator 2015-09-29T21:45:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = justdraw
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    board.cpp

HEADERS  += mainwindow.h \
    board.h

FORMS    += mainwindow.ui
QMAKE_CXXFLAGS += -std=c++11
