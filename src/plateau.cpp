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
        case TypeCardinaux::ouest: return getTuile(x, y-1);
        case TypeCardinaux::nord: return getTuile(x-1, y);
        case TypeCardinaux::sud: return getTuile(x+1, y);
        case TypeCardinaux::est: return getTuile(x, y+1);
        case TypeCardinaux::ouest_nord: return getTuile(x, y-1);
        case TypeCardinaux::ouest_sud: return getTuile(x, y-1);
        case TypeCardinaux::nord_est: return getTuile(x-1, y);
        case TypeCardinaux::nord_ouest: return getTuile(x-1, y);
        case TypeCardinaux::sud_est: return getTuile(x+1, y);
        case TypeCardinaux::sud_ouest: return getTuile(x+1, y);
        case TypeCardinaux::est_nord: return getTuile(x, y+1);
        case TypeCardinaux::est_sud: return getTuile(x, y+1);
    }
}

bool Plateau::isTuileCompatible(int x, int y, Tuile* t) {
    if(getTuile(x,y) != nullptr || getNullVoisins(x,y).size() == 4) return false;
    std::vector<TypeCardinaux::points> dir = {TypeCardinaux::nord, TypeCardinaux::est, TypeCardinaux::sud, TypeCardinaux::ouest};
    for (auto it = dir.begin();  it != dir.end() ; it++) {
        Tuile* voisin = getVoisinByOrientation(x,y, *it);
        Element* inverseElem = nullptr;
        Element* elemVoisin = t->getElementByOrientation(*it);
        if(voisin != nullptr) {
            inverseElem = voisin->getElementByOrientation(TypeCardinaux::getOrientationInverse(*it));
            if(inverseElem != nullptr && elemVoisin != nullptr) {
                if(inverseElem->getType() != elemVoisin->getType())
                    return false;
            } else if((inverseElem == nullptr && elemVoisin != nullptr) || (inverseElem != nullptr && elemVoisin == nullptr)){
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
    std::cout << "- Placage de la tuile sur le plateau (" << x << "," << y << ") -" << std::endl;
    for(auto it = elems.begin(); it != elems.end(); it++) {
        std::cout << "Ajout de l'élément " << TypeElement::toString((*it)->getType()) << " aux groupements" << std::endl;
        std::list<TypeCardinaux::points> dirs = (*it)->getOrientations();
        g = new Groupement((*it)->getType());
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
        groupements.push_back(g);
        g->addElement(*it);
    }
}

bool Plateau::isMeeplePlacable(Tuile* t, Element* e) {
    std::list<Element*> elems = t->getElements();
    for(auto it = elems.begin(); it != elems.end(); it++)
        if(getGroupementWithElement(*it)->getMeeples().empty())
            return true;
        return false;
}

void Plateau::placerMeeple(Tuile* t, Meeple* m, Element* e) {
    std::list<Element*> elems = t->getElements();
    for(auto it = elems.begin(); it != elems.end(); it++)
        if(!getGroupementWithElement(*it)->getMeeples().size())
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

std::vector<std::pair<int, int>> Plateau::getCasesLibres() {
    std::vector<std::pair<int, int>> casesLibres;
    for (auto caseOccupee : plateau)
        for (auto caseVide : getNullVoisins(caseOccupee.first.first, caseOccupee.first.second))
            casesLibres.push_back(caseVide);

    return casesLibres;
}

std::vector<std::pair<int,int>> Plateau::getNullVoisins(int x, int y) {
    std::vector<std::pair<int,int>> res;
    if (getTuile(x+1, y) == nullptr) res.push_back(std::pair<int,int>(x+1,y));
    if (getTuile(x-1, y) == nullptr) res.push_back(std::pair<int,int>(x-1,y));
    if (getTuile(x, y+1) == nullptr) res.push_back(std::pair<int,int>(x,y+1));
    if (getTuile(x, y-1) == nullptr) res.push_back(std::pair<int,int>(x,y-1));
    return res;
}

std::vector<std::pair<int,int>> Plateau::getSquaredNullVoisins(int x, int y) {
    std::vector<std::pair<int,int>> res;
    if (getTuile(x+1, y) == nullptr) res.push_back(std::pair<int,int>(x+1,y));
    if (getTuile(x-1, y) == nullptr) res.push_back(std::pair<int,int>(x-1,y));
    if (getTuile(x, y+1) == nullptr) res.push_back(std::pair<int,int>(x,y+1));
    if (getTuile(x, y-1) == nullptr) res.push_back(std::pair<int,int>(x,y-1));
    if (getTuile(x+1, y+1) == nullptr) res.push_back(std::pair<int,int>(x+1,y+1));
    if (getTuile(x-1, y+1) == nullptr) res.push_back(std::pair<int,int>(x-1,y+1));
    if (getTuile(x-1, y+1) == nullptr) res.push_back(std::pair<int,int>(x-1,y+1));
    if (getTuile(x-1, y-1) == nullptr) res.push_back(std::pair<int,int>(x-1,y-1));
    return res;
}


pair<int, int> Plateau::getTuileCoordinates(Tuile* t) {
    for(auto it = plateau.begin(); it != plateau.end(); it++) {
        if((*it).second == t)
            return (*it).first;
    }
}

Tuile* Plateau::getTuileWithElement(Element* e) {
    for(auto it = plateau.begin(); it != plateau.end(); it++) {
        std::list<Element*> elems = (*it).second->getElements();
        auto finded = std::find(elems.begin(), elems.end(), e);
        if(finded != elems.end())
            return (*it).second;
    }
    return nullptr;
}

std::list<Groupement*> Plateau::getGroupementsWithTuile(Tuile* t) {
    std::list<Groupement*> raws;
    std::list<Element*> elems = t->getElements();
    for(auto it = elems.begin(); it != elems.end(); it++)
        if(getGroupementWithElement(*it) != nullptr)
            raws.push_back(getGroupementWithElement(*it));

    return raws;
}

std::vector<std::pair<TypeElement::points, int>> Plateau::getSizeOfGroupements() {
    std::vector<std::pair<TypeElement::points, int>> raws;
    int ro=0; int v=0; int a=0; int ri=0; int j=0; int p=0;
    for(auto it = groupements.begin(); it != groupements.end(); it++) {
        if(!(*it)->isFinished()) {
            switch ((*it)->getType()) {
                case TypeElement::route:
                    ro++;
                    break;
                case TypeElement::ville:
                    v++;
                    break;
                case TypeElement::abbaye:
                    a++;
                    break;
                case TypeElement::riviere:
                    ri++;
                    break;
                case TypeElement::jardin:
                    j++;
                    break;
                case TypeElement::pre:
                    p++;
                    break;
            }
        }
    }
    raws.push_back(std::pair<TypeElement::points, int>(TypeElement::route, ro));
    raws.push_back(std::pair<TypeElement::points, int>(TypeElement::ville, v));
    raws.push_back(std::pair<TypeElement::points, int>(TypeElement::abbaye, a));
    raws.push_back(std::pair<TypeElement::points, int>(TypeElement::riviere, ri));
    raws.push_back(std::pair<TypeElement::points, int>(TypeElement::jardin, j));
    raws.push_back(std::pair<TypeElement::points, int>(TypeElement::pre, p));


    return raws;
}
void Plateau::checkGroupement(Groupement* g) {
    switch(g->getType()) {
        case TypeElement::route:
            checkRoute(g);
            break;
        case TypeElement::abbaye:
            checkAbbaye(g);
            break;
        case TypeElement::ville:
            checkVille(g);
        case TypeElement::pre:
            checkPre(g);
            break;
        case TypeElement::jardin:
            checkJardin(g);
            break;
        case TypeElement::riviere:
            break;
    }
}
// OLD VERSIONS CHECKING NEW ONE
/*
void Plateau::checkRoute(Groupement *g) {
    int count=0;
    std::list<Element*> elems = g->getElements();
    for(auto it = elems.begin(); it != elems.end(); it++)
        if((*it)->getOrientations().size() == 1)
            count ++;

        g->setComplete(count == 2);
}
*/

// MORE FLEXIBLE
void Plateau::checkRoute(Groupement *g) {
    std::list<Element*> elems = g->getElements();
    for(auto it = elems.begin(); it != elems.end(); it++) {
        Tuile* t = getTuileWithElement(*it);
        pair<int,int> cords = getTuileCoordinates(t);
        std::list<TypeCardinaux::points> cards = (*it)->getOrientations();
        for(auto it2 = cards.begin(); it2 != cards.end(); it2 ++) {
            if(getVoisinByOrientation(cords.first, cords.second, *it2) == nullptr)
                return;
        }
    }
    g->setComplete(true);
}

void Plateau::checkVille(Groupement *g) {
    std::list<Element*> elems = g->getElements();
    for(auto it = elems.begin(); it != elems.end(); it++) {
        Tuile* t = getTuileWithElement(*it);
        pair<int,int> cords = getTuileCoordinates(t);
        std::list<TypeCardinaux::points> cards = (*it)->getOrientations();
        for(auto it2 = cards.begin(); it2 != cards.end(); it2 ++) {
            if(getVoisinByOrientation(cords.first, cords.second, *it2) == nullptr)
                return;
        }
    }
    g->setComplete(true);
}

void Plateau::checkPre(Groupement* g) {

}
void Plateau::checkAbbaye(Groupement* g) {
    Tuile* t = getTuileWithElement(g->getElements().front());
    pair<int,int> cords = getTuileCoordinates(t);
    g->setComplete(getSquaredNullVoisins(cords.first, cords.second).size() == 8);
}
void Plateau::checkJardin(Groupement* g) {

}