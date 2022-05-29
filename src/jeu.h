#ifndef jeu_h
#define jeu_h

#include <list>
#include "joueur.h"
#include "plateau.h"
#include "enum.h"

#include "iostream"
using namespace std; 

class Jeu{
public:
    static Jeu& getJeu();
    void libererJeu();
    Jeu(const Jeu& j)=delete;
    Jeu& operator=(const Jeu& j)=delete;
    
    Pioche* getPioche() const {return pioche;}
    Tuile* getLastTuile() const {return last_tuile;}
    const Joueur* getCurrent() const {return current; }
    const Plateau* getPlateau() const {return plateau;}
    list<Joueur*> getJoueurs() const {return joueurs;}
    
    void setJoueur(Joueur* j){
        joueurs.push_back(j);
    }

    void poserMeeple(Joueur* j, Element* e, TypeMeeple t);
    void recupererMeeple(Meeple* m);
    void updateJoueur();
    void updateTuile();
    void jouer();
private:
    static Jeu* instance;
    Jeu();
    ~Jeu();
    Tuile* last_tuile;
    list<Joueur*> joueurs;
    Joueur* current;
    Plateau* plateau;
    Pioche* pioche;
    bool abbaye=false;
    bool riviere=false;
    bool aubergecathedrale = false;
};

#endif

