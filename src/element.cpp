#include "element.h"

void Element::setPosition(const int& x,const int& y){
    position.x=x;
    position.y=y;
}
void Element::setGroupement(Groupement* grp){
    groupement=grp; 
}

void Element::setOrientation(const Orientation* o){
    orientation=o;
}
