//
// Created by peron on 01/05/2022.
//

#ifndef PROJET_JOUEUR_H
#define PROJET_JOUEUR_H

#include <string>

class Joueur {
private:
    bool hasBigMeeple;
    bool abbe;
    int score;
    int meepleNumbers;
    int id;
public:
    int getNbMeeple() const { return meepleNumbers; }
    int getScore() const { return score; }
    int getID() const { return id; }
    bool getAbbe() const { return abbe; }
    bool getBigMeepple() const { return hasBigMeeple; }
    void setAbbe(bool a) { abbe = a; }
    void setBigMeeple(bool m) { hasBigMeeple = m; }
    void setScore(int a) {}
};

class JoueurException {
private:
    std::string info;
public:
    JoueurException(std::string s) : info(s) {}
};

#endif //PROJET_JOUEUR_H
