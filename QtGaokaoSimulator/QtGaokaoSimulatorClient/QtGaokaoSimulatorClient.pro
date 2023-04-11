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

#指定编译生成的可执行文件放到源码上一级目录下的bin目录
!android {
!wasm {
DESTDIR = $$PWD/bin
}}

DIR1 = $$PWD/../DataBase/database.sqlite3
DIR2 = $$DESTDIR
# 将/替换为\\才能正确识别路径
DIR11 = $$replace(DIR1, /, \\)  # replace函数的第一个参数必须是大写，坑死了
DIR21 = $$replace(DIR2, /, \\)
QMAKE_POST_LINK += copy $$DIR11 $$DIR21

