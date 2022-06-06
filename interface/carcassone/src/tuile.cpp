#include "tuile.h"
#include "element.h"
#include <list>

void Tuile::rotateOrientation() {
    for (Element* i : elements){
        i->rotateOrientation();
    }
}

Tuile &Tuile::operator=(const Tuile &j) {
    // copy the element list of j into the element list of *this
    elements = j.elements;
    return *this;
}

Element* Tuile::getElementByOrientation(TypeCardinaux::points t) {
    for (auto it = elements.begin(); it != elements.end(); it++) {
        auto orients = (*it)->getOrientations();
        auto raw = std::find(orients.begin(), orients.end(), t);
        if(raw != orients.end())
            return *it;
    }
    return nullptr;
}

std::list<Element*> Tuile::getElementByType(TypeElement e) {
    std::list<Element*> raws;
    for (auto it = elements.begin(); it != elements.end(); it++) {
        if((*it)->getType() == e)
            raws.push_back(*it);
    }
    return raws;
}

