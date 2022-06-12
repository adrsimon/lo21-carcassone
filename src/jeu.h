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
    int rotation=0;

    void addJoueur(std::string nom, TypeCouleur::points couleur, bool a, bool ac) {joueurs.push_back(new Joueur(nom, couleur, a, ac));}
    void setExtensions(bool m, bool r, bool ac, bool p, bool a);

public:
    // Singleton properties
    static Jeu& getJeu();
    void libererJeu();
    Jeu(const Jeu& j)=delete;
    Jeu& operator=(const Jeu& j)=delete;

    // Init
    void initialiser(std::vector<std::string> noms, std::vector<TypeCouleur::points> cs, bool m=true, bool r=false, bool ac=false, bool p = true, bool a = true);

    // Getters
    Pioche* getPioche() const {return pioche;}
    Tuile* getCurrentTuile() const {return currentTuile;}
    int getCurrentTuileId() const { return currentTuile->getID(); }
    Joueur* getCurrentJoueur() const {return currentJoueur;}
    TypeCouleur::points  getCurrentJoueurColor() const { return currentJoueur->getCouleur(); }
    Plateau* getPlateau() const {return plateau;}
    std::list<Joueur*> getJoueurs() const {return joueurs;}

    // Jeu functions
    void nextTurn();
    bool isGameFinished() const { return pioche->getTuiles().size() ==0; }
    int getTuilesAmount() const { return pioche->getTuiles().size() + pioche->getTuilesRiviere().size(); }
    std::vector<std::pair<TypeMeeple::points, int>> getPlayerMeeplesAmount() { return currentJoueur->getAvailableMeeplesAmount(); }
    std::vector<std::pair<TypeElement::points, int>> getSizeOfGroupements() { return plateau->getSizeOfGroupements(); }
    std::vector<std::pair<int,int>> getCordsOfDeletedMeeples();
    std::list<Groupement*> getCurrentTuileGroupements();
    std::vector<std::pair<int, int>> getAvailableTuilesChoices() { return plateau->getCasesLibres(); }
    bool isPlayerAbbePlaced() { return currentJoueur->isAbbePlaced(); }
    std::list<Element*> getCurrentTuileElements() { return currentTuile->getElements(); }
    int getFirstTuileId() { return plateau->getMap().at(std::pair<int,int>(6,11))->getID(); }
    int getRotation() const { return rotation; }
    void rotateTuile() { currentTuile->rotateOrientation(); rotation = (++rotation)%4; }
    bool tuileAction(int x, int y);
    bool meepleAction(Element* e, TypeMeeple::points t);
    void checkCurrentTuileGroupements();
    void attribuerPoints(Groupement* g);
    bool recupererMeeple(Meeple* m);
    void retirerPlayerAbbe();
};

#endif

