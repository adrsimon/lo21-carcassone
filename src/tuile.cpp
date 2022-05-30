#include "tuile.h"
#include "element.h"
#include <list>

void Tuile::setOrientation()
{
    for (Element* i : elements){
        i->rotateOrientation();
    }
}

Tuile &Tuile::operator=(const Tuile &j) {
    // copy the element list of j into the element list of *this
    elements = j.elements;
    return *this;
}

