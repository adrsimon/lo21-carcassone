#ifndef LO21_CARCASSONE_PLATEAU_H
#define LO21_CARCASSONE_PLATEAU_H

#include <map>
#include <utility>

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
    std::map<std::pair<int,int>, Tuile*> plateau;
    std::list<Groupement*> groupements = {};

    void checkRoute(Groupement* g);
    void checkVille(Groupement* g);
    void checkPre(Groupement* g);
    void checkAbbaye(Groupement* g);
    void checkJardin(Groupement* g);

public:
    // Singleton methods
    static Plateau& getInstance();
    static void libereInstance();

    // Getters & Setters
    std::map<std::pair<int,int>, Tuile*> getMap() {return plateau;};
    Tuile* getTuile(int x, int y);
    std::vector<Tuile*> getVoisins(int x, int y);
    std::vector<std::pair<int,int>> getNullVoisins(int x, int y);
    std::vector<std::pair<int,int>> getSquaredNullVoisins(int x, int y);
    Tuile* getVoisinByOrientation(int x, int y, TypeCardinaux::points t);

    // Finders
    std::pair<int, int> getTuileCoordinates(Tuile* t);
    Tuile* getTuileWithElement(Element* e);
    std::list<Groupement*> getGroupementsWithTuile(Tuile* t);
    Groupement* getGroupementWithElement(Element* e);
    Groupement* getGroupementWithMeeple(Meeple* m);
    std::list<Groupement*> getGroupements() { return groupements; }
    std::vector<std::pair<TypeElement::points, int>> getSizeOfGroupements();

    std::vector<std::pair<int, int>> getCasesLibres();

    bool isTuileCompatible(int x, int y, Tuile* t);
    void placerTuile(Tuile* t, int x, int y);

    bool isMeeplePlacable(Tuile* t, Element* e);
    void placerMeeple(Tuile* t, Meeple* m, Element* e);

    void checkGroupement(Groupement* g);
    int evaluerGroupement(Groupement* g);

    int compterVoisins(int x, int y) { return getVoisins(x,y).size(); }
};


#endif //LO21_CARCASSONE_PLATEAU_H
