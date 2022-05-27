#ifndef LO21_CARCASSONE_PIOCHE_H
#define LO21_CARCASSONE_PIOCHE_H

#include "tuile.h"

class Pioche {
public:
    static Pioche& getInstance();
    static void libereInstance();

    std::list<Tuile> *getTuiles() const {
        return tuiles;
    }

    // const Tuile& piocher();
    void genererTuiles();
private:
    static Pioche* instance;
    Pioche() : nbTuilesMax(0), nbTuilesRiviereMax(0), tuiles(nullptr), tuiles_riviere(nullptr) {};
    Pioche(Pioche const&);
    void operator=(Pioche const&);
    virtual ~Pioche();

    const int nbTuilesMax;
    const int nbTuilesRiviereMax;
    std::list<Tuile> *tuiles_riviere;
    std::list<Tuile> *tuiles;
};

#endif //LO21_CARCASSONE_PIOCHE_H
