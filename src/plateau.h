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
    virtual ~Plateau() {};

    // Board and Groupements properties
    int orientationTuile=0;
    int idCurrentTuile;
    std::map<pair<int,int>, Tuile*> plateau;
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
    Tuile* getTuile(int x, int y) const { return plateau.at(pair<int,int>(x,y)); }
    std::vector<Tuile*> getVoisins(int x, int y);

    // Finders
    Groupement* getGroupementWithElement(Element* e);
    Groupement* getGroupementWithMeeple(Meeple* m);

    void placerTuile(Tuile* t, int x, int y) { plateau.insert(pair<pair<int,int>, Tuile*>(pair<int,int>(x,y),t)); }
    //Tuile** recupererVoisins(int x, int y);
    bool voisinsCompatibles(int x, int y, Tuile* t);
    int compterVoisins(int x, int y) { return getVoisins(x,y).size(); }
};


#endif //LO21_CARCASSONE_PLATEAU_H
