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

void Jeu::initialiser(std::vector<std::string> noms, std::vector<TypeCouleur> cs, bool m, bool r, bool ac) {
    // Création du plateau et de la pioche
    plateau = &Plateau::getInstance();
    pioche = &Pioche::getInstance();

    // Génération des tuiles en fonction des extensions
    setExtensions(m, r, ac);
    pioche->genererTuiles(extensions);

    // Initialisation des joueurs
    for(int i = 0; i < noms.size(); i++) {
        addJoueur(noms[i], cs[i]);
    }

    currentJoueur = joueurs.front();
    plateau->placerTuile(pioche->piocher(), 0, 0);
    currentTuile = pioche->piocher();
}

void Jeu::nextTurn() {
    // On passe au joueur suivant
    joueurs.push_back(joueurs.front());
    joueurs.pop_front();
    currentJoueur = joueurs.front();
    // On pioche une tuile
    currentTuile = pioche->piocher();
}

bool Jeu::tuileAction(int x, int y) {
    if(plateau->isTuileCompatible(x,y, currentTuile)) {
        plateau->placerTuile(currentTuile, x, y);
        return true;
    }
    return false;
}

bool Jeu::meepleAction(TypeElement e) {
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

void Jeu::tourTuile(int x, int y) {
    if(pioche->piocher() == nullptr)
        throw "Jeu fini";
    std::cout<<"test";
}


