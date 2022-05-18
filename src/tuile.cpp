#include "tuile.h"
#include "element.h"

Tuile::Tuile(int &nb, bool &m, bool &j, int &id) {
    nombreElement = nb;
    hasMonastere = m;
    hasJardin = j;
    position = Position (-1,-1);
    liste = new Element* [nb];
}

void Tuile::changeOrientation(orientation* nouvOrient)
{
    for (int i =0; i<nombreElement; i++){
        liste[i]->setOrientation(nouvOrient);
    }
}
void Tuile::updatePosition(const int& x, const int& y){
    position.setPosition(x, y);
    for (int i =0; i < nombreElement; i++){
        liste[i]->setPosition(x, y);
    }
}

Position* Tuile::getPosition() {
    return &position;
}

Tuile::Tuile(Tuile *pTuile) {
    nombreElement = pTuile->nombreElement;
    hasMonastere = pTuile->hasMonastere;
    hasJardin = pTuile->hasJardin;
    position = pTuile->position;
    liste = new Element* [nombreElement];
    for (int i =0; i<nombreElement; i++){
        liste[i] = pTuile->liste[i];
    }
}

