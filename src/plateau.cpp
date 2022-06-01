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
        case TypeCardinaux::sud_est: return getTuile(x, y-1);
        case TypeCardinaux::sud_ouest: return getTuile(x, y-1);
        case TypeCardinaux::est_nord: return getTuile(x+1, y);
        case TypeCardinaux::est_sud: return getTuile(x+1, y);
        case TypeCardinaux::ouest_nord: return getTuile(x-1, y);
        case TypeCardinaux::ouest_sud: return getTuile(x-1, y);
        case TypeCardinaux::nord_ouest: return getTuile(x, y+1);
        case TypeCardinaux::nord_est: return getTuile(x, y+1);
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
    for(auto it = groupements.begin(); it != groupements.end(); it++) {
        std::list<Element*> elements = (*it)->getElements();
        if(std::find(elements.begin(), elements.end(), e) != elements.end())
            return *it;
    }
    return nullptr;
}

Groupement* Plateau::getGroupementWithMeeple(Meeple* m) {
    for(auto it = groupements.begin(); it != groupements.end(); it++) {
        std::list<Meeple*> meeples = (*it)->getMeeples();
        if(std::find(meeples.begin(), meeples.end(), m) != meeples.end())
            return *it;
    }
    return nullptr;
}

void Plateau::placerTuile(Tuile* t, int x, int y) {
    plateau.insert(pair<pair<int,int>, Tuile*>(pair<int,int>(x,y),t));
    std::vector<Tuile*> voisins = getVoisins(x, y);
    std::list<Element*> elems = t->getElements();
    Groupement* g;
    for(auto it = elems.begin(); it != elems.end(); it++) {
        std::list<TypeCardinaux::points> dirs = (*it)->getOrientations();
        g = new Groupement((*it)->getType());
        if (dirs.size() > 1) {
            Tuile* voisin;
            for (auto it2 = dirs.begin(); it2 != dirs.end(); it2++) {
                voisin = getVoisinByOrientation(x, y, *it2);
                if(voisin != nullptr) {
                    Groupement *toAdd = getGroupementWithElement(voisin->getElementByOrientation(TypeCardinaux::getOrientationInverse(*it2)));
                    if(toAdd != nullptr) {
                        *g + *toAdd;
                        groupements.remove(toAdd);
                        delete toAdd;
                    }
                }
            }
        }
        groupements.push_back(g);
        g->addElement(*it);
    }
}

bool Plateau::isMeeplePlacable(Tuile* t) {
    std::list<Element*> elems = t->getElements();
    for(auto it = elems.begin(); it != elems.end(); it++)
        if(getGroupementWithElement(*it)->getMeeples().empty())
            return true;
        return false;
}

void Plateau::placerMeeple(Tuile* t, Meeple* m, TypeElement type) {
    std::list<Element*> elems = t->getElements();
    for(auto it = elems.begin(); it != elems.end(); it++)
        if(getGroupementWithElement(*it)->getType() == type)
            getGroupementWithElement(*it)->addMeeple(m);
}

int Plateau::evaluerGroupement(Groupement* g) {
    std::list<Element*> elems = g->getElements();
    bool modifier;
    int sum=0;
    for(auto it = elems.begin(); it != elems.end(); it++) {
        sum+=(*it)->getElementPoints();
        if((*it)->hasModifier()) modifier=true;
    }
    return sum * (modifier ? 2 : 1);
}

std::vector<std::pair<int,int>> Plateau::getNullVoisins(int x, int y) {
    std::vector<std::pair<int,int>> res;
    if (getTuile(x+1, y) == nullptr) res.push_back(std::pair<int,int>(x+1,y));
    if (getTuile(x-1, y) == nullptr) res.push_back(std::pair<int,int>(x-1,y));
    if (getTuile(x, y+1) == nullptr) res.push_back(std::pair<int,int>(x,y+1));
    if (getTuile(x, y-1) == nullptr) res.push_back(std::pair<int,int>(x,y-1));
    return res;
}
