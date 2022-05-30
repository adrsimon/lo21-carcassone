#ifndef LO21_CARCASSONE_PLATEAU_H
#define LO21_CARCASSONE_PLATEAU_H

#include <map>

#include "tuile.h"
#include "groupement.h"
#include "pioche.h"
#include "joueur.h"

class Plateau {
private:

    // Singleton properties
    static Plateau* instance;
    Plateau();
    Plateau(Plateau const&);
    void operator=(Plateau const&);
    virtual ~Plateau();

    // Board and Groupements properties
    int orientationTuile=0;
    int idCurrentTuile;
    std::map<Position, Tuile*> plateau;
    std::list<Groupement*> groupements = {};
public:
    // Singleton methods
    static Plateau& getInstance();
    static void libereInstance();

    // Getters & Setters
    int const getOrientationTuile() { return orientationTuile; }
    int const getIdCurrentTuile() { return idCurrentTuile; }
    void setOrientationTuile(int o) { orientationTuile = 0; }
    void setIdCurrentTuile(int i) { idCurrentTuile = 0; }
    Tuile* getTuile(Position p) const { return plateau.at(p); }

    // Finders
    Groupement* getGroupementWithElement(Element* e);
    Groupement* getGroupementWithMeeple(Meeple* m);

    void placerTuile(Tuile* t, Position p) { plateau.insert(std::pair<Position, Tuile*>(p,t)); }
    //Tuile** recupererVoisins(int x, int y);
    bool voisinsCompatibles(Position p, Tuile* t);
    int compterVoisins(Position p);
};


#endif //LO21_CARCASSONE_PLATEAU_H
