#include "meeple.h"
#include "element.h"
#include "groupement.h"
#include <list>

int Groupement::getAllElementsPoints() {
    int sum=0;
    bool modifier;
    for(auto it = elements.begin(); it != elements.end(); it++) {
        if((*it)->hasModifier())
            modifier = true;
        sum+=(*it)->getElementPoints();
    }
    return sum * (modifier ? 2 : 1);
}

Groupement& Groupement::operator+(const Groupement& g){
    std::list<Element*> elems = g.getElements();
    for(auto it = elems.begin(); it != elems.end(); it++)
        elements.push_back(*it);
    std::list<Meeple*> meeples = g.getMeeples();
    for(auto it = meeples.begin(); it != meeples.end(); it++)
        meeples.push_back(*it);
    return *this;
}

Groupement &Groupement::operator=(const Groupement &g){
    elements.clear();
    std::list<Element*> elems = g.getElements();
    for(auto it = elems.begin(); it != elems.end(); it++)
        elements.push_back(*it);
    meeples.clear();
    std::list<Meeple*> meeples = g.getMeeples();
    for(auto it = meeples.begin(); it != meeples.end(); it++)
        meeples.push_back(*it);
    complete=g.complete;
    return *this;
}

bool Groupement::isFinished() {
    return false;
}