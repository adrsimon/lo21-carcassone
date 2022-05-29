cmake_minimum_required(VERSION 3.20)
project(lo21_carcassone)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(lo21_carcassone
        main.cpp
        #src/enum.h
        #src/element.cpp
        #src/element.h
        #src/groupement.cpp
        #src/groupement.h
        #src/joueur.cpp
        #src/joueur.h
        #src/plateau.cpp
        #src/plateau.h
        #src/pioche.cpp
        #src/pioche.h
        #src/position.cpp
        #src/position.h
        #src/tuile.cpp
        #src/tuile.h
        #src/jeu.h
        #src/jeu.cpp
        #src/meeple.cpp
        #src/meeple.h
        #src/gameengine.cpp
        #src/gameengine.h
        #utils/libraries/tinyxml2.cpp
        #utils/libraries/tinyxml2.h
        VuePartie.h
        VuePartie.cpp
        VueSettings.cpp
        VueSettings.h
        VueTuile.cpp
        VueTuile.h
        VueValider.cpp
        VueValider.h
        VuePlateau.h
        VuePlateau.cpp)

target_link_libraries(lo21_carcassone PUBLIC Qt6::Widgets)