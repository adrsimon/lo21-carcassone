#include "groupement.h"
#include "element.h"
#import "meeple.h"

Groupement& Groupement::operator=(const Groupement& g){
    Meeple** newliste=new Meeple*[g.dim_l];
    for(unsigned int i=0; i<g.dim_l;i++) newliste[i]=g.liste[i];
    Meeple** old=liste;
    liste=newliste;
    dim_l=g.dim_l;
    delete[] old;

    Element* newel=new Element[g.dim_e];
    for(unsigned int i=0; i<g.dim_e;i++) newel[i]=g.element[i];
    Element* oldEl=element;
    element=newel;
    dim_e=g.dim_e;
    delete[] old;

    return *this;
}
