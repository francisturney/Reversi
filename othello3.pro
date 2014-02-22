#-------------------------------------------------
#
# Project created by QtCreator 2013-04-29T17:34:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = othello
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    piece.cpp \
    square.cpp

HEADERS  += mainwindow.h \
    piece.h \
    square.h

FORMS    += mainwindow.ui \
    piece.ui
