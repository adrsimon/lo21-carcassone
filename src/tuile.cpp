#include "tuile.h"
#include "element.h"
#include <list>

void Tuile::setOrientation()
{
    for (Element i : elements){
        i.rotateOrientation();
    }
}

Tuile &Tuile::operator=(const Tuile &j) {
    hasJardin = j.hasJardin;
    hasMonastere = j.hasMonastere;
    position = j.position;
    elements = j.elements;
}

/*
Tuile::Tuile(Tuile *pTuile) {
    hasMonastere = pTuile->hasMonastere;
    hasJardin = pTuile->hasJardin;
    position = pTuile->position;
    liste = new Element* [nombreElement];
    for (int i =0; i<nombreElement; i++){
        liste[i] = pTuile->liste[i];
    }
}
*/
