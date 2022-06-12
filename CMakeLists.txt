cmake_minimum_required(VERSION 3.20)
project(lo21-carcassone)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(lo21-carcassone
        main.cpp
        src/jeu.cpp
        src/jeu.h
        src/plateau.cpp
        src/plateau.h
        src/element.cpp
        src/element.h
        src/groupement.cpp
        src/groupement.h
        src/meeple.cpp
        src/meeple.h
        src/pioche.cpp
        src/pioche.h
        src/joueur.h
        src/joueur.cpp
        src/tuile.cpp
        src/tuile.h
        VuePartie.cpp
        VuePartie.h
        VueSettings.h
        VueSettings.cpp
        VueTuile.cpp
        VueTuile.h
        VuePlateau.cpp
        VuePlateau.h
        utils/libraries/tinyxml2.h
        utils/libraries/tinyxml2.cpp
        src/enum.cpp
        VuePoseMeeple.cpp
        VuePoseMeeple.h)

target_link_libraries(lo21-carcassone PUBLIC Qt6::Widgets)
