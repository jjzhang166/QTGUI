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
    sgen.cpp \
    mgen.cpp \
    mainwindow.cpp \
    Model.cpp

HEADERS  += \
    ModelGenerator.h \
    mgen.h \
    sgen.h \
    lgen.h \
    saver.h \
    model.h \
    loader.h \
    parse.h \
    mainwindow.h

FORMS    += mainwindow.ui
