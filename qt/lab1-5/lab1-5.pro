#-------------------------------------------------
#
# Project created by QtCreator 2015-09-01T19:46:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab1-5
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    subw.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    subw.h \
    str.h \
    dialog.h

FORMS    += mainwindow.ui \
    subw.ui \
    dialog.ui
QMAKE_CXXFLAGS += -std=c++11
