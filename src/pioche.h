#ifndef LO21_CARCASSONE_PIOCHE_H
#define LO21_CARCASSONE_PIOCHE_H

#include <vector>
#include "tuile.h"

class Pioche {
public:
    static Pioche& getInstance();
    static void libereInstance();

    std::vector<Tuile*> getTuiles() const {
        return tuiles;
    }

    Tuile* piocher();
    void genererTuiles();
private:
    static Pioche* instance;
    Pioche() : nbTuilesMax(0), nbTuilesRiviereMax(0), tuiles(std::vector<Tuile*>()), tuiles_riviere(std::vector<Tuile*>()) {};
    Pioche(Pioche const&);
    void operator=(Pioche const&);
    virtual ~Pioche();

    const int nbTuilesMax;
    const int nbTuilesRiviereMax;
    std::vector<Tuile*> tuiles_riviere;
    std::vector<Tuile*> tuiles;
};

#endif //LO21_CARCASSONE_PIOCHE_H
