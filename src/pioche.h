#ifndef LO21_CARCASSONE_PIOCHE_H
#define LO21_CARCASSONE_PIOCHE_H

#include "tuile.h"

class Pioche {
private:
    const int nbTuilesMax;
    const int nbTuilesRiviereMax;
    std::list<Tuile> *tuiles_riviere;
    std::list<Tuile> *tuiles;
public:
    Pioche() = default;
    ~Pioche() = default;

    const Tuile& piocher();
    void genererTuiles();

    Pioche(const Pioche&) = delete;
    Pioche& operator=(const Pioche&) = delete;
};

#endif //LO21_CARCASSONE_PIOCHE_H
