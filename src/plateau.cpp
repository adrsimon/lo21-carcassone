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
    // the goal of this function is to extend the plateau by 2 in both directions
    // the new plateau points to the same tiles as the old one
    // the void tiles are initialized as a nullptr
    // the old tiles are deleted
    // the new tiles are added to the list of tiles

    // first, we create the new array
    Tuile*** newPlateau = new Tuile**[xmax + 2];
    for (int i = 0; i < xmax + 2; i++) {
        newPlateau[i] = new Tuile*[ymax + 2];
    }

    // then, we copy the old array into the new one
    for (int i = 0; i < xmax; i++) {
        for (int j = 0; j < ymax; j++) {
            newPlateau[i + 1][j + 1] = plateau[i][j];
        }
    }

    // then, we initialize the new void tiles
    for (int i = 0; i < xmax + 2; i++) {
        for (int j = 0; j < ymax + 2; j++) {
            if (i == 0 || i == xmax + 1 || j == 0 || j == ymax + 1) {
                newPlateau[i][j] = nullptr;
            }
        }
    }

    // then, we delete the old array
    for (int i = 0; i < xmax; i++) {
        for (int j = 0; j < ymax; j++) {
            plateau[i][j]->~Tuile();
        }
    }

    for (int i = 0; i < xmax; i++) {
        delete[] plateau[i];
    }

    delete[] plateau;

    // then, we update the plateau
    plateau = newPlateau;
    xmax += 2;
    ymax += 2;
}

void Plateau::placerTuile(Tuile *tuile, int x, int y) {
    if (x >= xmax || y >= ymax || x <= -xmax || y <= -ymax) {
        etendrePlateau();
    }
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
        elems[i] = *it;
        i++;
    }
    return elems;
}

bool Plateau::voisinsCompatibles(Position p, Tuile* t) {
    for(auto it = t->getElement(); )
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

Groupement* Plateau::getGroupementWithElement(Element* e) {
    auto it = groupements.begin();
    while(it != groupements.end()) {
        if(std::find((*it)->getElements().begin(), (*it)->getElements().end(), e) != (*it)->getElements().end())
            return *it;
        it++;
    }
}

Groupement* Plateau::getGroupementWithMeeple(Meeple* m) {
    auto it = groupements.begin();
    while(it != groupements.end()) {
        if(std::find((*it)->getMeeples().begin(), (*it)->getMeeples().end(), m) != (*it)->getMeeples().end())
            return *it;
        it++;
    }

}