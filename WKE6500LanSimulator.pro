#-------------------------------------------------
#
# Project created by QtCreator 2017-10-01T11:21:28
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WKE6500LanSimulator
TEMPLATE = app
INCLUDEPATH += Public Server Utilities UserInterface

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


DESTDIR =$$PWD/Exe/


HEADERS += \
    Public/ScreenHelper.h \
    Server/clsTcpIpThread.h \
    Server/clsWKServer.h \
    UserInterface/frmWK6500PUi.h \
    Utilities/clsWK6500P.h \
    Utilities/clsWKCommandProcess.h \
    Public/singleton.h \
    Public/doubleType.h \
    UserInterface/wk6500LevelInputBox.h \
    UserInterface/wk6500Range.h \
    UserInterface/wk6500Speed.h \
    UserInterface/NumberInput.h \
    UserInterface/wk6500Function.h \
    Public/clsComplexOp.h \
    Public/clsUserFunction.h

SOURCES += \
    Public/main.cpp \
    Public/ScreenHelper.cpp \
    Server/clsTcpIpThread.cpp \
    Server/clsWKServer.cpp \
    UserInterface/frmWK6500PUi.cpp \
    Utilities/clsWK6500P.cpp \
    Utilities/clsWKCommandProcess.cpp \
    Public/doubleType.cpp \
    UserInterface/wk6500LevelInputBox.cpp \
    UserInterface/wk6500Range.cpp \
    UserInterface/wk6500Speed.cpp \
    UserInterface/NumberInput.cpp \
    UserInterface/wk6500Function.cpp \
    Public/clsComplexOp.cpp \
    Public/clsUserFunction.cpp

FORMS += \
    UserInterface/frmWK6500PUi.ui \
    UserInterface/wk6500LevelInputBox.ui \
    UserInterface/wk6500Range.ui \
    UserInterface/wk6500Speed.ui \
    UserInterface/NumberInput.ui \
    UserInterface/wk6500Function.ui

RESOURCES += \
    Res/WKRes.qrc

RC_FILE  =Icon.rc
