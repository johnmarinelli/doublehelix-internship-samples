#-------------------------------------------------
#
# Project created by QtCreator 2015-01-16T21:44:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_CXXFLAGS += -std=c++11

TARGET = doublehelix-multithreading-example
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myitem.cpp

HEADERS  += mainwindow.h \
    myitem.h

FORMS    += mainwindow.ui

RESOURCES += \
    assets/assets.qrc
