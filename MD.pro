#-------------------------------------------------
#
# Project created by QtCreator 2018-01-29T17:53:02
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MD
TEMPLATE = app
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        MainWindow.cpp \
        parser.cpp

HEADERS += \
        MainWindow.h \
        header.h

FORMS += \
        MainWindow.ui

INCLUDEPATH += \
        /usr/local/Cellar/boost/1.66.0/include
LIBS += -L/usr/local/Cellar/boost/1.66.0/lib/ -lboost_filesystem -lboost_system -lboost_regex

RESOURCES += \
    QRC.qrc
