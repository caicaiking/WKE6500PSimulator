#-------------------------------------------------
#
# Project created by QtCreator 2017-10-01T11:21:28
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WKE6500LanSimulator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        clsMainWindow.cpp \
    clsWK6500MServer.cpp \
    MyThread.cpp \
    clsWKCommandProcess.cpp

HEADERS += \
        clsMainWindow.h \
    clsWK6500MServer.h \
    MyThread.h \
    clsWKCommandProcess.h \
    singleton.h

FORMS += \
        clsMainWindow.ui
