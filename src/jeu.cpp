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

void Jeu::initialiser(std::vector<std::string> noms, std::vector<TypeCouleur::points> cs, bool m, bool r, bool ac, bool p, bool a) {
    // Création du plateau et de la pioche
    plateau = &Plateau::getInstance();
    pioche = &Pioche::getInstance();

    // Génération des tuiles en fonction des extensions
    setExtensions(m, r, ac, p , a);
    pioche->genererTuiles(extensions);

    // Initialisation des joueurs
    for(int i = 0; i < noms.size(); i++) {
        addJoueur(noms[i], cs[i], a, ac);
    }

    currentJoueur = joueurs.front();
    joueurs.push_back(joueurs.front());
    joueurs.pop_front();
    currentTuile = pioche->piocher();
    plateau->placerTuile(currentTuile,6,11);
    currentTuile = pioche->piocher();
}

void Jeu::nextTurn() {
    // On passe au joueur suivant
    currentJoueur = joueurs.front();
    joueurs.push_back(joueurs.front());
    joueurs.pop_front();
    // On pioche une tuile
    currentTuile = pioche->piocher();
    rotation=0;
}

bool Jeu::tuileAction(int x, int y) {
    if (plateau->getMap().empty()) {
        plateau->placerTuile(currentTuile, x, y);
        return true;}
    if (plateau->isTuileCompatible(x,y, currentTuile)) {
        plateau->placerTuile(currentTuile, x, y);
        return true;
    }
    return false;
}

bool Jeu::meepleAction(Element* e, TypeMeeple::points t) {
    Meeple* m = currentJoueur->getAvailableMeepleByType(t);
    Groupement* g = plateau->getGroupementWithElement(e);
    if(m == nullptr || g == nullptr || m->isPlaced() || !g->isMeepleAddable() || (e->getType() == TypeElement::jardin && t != TypeMeeple::abbe)) return false;
    std::cout << currentJoueur->getNom() << " a posé un Meeple " << TypeMeeple::toString(t) << " sur " << TypeElement::toString(e->getType()) << std::endl;
    g->addMeeple(m);
    e->setMeeple(true);
    m->setAvailable(false);
    return true;
}
// FONCTIONS DE JEU

void Jeu::setExtensions(const bool m, const bool r, const bool ac, bool p, bool a) {
    if (m) extensions.push_back(TypeExtension::main);
    if (r) extensions.push_back(TypeExtension::riviere);
    if (ac) extensions.push_back(TypeExtension::auberge);
    if (p) extensions.push_back(TypeExtension::paysan);
    if (a) extensions.push_back(TypeExtension::abbe);
}

bool Jeu::recupererMeeple(Meeple* m){
    Groupement* g = plateau->getGroupementWithMeeple(m);
    if(g == nullptr || !m->isPlaced()) return false;
    g->removeMeeple(m);
    m->setAvailable(true);
    return true;
}

std::list<Groupement*> Jeu::getCurrentTuileGroupements() {
    std::list<Groupement*> raws;
    std::list<Element*> elems = currentTuile->getElements();
    for(auto it = elems.begin(); it != elems.end(); it++) {
        raws.push_back(plateau->getGroupementWithElement(*it));
    }
    return raws;
}

void Jeu::checkCurrentTuileGroupements() {
    std::cout << "- Check des groupements terminés -" << std::endl;
    std::list<Groupement*> grps = plateau->getGroupementsWithTuile(currentTuile);
    for(auto it = grps.begin(); it != grps.end(); it++) {
        plateau->checkGroupement(*it);
        if((*it)->isFinished()) {
            std::cout << "Groupement " << TypeElement::toString((*it)->getType()) << " terminé." << std::endl;
            attribuerPoints(*it);
            std::list<Meeple*> mpls = (*it)->getMeeples();
            for(auto it2 = mpls.begin(); it2 != mpls.end(); it2++) {
                (*it2)->setAvailable(true);
            }
            (*it)->clearMeeples();
        }
    }
}

void Jeu::attribuerPoints(Groupement* g) {
    int score = plateau->evaluerGroupement(g);
    std::list<Meeple*> meeples = (g)->getMeeples();
    map<Joueur*, int> numbers;
    // INSERT RAWS
    for(auto it = joueurs.begin(); it != joueurs.end(); it++) {
        numbers.insert(pair<Joueur*, int>(*it, 0));
    }
    // ADD COUNT
    for(auto it = meeples.begin(); it != meeples.end(); it++) {
        for(auto it2 = joueurs.begin(); it2 != joueurs.end(); it2++) {
            if((*it2)->isMeepleOfPlayer(*it))
                numbers.find(*it2)->second+= (*it)->getPoids();
        }
    }
    bool alone=true;
    int max = 0;
    std::list<Joueur*> jWinners;
    // SETTINGS WINNERS
    for(auto it = numbers.begin(); it != numbers.end(); it++) {
        if((*it).second > max) {
            max = (*it).second;
            jWinners.clear();
            jWinners.push_back((*it).first);
        } else if((*it).second == max && max != 0)
            jWinners.push_back((*it).first);
    }
    for(auto it = jWinners.begin(); it != jWinners.end(); it++) {
        std::cout << "Le joueur " << (*it)->getNom() << " a gagné " << to_string(score) << " points." << std::endl;
        (*it)->setScore((*it)->getScore() + score);
    }

}

std::vector<std::pair<int,int>> Jeu::getCordsOfDeletedMeeples() {
    std::vector<pair<int,int>> raws;
    std::list<Groupement*> grps = getCurrentTuileGroupements();
    for(auto it = grps.begin(); it != grps.end(); it++) {
        if((*it)->isFinished()) {
            std::list<Element*> elems = (*it)->getElements();
            for(auto it2 = elems.begin(); it2 != elems.end(); it2++) {
                Tuile* t = plateau->getTuileWithElement(*it2);
                std::pair<int,int> cords = plateau->getTuileCoordinates(t);
                raws.push_back(cords);
            }
        }
    }
    return raws;
}

void Jeu::retirerPlayerAbbe() {
    Meeple* m = currentJoueur->getAbbe();
    m->setAvailable(true);
    Groupement* g = plateau->getGroupementWithMeeple(m);
    g->removeMeeple(m);
    currentJoueur->setScore(currentJoueur->getScore() + plateau->evaluerGroupement(g));
}
