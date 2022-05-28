#include "enum.h"
#include "meeple.h"
#include "element.h"
#include "groupement.h"
#include <iostream>
#include <string>
#include <list>
#include <array>
#include <vector>

/*
     Groupement& Groupement::operator+(const Groupement& g){
         for (unsigned int i = 0; i < (g.meeples).size(); i++) { (this->meeples).push_back(g.meeples[i]); }
        for(unsigned int i=0; i<(g.element).size();i++) {(this->element).push_back(g.element[i]);}
        this->type=g.type;
        this->complete=g.complete;
        this->points+=g.points;
        g.~Groupement();
        return (*this);
    }
*/