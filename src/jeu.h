#ifndef jeu_h
#define jeu_h

#include <stdio.h>
#include <list>
#include <algorithm>
#include <iterator> 
#include "joueur.h"
#include "plateau.h"

#include "iostream"
using namespace std; 

class Jeu{
public:
    Jeu& getJeu();
    void libererJeu();
    Jeu(const Jeu& j)=delete;
    Jeu& operator=(const Jeu& j)=delete;
    
    Pioche* getPioche() const {return  pioche;}
    
    Tuile* getLastTuile() const {return last_tuile;}
    
    const Joueur* getCurrent() const {return current; }
    
    const Plateau* getPlateau() const {return plateau;}
        
    list<Joueur*> getJoueur() const {return joueur;}
    
    void setJoueur(Joueur* j){
        joueur.push_back(j);
    }

    void poserMeeple();
    void updateJoueur();
    void updateTuile();
private:
    static Jeu* instance;
    Jeu();
    ~Jeu();
    Tuile* last_tuile;
    list<Joueur*> joueur;
    Joueur* current;
    const Plateau* plateau;
    Pioche* pioche;
};

#endif

