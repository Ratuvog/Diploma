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
        qcustomplot.cpp \
        frame.cpp \
        models/heterogenitymodel.cpp \
        views/menubutton.cpp \
        views/abstractdomainview.cpp \
        views/menudomainview.cpp \
    views/firstinfodomainview.cpp \
    views/secondinfodomainview.cpp \
    views/thirdinfodomainview.cpp \
    models/domainmodel.cpp \
    plot.cpp \
    wheel.cpp

HEADERS  += mainwindow.h \
            qcustomplot.h \
            frame.h \
            models/heterogenitymodel.h \
            reader.h \
            views/menubutton.h \
            views/abstractdomainview.h \
            models/domains.h \
            views/menudomainview.h \
            models/abstractdomainmodel.h \
    views/firstinfodomainview.h \
    views/secondinfodomainview.h \
    views/thirdinfodomainview.h \
    models/domainmodel.h \
    plot.h \
    wheel.h

FORMS    += mainwindow.ui \
            frame.ui \
            views/abstractmenu.ui \
            views/menubutton.ui \
    views/firstinfodomainview.ui \
    views/secondinfodomainview.ui \
    views/thirdinfodomainview.ui

DISTFILES += \
    ../build-DRViewer-Desktop_Qt_5_4_1_GCC_32bit-Debug/input.txt \
    input.txt

RESOURCES += \
    resource.qrc
