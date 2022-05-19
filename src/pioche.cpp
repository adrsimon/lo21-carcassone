#include <cstdlib>
#include "pioche.h"
#include "tuile.h"

const Tuile &Pioche::piocher() {
    if (tuiles_riviere != nullptr) {
        int i;
        if (nbTuilesRiviere == nbTuilesRiviereMax) {
            i = 0;
        } else {
            i = std::rand() % sizeof tuiles_riviere;
        }
        const Tuile* tmp = &tuiles_riviere[i];
        tuiles_riviere[i] = tuiles_riviere[nbTuilesRiviere - 1];
        nbTuilesRiviere--;
        return *tmp;
    } else {
        int i = std::rand() % sizeof tuiles;
        const Tuile* tmp = &tuiles[i];
        tuiles[i] = tuiles[nbTuiles - 1];
        nbTuiles--;
        return *tmp;
    }
}

void Pioche::genererTuiles() {
    // besoin de générer les tuiles depuis un fichier json
    // - d'abord, on génère les tuiles de rivière, on les affecte a la pioche de rivière
    // - ensuite on genère les autres et on les affecte a la pioche classique
}

