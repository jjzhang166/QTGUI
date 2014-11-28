#-------------------------------------------------
#
# Project created by QtCreator 2014-10-28T17:53:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = COMP523ProjectQTParamCp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sgen.cpp

HEADERS  += mainwindow.h \
    ModelGenerator.h \
    mgen.h \
    sgen.h \
    lgen.h \
    saver.h \
    model.h \
    loader.h \
    parse.h

FORMS    += mainwindow.ui
