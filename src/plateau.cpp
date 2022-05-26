#include "plateau.h"
#include "joueur.h"

Plateau* Plateau::instance = nullptr;

Plateau& Plateau::donneInstance() {
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

void Plateau::etendrePlateau() {
    Tuile** nouveauPlateau = new Tuile*[xmax + 2];
    for (int i = 0; i < xmax + 2; i++) {
        nouveauPlateau[i] = *plateau[i];
    }
    for (int i = 0; i < xmax; i++) {
        for (int j = 0; j < ymax; j++) {
            nouveauPlateau[i][j] = plateau[i-1][j-1];
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
    Tuile* voisins;
    int i = 0;
    for (int j = -1; j < 2; j++) {
        for (int k = -1; k < 2; k++) {
            if (x + j >= 0 && x + j < xmax && y + k >= 0 && y + k < ymax) {
                voisins[i] = plateau[x + j][y + k];
                i++;
            }
        }
    }
    return &voisins;
}

bool Plateau::voisinsCompatibles(int x, int y, Tuile *tuile) {
    if ((tuile->getElement()[0] == plateau[x][y+1]->getElement()[2] || plateau[x][y+1] == nullptr)
        && (tuile->getElement()[1] == plateau[x+1][y]->getElement()[3] || plateau[x+1][y] == nullptr)
        && (tuile->getElement()[2] == plateau[x][y-1]->getElement()[0] || plateau[x][y-1] == nullptr)
        && (tuile->getElement()[3] == plateau[x-1][y]->getElement()[1] || plateau[x-1][y] == nullptr)) {
        return true;
    }
    return false;
}

// tester le nombre de cases non vides autour de la case x, y
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
                plateau[i][j]->getPosition()->setPosition(plateau[i][j]->getPosition()->getPositionX() + 1, plateau[i][j]->getPosition()->getPositionY() + 1);
            }
        }
    }
}
