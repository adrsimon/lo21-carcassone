QT += widgets

SOURCES += main.cpp

SOURCES += VuePartie.cpp
SOURCES += VuePlateau.cpp
SOURCES += VuePoseMeeple.cpp
SOURCES += VueSettings.cpp
SOURCES += VueTuile.cpp

HEADERS += VuePartie.h
HEADERS += VuePlateau.h
HEADERS += VuePoseMeeple.h
HEADERS += VueSettings.h
HEADERS += VueTuile.h

SOURCES += src/element.cpp
SOURCES += src/enum.cpp
SOURCES += src/groupement.cpp
SOURCES += src/jeu.cpp
SOURCES += src/joueur.cpp
SOURCES += src/meeple.cpp
SOURCES += src/pioche.cpp
SOURCES += src/plateau.cpp
SOURCES += src/tuile.cpp

HEADERS += src/element.h
HEADERS += src/enum.h
HEADERS += src/groupement.h
HEADERS += src/jeu.h
HEADERS += src/joueur.h
HEADERS += src/meeple.h
HEADERS += src/pioche.h
HEADERS += src/plateau.h
HEADERS += src/tuile.h

SOURCES += utils/libraries/tinyxml2.cpp
HEADERS += utils/libraries/tinyxml2.h
