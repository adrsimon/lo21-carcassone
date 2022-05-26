#ifndef element_h
#define element_h

#include <iostream>
#include "groupement.h"
#include "position.h"


enum class Orientation{N,S,O,E};

//trouver une solution pour l'orientation -> créer nouvelle fonction pour l'orientation
class Element{
public:
    Orientation* getOrientation() const {return orientation;}
    Position getPosition() const {return position;}
    bool getBlason() const {return blason;}
    Groupement* getGroupement() const {return groupement;}
    types getType() const {return type;}
    void setPosition(const int& x,const int& y);
    void setGroupement(Groupement* grp);
    void setOrientation(orientation* orient) {orientation = orient;}

    //Constructeur : lors de la construction d'un élémnent celui-ci n'a pas encore de position sur le plateau
    Element(const types& t, Groupement* grp, bool b=false) : hasMeeple(false), type(t), groupement(grp), orientation(NULL), blason(b){
        position.setPosition(-1,-1);
    }
    ~Element(){delete[] orientation;}
    //Element(const Element& e);
    //Element& operator=(const Element& e);
private:
    bool hasMeeple;
    types type; //même type énuméré que dans classe groupement
    Groupement* groupement;
    Orientation orientation;
    Position position;
    bool blason;
};

#endif
