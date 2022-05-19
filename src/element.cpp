#include "element.h"
#include "groupement.h"

void Element::setPosition(const int& x,const int& y){
    position.setPosition(x,y);
}

void Element::setGroupement(Groupement* grp){
    groupement=grp; 
}
