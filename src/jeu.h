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
    std::list<TypeExtension> extensions;

    void addJoueur(std::string nom, TypeCouleur couleur) {joueurs.push_back(new Joueur(nom, couleur));}
    void setExtensions(bool m, bool r, bool ac);

public:
    // Singleton properties
    static Jeu& getJeu();
    void libererJeu();
    Jeu(const Jeu& j)=delete;
    Jeu& operator=(const Jeu& j)=delete;

    // Init
    void initialiser(std::vector<std::string> noms, std::vector<TypeCouleur> cs, bool m=false, bool r=false, bool ac=false);

    // Getters
    Pioche *const getPioche() const {return pioche;}
    Tuile* getCurrentTuile() const {return currentTuile;}
    int getCurrentTuileId() const { return currentTuile->getID(); }
    const Joueur* getCurrentJoueur() const {return currentJoueur;}
    Plateau *const getPlateau() const {return plateau;}
    std::list<Joueur*> getJoueurs() const {return joueurs;}

    // Jeu functions
    void nextTurn();
    bool isGameFinished() const { return pioche->getTuiles().size() ==0; }
    std::vector<std::pair<int, int>> tuileChoix() { return plateau->getCasesLibres(); }
    bool tuileAction(int x, int y);
    bool meepleAction(TypeElement e);

    void poserMeeple(Joueur* j, Element* e, TypeMeeple t);
    void recupererMeeple(Meeple* m);
    void tourTuile(int x, int y);
};

#endif

