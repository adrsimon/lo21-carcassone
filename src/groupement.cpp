#include "enum.h"
#include "meeple.h"
#include "element.h"
#include "groupement.h"
#include <iostream>
#include <string>
#include <list>
#include <array>
#include <vector>

Groupement& Groupement::operator+(const Groupement& g){
    for(Meeple* m : g.meeples){
        meeples.push_back(m);
    }
    for(Element* e : g.element){
        element.push_back(e);
    }
    this->type=g.type;
    this->complete=g.complete;
    this->points+=g.points;
    g.~Groupement();
    return (*this);
}

Groupement &Groupement::operator=(const Groupement &g){
    for(Meeple* m : g.meeples){
        meeples.push_back(m);
    }
    for(Element* e : g.element){
        element.push_back(e);
    }
    this->type=g.type;
    this->complete=g.complete;
    this->points=g.points;
    g.~Groupement();
    return (*this);
}
