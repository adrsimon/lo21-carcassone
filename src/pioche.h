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
    std::vector<Tuile*> getTuilesRiviere() const {
        return tuiles_riviere;
    }

    Tuile* piocher();
    void genererTuiles(std::list<TypeExtension::points> extensions = {TypeExtension::main});
private:
    static Pioche* instance;
    Pioche() : nbTuilesMax(0), nbTuilesRiviereMax(0), tuiles(std::vector<Tuile*>()), tuiles_riviere(std::vector<Tuile*>()) {};
    Pioche(Pioche const&);
    void operator=(Pioche const&);
    virtual ~Pioche();

    int nbTuilesMax = 0;
    int nbTuilesRiviereMax = 0;
    std::vector<Tuile*> tuiles_riviere;
    std::vector<Tuile*> tuiles;
};

#endif //LO21_CARCASSONE_PIOCHE_H
