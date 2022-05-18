#ifndef jeu_h
#define jeu_h

#include <stdio.h>
#include "joueur.h"
#include "plateau.h"

#include "iostream"
using namespace std; 

class Jeu{
public:
    Jeu(const Joueur* ls_joueur, const Tuile* p, const int& nb): last_tuile(NULL), liste(ls_joueur), current(ls_joueur), pioche(p), nb_joueur(nb){
        Plateau* plateau=Plateau();
    }
    void poserMeeple();
    void updateJoueur();
    void updateTuile();
    void evaluerScore();
    void play();
private:
    Tuile* last_tuile;
    Joueur* liste;
    Joueur* current;
    Plateau* plateau;
    Tuile* pioche;
    int nb_joueur;
};

#endif

