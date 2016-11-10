#-------------------------------------------------
#
# Project created by QtCreator 2016-11-09T20:53:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SeamCarving
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/image.cpp \
    src/graph.cpp \
    src/edge.cpp \
    src/pixel.cpp

HEADERS  += src/mainwindow.h \
    src/image.h \
    src/graph.h \
    src/edge.h \
    src/pixel.h

FORMS    += mainwindow.ui
