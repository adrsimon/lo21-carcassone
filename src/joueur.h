//
// Created by peron on 01/05/2022.
//

#ifndef PROJET_JOUEUR_H
#define PROJET_JOUEUR_H

#include <string>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

class Meeple;

class Joueur {
private:
    int score;
    std::list<Meeple> meeples;
    const std::string nom;
public:
    // Getters
    std::list<Meeple> getMeeples() const { return meeples; }
    int getScore() const { return score; }
    std::string getNom() const { return nom; }
    // Setters
    void setScore(int s) { score = s; }

    // Constructors and Desctructors
    Joueur(std::string nom) : nom(nom), score(0) {
        // Meeple creation here
    }
};

#endif //PROJET_JOUEUR_H
