#ifndef meeple_h
#define meeple_h

#include <stdio.h>

#include "enum.h"

class Joueur;

class Meeple{
    const meeple_type type;
    bool disponible;
    const Joueur* joueur;
public:
    const meeple_type getType() const {return type;}
    bool getDisponible() const {return disponible;}
    const Joueur* getJoueur() const {return joueur;}
    Meeple() = default;
    Meeple(const meeple_type& type, const bool& d): type(type),disponible(d),joueur(nullptr){}
    Meeple(const Meeple& m)=delete;
    Meeple& operator=(const Meeple& m)=delete;
    ~Meeple()=default;
    void updateMeeple(){
        if(getDisponible()==true) {
            disponible=false;
        }
        else {disponible = true;}
    }
};

#endif
