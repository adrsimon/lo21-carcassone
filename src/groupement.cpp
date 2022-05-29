#include "enum.h"
#include "meeple.h"
#include "element.h"
#include "groupement.h"
#include <iostream>
#include <string>
#include <list>
#include <array>
#include <vector>

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
    for(Meeple* m : g.meeples){
        meeples.push_back(m);
    }
    for(Element* e : g.elements){
        elements.push_back(e);
    }
    g.~Groupement();
    return (*this);
}

Groupement &Groupement::operator=(const Groupement &g){
    meeples = g.meeples;
    elements = g.elements;
    complete=g.complete;
    g.~Groupement();
    return (*this);
}
