#include <iostream>
#include <string>
#include <list>
#include "jeu.h"
#include "meeple.h"

Jeu* Jeu::instance=nullptr;

Jeu& Jeu::getJeu(){
    if(instance==nullptr){
        instance = new Jeu;
    }
    return *instance;
}

void Jeu::libererJeu(){
    delete instance;
    instance=nullptr;
}

Jeu::Jeu() = default;
Jeu::~Jeu() = default;

// FONCTIONS DE JEU

void Jeu::poserMeeple(Meeple* m, Element* e) {
    std::string type = m->getType();

    auto it=current->getMeeples().begin();
    if (type=="Normal") {
        for (it=current->getMeeples().begin();it!=current->getMeeples().end();it++) {
            if(it->getType()=="Normal") continue;
            if(it->getDisponible()==true)
                break;
        }
        if(it==current->getMeeples().end()) std::cout << "Pas de meeple disponible" << std::endl;
        it->updateMeeple();
    } else {
        if (type=="Abbe") {
            for (it=current->getMeeples().begin();it!=current->getMeeples().end();it++) {
                if(it->getType()!="Abbe") continue;
                if(it->getDisponible()==true) break;
            }
            if(it==current->getMeeples().end()) std::cout << "Pas de meeple disponible" << std::endl;
            if(e->getType()=="abbaye" && e->getType()=="jardin"){
                it->updateMeeple();
            } else {
                std::cout << "Impossible de poser un Abbé ici" << std::endl;
            }
        } else {
            if(type=="Big") {
                for (it=current->getMeeples().begin();it!=current->getMeeples().end();it++) {
                    if(it->getType()!="Big") continue;
                    if(it->getDisponible()==true) break;
                }
                if(it!=current->getMeeples().end()) std::cout << "Pas de meeple disponible" << std::endl;
                it->updateMeeple();
            } else {
                std::cout << "Le type n'existe pas." << std::endl;
            }
        }
    }
}

void Jeu::recupererMeeple(Meeple& m){
    m.updateMeeple(); 
}


void Jeu::updateJoueur(){
    auto it=joueurs.begin();
    for (it=joueurs.begin();it!=joueurs.end();it++) {
        if((*it)==this->getCurrent()) {
            it++;
            if(it==joueurs.end()) {
                current = joueurs.front();
            } else {
                current = *it;
            }
            break;
        }
    }
}

void Jeu::updateTuile(){
    //last_tuile=pioche->piocher();
}


