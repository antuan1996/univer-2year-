#-------------------------------------------------
#
# Project created by QtCreator 2016-01-18T20:27:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = puzzle
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainboard.cpp \
    pmodel.cpp \
    pview.cpp \
    settings.cpp \
    buckets.cpp \
    superdsu.cpp

HEADERS  += mainboard.h \
    pmodel.h \
    pview.h \
    settings.h \
    enums.h \
    buckets.h \
    superdsu.h

FORMS    +=
