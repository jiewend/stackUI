#-------------------------------------------------
#
# Project created by QtCreator 2016-12-23T04:20:03
#
#-------------------------------------------------

QT       += core gui webenginewidgets multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11
TARGET = UWAN
TEMPLATE = app
#UI_DIR = ./UI


SOURCES += main.cpp\
        mainwindow.cpp \
    pcommunication.cpp \
    usermainwindow.cpp \
    nodeitem.cpp \
    imtoolbox.cpp \
    imtoolitem.cpp \
    qqbutton.cpp \
    chatwindows.cpp \
    faceform.cpp \
    camera.cpp \
    showfigwidget.cpp \
    topo.cpp\
    recv_image.cpp \
    rs.cpp

HEADERS  += mainwindow.h \
    app_datapackage.h \
    definefile.h \
    pcommunication.h \
    usermainwindow.h \
    nodeitem.h \
    imtoolbox.h \
    imtoolitem.h \
    qqbutton.h \
    chatwindows.h \
    faceform.h \
    camera.h \
    showfigwidget.h \
    topo.h \
    recv_image.h \
    rs.h

FORMS    += mainwindow.ui \
    usermainwindow.ui \
    chatwindows.ui \
    faceform.ui \
    camera.ui \
    showfigwidget.ui \
    topo.ui \
    recv_image.ui

RESOURCES += \
    figresource.qrc

LIBS += -lpthread

DISTFILES += \
    messageBox.html
