#ifndef jeu_h
#define jeu_h

#include <list>
#include "joueur.h"
#include "plateau.h"
#include "enum.h"

#include "iostream"

class Jeu{
private:
    static Jeu* instance;
    Jeu();
    ~Jeu();
    Tuile* currentTuile;
    std::list<Joueur*> joueurs;
    Joueur* currentJoueur;
    Plateau* plateau;
    Pioche* pioche;
    std::list<TypeExtension::points> extensions;

    void addJoueur(std::string nom, TypeCouleur::points couleur) {joueurs.push_back(new Joueur(nom, couleur));}
    void setExtensions(bool m, bool r, bool ac);

public:
    // Singleton properties
    static Jeu& getJeu();
    void libererJeu();
    Jeu(const Jeu& j)=delete;
    Jeu& operator=(const Jeu& j)=delete;

    // Init
    void initialiser(std::vector<std::string> noms, std::vector<TypeCouleur::points> cs, bool m=false, bool r=false, bool ac=false);

    // Getters
    Pioche *const getPioche() const {return pioche;}
    Tuile* getCurrentTuile() const {return currentTuile;}
    int getCurrentTuileId() const { return currentTuile->getID(); }
    Joueur *const getCurrentJoueur() const {return currentJoueur;}
    Plateau *const getPlateau() const {return plateau;}
    std::list<Joueur*> getJoueurs() const {return joueurs;}

    // Jeu functions
    void nextTurn();
    bool isGameFinished() const { return pioche->getTuiles().size() ==0; }
    int getTuilesAmount() const { return pioche->getTuiles().size() + pioche->getTuilesRiviere().size(); }
    std::vector<std::pair<TypeMeeple::points, int>> getPlayerMeeplesAmount() { return currentJoueur->getAvailableMeeplesAmount(); }
    std::vector<std::pair<TypeElement::points, int>> getSizeOfGroupements() { return plateau->getSizeOfGroupements(); }
    std::vector<std::pair<int, int>> getAvailableTuilesChoices() { return plateau->getCasesLibres(); }
    std::list<Element*> getCurrentTuileElements() { return currentTuile->getElements(); }
    int getFirstTuileId() { return plateau->getMap().at(pair<int,int>(0,0))->getID(); }
    void rotateTuile() { return currentTuile->rotateOrientation(); }
    bool tuileAction(int x, int y);
    bool meepleAction(Element* e, TypeMeeple::points t);
    bool recupererMeeple(Meeple* m);
};

#endif

