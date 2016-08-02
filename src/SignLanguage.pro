
QT       += core gui widgets

TARGET = SignLanguage
TEMPLATE = app

SOURCES += main.cpp\
           mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += $$PWD/includes

LIBS += -L$$PWD/includes/libs

LIBS += -lopencv_core231\
        -lopencv_highgui231\
        -lopencv_imgproc231


#INCLUDEPATH += $$(OPENCV)\include

#LIBS += -L$$(OPENCV)\x64\vc14\lib -lopencv_world310
