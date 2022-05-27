#include "groupement.h"
#include "element.h"
#import "meeple.h"

Groupement& Groupement::operator=(const Groupement& g){
    Meeple** newliste=new Meeple*[sizeof(g.meeples)];
    for(unsigned int i=0; i<sizeof(g.meeples);i++) newliste[i]=g.meeples[i];
    Meeple** old=meeples;
    meeples=newliste;
    sizeof(meeples)=sizeof(g.meeples);
    delete[] old;

    Element* newel=new Element[sizeof(g.element)];
    for(unsigned int i=0; i<sizeof(g.element);i++) newel[i]=g.element[i];
    Element* oldEl=element;
    element=newel;
    sizeof(element)=sizeof(g.element);
    delete[] old;
    return *this;
}

    virtual Groupement& Groupement::operator+(const Groupement& g){
        for(unsigned int i=0; i<sizeof(g.meeples);i++) (this->meeples).push_back(g.meeples[i]);
        for(unsigned int i=0; i<sizeof(g.element);i++) (this->element).push_back(g.element[i]);
        this->type=g.type;
        this->complete=g.complete;
        this->points+=g.points;
        g.~Groupement();
        return (*this);
    }
