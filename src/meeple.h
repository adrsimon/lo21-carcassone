#ifndef meeple_h
#define meeple_h

#include <stdio.h>

enum meeple_type{Normal, Abbe, Big};

class Meeple{
    meeple_type type;
    bool disponible;
public:
    meeple_type getType() const {return type;}
    bool getDisponible() const {return disponible;}
    Meeple() = default;
    Meeple(const meeple_type& type, const bool& d): type(type),disponible(d){}
    void updateMeeple(){
        if(getDisponible()==true) {
            disponible=false;
        }
        else {disponible = true;}
    }
};

#endif