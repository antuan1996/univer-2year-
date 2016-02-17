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
    buckets.cpp \
    superdsu.cpp \
    control.cpp \
    startwindow.cpp \
    previewfiledialog.cpp

HEADERS  += mainboard.h \
    pmodel.h \
    pview.h \
    enums.h \
    buckets.h \
    superdsu.h \
    control.h \
    startwindow.h \
    previewfiledialog.h

FORMS    += \
    control.ui \
    startwindow.ui

RESOURCES += \
    resources_puzzle.qrc
