#-------------------------------------------------
#
# Project created by QtCreator 2015-01-06T14:13:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11

TARGET = QThreads
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    worker.cpp \
    threadspinner.cpp

HEADERS  += mainwindow.h \
    worker.h \
    threadspinner.h

FORMS    += mainwindow.ui
