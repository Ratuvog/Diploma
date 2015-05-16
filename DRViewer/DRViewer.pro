#-------------------------------------------------
#
# Project created by QtCreator 2015-03-13T17:03:39
#
#-------------------------------------------------

QT       += core gui widgets printsupport

TARGET = DRViewer
TEMPLATE = app

INCLUDEPATH += .. models views

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
        wheel.cpp \
        cursormodel.cpp \
        cursorgraph.cpp \
        reflectogram.cpp \
        labelprovider.cpp \
        reflectogramreader.cpp

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
            wheel.h \
            cursormodel.h \
            cursorgraph.h \
            reflectogram.h \
            labelprovider.h \
            reflectogramreader.h

FORMS    += mainwindow.ui \
            frame.ui \
            views/abstractmenu.ui \
            views/menubutton.ui \
            views/firstinfodomainview.ui \
            views/secondinfodomainview.ui \
            views/thirdinfodomainview.ui

RESOURCES += \
    resource.qrc
