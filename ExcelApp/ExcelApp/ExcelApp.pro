#-------------------------------------------------
#
# Project created by QtCreator 2019-12-18T22:09:04
#
#-------------------------------------------------

QT       += core gui printsupport winextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network axcontainer

TARGET = ExcelApp
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        dialog.cpp \
    headdialog.cpp \
    scanoptionform.cpp \
    dib.cpp \
    indexdialog.cpp \
    qtwaininterface.cpp \
    twaincpp.cpp \
    dibfile.c \
    dibutil.c \
    qtwain.cpp \
    scanthread.cpp \
    processbardialog.cpp

HEADERS  += dialog.h \
    headdialog.h \
    scanoptionform.h \
    dib.h \
    dibapi.h \
    dibutil.h \
    indexdialog.h \
    qtwain.h \
    qtwaininterface.h \
    twain.h \
    twaincpp.h \
    stdafx.h \
    scanthread.h \
    processbardialog.h

FORMS    += dialog.ui \
    headdialog.ui \
    scanoptionform.ui \
    indexdialog.ui \
    processbardialog.ui

RESOURCES += \
    res.qrc

LIBS += -lgdi32
