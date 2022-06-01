//
// Created by peron on 01/05/2022.
//

#ifndef PROJET_JOUEUR_H
#define PROJET_JOUEUR_H

#include <string>
#include <vector>
#include <list>
#include <iterator>
#include "meeple.h"

using namespace std;

class Joueur {
private:
    int score;
    std::list<Meeple*> meeples;
    const std::string nom;
    TypeCouleur couleur;
public:
    // Getters
    std::list<Meeple*> getMeeples() const { return meeples; }
    Meeple* getAvailableMeepleByType(TypeMeeple t);
    int getScore() const { return score; }
    std::string getNom() const { return nom; }
    TypeCouleur getCouleur() const { return couleur; }
    // Setters
    void setScore(int s) { score = s; }

    // Constructors and Destructors
    Joueur(std::string nom, TypeCouleur couleur) : nom(nom), couleur(couleur), score(0) {
        for(int i=0; i<5; i++) {
            meeples.push_back(new Meeple());
        }
        meeples.push_back(new BigMeeple());
        meeples.push_back(new AbbeMeeple());
    }
};

#endif //PROJET_JOUEUR_H
