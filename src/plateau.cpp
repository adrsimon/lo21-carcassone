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
Tuile* Plateau::getTuile(int x, int y) {
    auto tuile = plateau.find(pair<int,int>(x,y));
    if(tuile == plateau.end())
        return nullptr;
    else return tuile->second;
}

std::vector<Tuile*> Plateau::getVoisins(int x, int y) {
    std::vector<Tuile*> raw;
    raw.push_back(getTuile(x+1, y));
    raw.push_back(getTuile(x-1, y));
    raw.push_back(getTuile(x, y+1));
    raw.push_back(getTuile(x, y-1));
    return raw;
}

Tuile* Plateau::getVoisinByOrientation(int x, int y, TypeCardinaux::points t) {
    switch(t) {
        case TypeCardinaux::sud: return getTuile(x, y-1);
        case TypeCardinaux::est: return getTuile(x+1, y);
        case TypeCardinaux::ouest: return getTuile(x-1, y);
        case TypeCardinaux::nord: return getTuile(x, y+1);
    }
}

bool Plateau::isTuileCompatible(int x, int y, Tuile* t) {
    if(getTuile(x,y) != nullptr) return false;
    std::vector<TypeCardinaux::points> dir = {TypeCardinaux::nord, TypeCardinaux::est, TypeCardinaux::sud, TypeCardinaux::ouest};
    for (auto it = dir.begin();  it != dir.end() ; it++) {
        Tuile* voisin = getVoisinByOrientation(x,y, *it);
        Element* inverseElem = nullptr;
        if(voisin != nullptr) {
            inverseElem = voisin->getElementByOrientation(TypeCardinaux::getOrientationInverse(*it));
            if(inverseElem != nullptr) {
                if(inverseElem->getType() != t->getElementByOrientation(*it)->getType())
                    return false;
            } else {
                if( t->getElementByOrientation(*it) != nullptr)
                    return false;
            }
        }
    }
    return true;
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