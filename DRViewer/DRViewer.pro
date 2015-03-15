#-------------------------------------------------
#
# Project created by QtCreator 2015-03-13T17:03:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = DRViewer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        qcustomplot.cpp

HEADERS  += mainwindow.h \
            qcustomplot.h

FORMS    += mainwindow.ui

DISTFILES += \
    ../build-DRViewer-Desktop_Qt_5_4_1_GCC_32bit-Debug/input.txt \
    input.txt
