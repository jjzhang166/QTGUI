#-------------------------------------------------
#
# Project created by QtCreator 2014-12-05T22:08:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Comp523QTParamCp
TEMPLATE = app


SOURCES += main.cpp \
    lgen.cpp \
    loader.cpp \
    mainwindow.cpp \
    mgen.cpp \
    model.cpp \
    ModelClass.cpp \
    saver.cpp \
    sgen.cpp \
    TestLoader.cpp \
    TestModel.cpp \
    TestSaver.cpp

HEADERS  += \
    lgen.h \
    loader.h \
    mainwindow.h \
    mgen.h \
    model.h \
    ModelClass.h \
    parse.h \
    saver.h \
    sgen.h \
    TestLoader.h \
    TestModel.h \
    TestSaver.h

FORMS    += mainwindow.ui
