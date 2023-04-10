QT += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    LoginWidgt.cpp \
    NetConnection.cpp \
    main.cpp \
    MainWidget.cpp

HEADERS += \
    ../Common.h \
    ILog.h \
    LoginWidgt.h \
    MainWidget.h \
    NetConnection.h\
    head.h

FORMS += \
    loginwidgt.ui \
    mainwidget.ui

RESOURCES   += $$PWD/core_qss/qss.qrc

INCLUDEPATH += $$PWD/core_base
include($$PWD/core_base/core_base.pri)
