#ifndef jeu_h
#define jeu_h

#include <stdio.h>
#include <list>
#include <algorithm>
#include <iterator> 
#include "joueur.h"
#include "plateau.h"
#include "enum.h"

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
        
    list<Joueur*> getJoueurs() const {return joueurs;}
    
    static void setJoueur(Joueur* j){
        joueurs.push_back(j);
    }

    static void poserMeeple(const std::string type, Element* e);
    static void recupererMeeple(Meeple& m);
    static void updateJoueur();
    static void updateTuile();
private:
    static Jeu* instance;
    Jeu();
    ~Jeu();
    static Tuile* last_tuile;
    static list<Joueur*> joueurs;
    static Joueur* current;
    const Plateau* plateau;
    static Pioche* pioche;
};

#endif

