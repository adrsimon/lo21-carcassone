//
//  Element.cpp
//  
//
//  Created by Claire Louard on 01/05/2022.
//

#include "Element.hpp"

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
