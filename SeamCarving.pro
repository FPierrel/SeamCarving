#-------------------------------------------------
#
# Project created by QtCreator 2016-11-09T20:53:14
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SeamCarving
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/image.cpp \
    src/graph.cpp \
    src/edge.cpp \
    src/pixel.cpp \
    src/heap.cpp \
    src/seamcarving.cpp

HEADERS  += src/mainwindow.h \
    src/image.h \
    src/graph.h \
    src/edge.h \
    src/pixel.h \
    src/heap.h \
    src/seamcarving.h

FORMS    += mainwindow.ui
