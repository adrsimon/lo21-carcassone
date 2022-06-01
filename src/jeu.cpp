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

void Jeu::initialiser() {
    plateau = &Plateau::getInstance();
    pioche = &Pioche::getInstance();
    setExtensions(true, true, false);
    pioche->genererTuiles(extensions);
}

// FONCTIONS DE JEU

void Jeu::setExtensions(const bool m, const bool r, const bool ac) {
    if (m) extensions.push_back(TypeExtension::main);
    if (r) extensions.push_back(TypeExtension::riviere);
    if (ac) extensions.push_back(TypeExtension::auberge);
}

void Jeu::poserMeeple(Joueur* j, Element* e, TypeMeeple t) {
    Meeple* m = j->getAvailableMeepleByType(t);
    if(m == nullptr)
        throw "meeple";
    Groupement* g = plateau->getGroupementWithElement(e);
    if(g == nullptr)
        throw "element";
    g->addMeeple(m);
}

void Jeu::recupererMeeple(Meeple* m){
    Groupement* g = plateau->getGroupementWithMeeple(m);
    if(g == nullptr)
        throw "groupement";
    g->removeMeeple(m);
}

void Jeu::updateJoueur(){
    auto it=joueurs.begin();
    for (it=joueurs.begin();it!=joueurs.end();it++) {
        if((*it)==this->getCurrent()) {
            it++;
            if(it==joueurs.end()) {
                currentJoueur = joueurs.front();
            } else {
                currentJoueur = *it;
            }
            break;
        }
    }
}

void Jeu::tourTuile(int x, int y) {
    if(pioche->piocher() == nullptr)
        throw "Jeu fini";
    std::cout<<"test";
}
void Jeu::updateTuile(){
    //last_tuile=pioche->piocher();
}


