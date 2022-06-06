TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
#CONFIG -= qt
QT += widgets
QT += core
QT += gui
SOURCES += \
        VuePartie.cpp \
        VuePlateau.cpp \
        VueSettings.cpp \
        VueTuile.cpp \
        VueValider.cpp \
        main.cpp \

HEADERS += \
    VuePartie.h \
    VuePlateau.h \
    VueSettings.h \
    VueTuile.h \
    VueValider.h \

FORMS +=

DISTFILES += \
    utils/tiles_illustrations/1.jpeg
