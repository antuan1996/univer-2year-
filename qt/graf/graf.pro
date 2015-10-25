#-------------------------------------------------
#
# Project created by QtCreator 2015-09-28T16:15:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = graf
TEMPLATE = app


SOURCES += main.cpp\
        mainw.cpp \
    drawarea.cpp \
    setter.cpp \
    pallete.cpp

HEADERS  += mainw.h \
    drawarea.h \
    setter.h \
    pallete.h

FORMS    += mainw.ui \
    setter.ui
QMAKE_CXXFLAGS += -std=c++11
