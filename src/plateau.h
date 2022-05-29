#ifndef LO21_CARCASSONE_PLATEAU_H
#define LO21_CARCASSONE_PLATEAU_H

#include "tuile.h"
#include "groupement.h"
#include "pioche.h"
#include "joueur.h"

class Plateau {
private:
    static Plateau* instance;
    Plateau();
    Plateau(Plateau const&);
    void operator=(Plateau const&);
    virtual ~Plateau();

    int xmax = 0;
    int ymax = 0;
    Tuile*** plateau = nullptr;
    std::list<Groupement*> groupements = {};
public:
    static Plateau& getInstance();
    static void libereInstance();

    void etendrePlateau();
    Groupement* getGroupementWithElement(Element* e);
    Groupement* getGroupementWithMeeple(Meeple* m);
    void placerTuile(Tuile* tuile, int x, int y);
    Tuile** recupererVoisins(int x, int y);
    bool voisinsCompatibles(int x, int y, Tuile* tuile);
    int compterVoisins(int x, int y);
    Tuile getTuile(int x, int y) const { return *plateau[x][y]; }
    void attribuerPoint(Joueur* joueur, int nbPoints);
    void decalerTuiles();
};


#endif //LO21_CARCASSONE_PLATEAU_H
