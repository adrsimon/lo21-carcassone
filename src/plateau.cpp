#include "plateau.h"

// SINGLETON

Plateau* Plateau::instance = nullptr;

Plateau::Plateau() = default;

Plateau& Plateau::getInstance() {
    if (instance == nullptr) {
        instance = new Plateau();
    }
    return *instance;
}

void Plateau::libereInstance() {
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}

Plateau::~Plateau() {
    for (int i = 0; i < xmax; i++) {
        for (int j = 0; j < ymax; j++) {
            plateau[i][j]->~Tuile();
        }
    }
    for (int i = 0; i < xmax; i++) {
        delete[] plateau[i];
    }
    delete[] plateau;
}

// FONCTIONS SPECIFIQUES

void Plateau::etendrePlateau() {
    Tuile** nouveauPlateau = new Tuile*[xmax + 2];
    for (int i = 0; i < xmax + 2; i++) {
        nouveauPlateau[i] = *plateau[i];
    }
    for (int i = 0; i < xmax; i++) {
        for (int j = 0; j < ymax; j++) {
            nouveauPlateau[i][j] = Tuile(*plateau[i-1][j-1]);
        }
    }
    for (int i = 0; i < xmax + 1; i++) {
        delete[] plateau[i];
    }
    delete[] plateau;
    plateau = &nouveauPlateau;
    xmax++;
    ymax++;
    decalerTuiles();
}

void Plateau::placerTuile(Tuile *tuile, int x, int y) {
    plateau[x][y] = tuile;
}

Tuile** Plateau::recupererVoisins(int x, int y) {
    Tuile** voisins;
    int i = 0;
    for (int j = -1; j < 2; j++) {
        for (int k = -1; k < 2; k++) {
            if (x + j >= 0 && x + j < xmax && y + k >= 0 && y + k < ymax) {
                voisins[i] = plateau[x + j][y + k];
                i++;
            }
        }
    }
    return voisins;
}

Element* getElementAsTable(Tuile* tuile) {
    Element *elems;
    int i = 0;
    for (auto & it : tuile->getElement()) {
        elems[i] = it;
        i++;
    }
    return elems;
}

bool Plateau::voisinsCompatibles(int x, int y, Tuile *tuile) {
    Element* elems_tuile = getElementAsTable(tuile);
    if ((elems_tuile[0].getType() == getElementAsTable(plateau[x][y+1])[2].getType() || plateau[x][y+1] == nullptr)
        && (elems_tuile[1].getType() == getElementAsTable(plateau[x+1][y])[3].getType() || plateau[x+1][y] == nullptr)
        && (elems_tuile[2].getType() == getElementAsTable(plateau[x][y-1])[0].getType() || plateau[x][y-1] == nullptr)
        && (elems_tuile[3].getType() == getElementAsTable(plateau[x-1][y])[1].getType() || plateau[x-1][y] == nullptr)) {
        return true;
    }
    return false;
}

int Plateau::compterVoisins(int x, int y) {
    int count = 0;
    Tuile** voisins = recupererVoisins(x, y);
    for (int i = 0; i < 8; i++) {
        if (voisins[i] != nullptr) {
            count++;
        }
    }
    return count;
}

void Plateau::attribuerPoint(Joueur *joueur, int nbPoints) {
    joueur->setScore(joueur->getScore() + nbPoints);
}

void Plateau::decalerTuiles() {
    for (int i = xmax; i > 0; i--) {
        for (int j = ymax; j > 0; j--) {
            if (&plateau[i][j] != nullptr) {
                plateau[i][j]->getPosition().setPosition(plateau[i][j]->getPosition().getPositionX() + 1, plateau[i][j]->getPosition().getPositionY() + 1);
            }
        }
    }
}
