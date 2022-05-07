//
//  jeu.hpp
//  
//
//  Created by Claire Louard on 01/05/2022.
//

#ifndef jeu_hpp
#define jeu_hpp

#include <stdio.h>

#endif /* jeu_hpp */
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
}



