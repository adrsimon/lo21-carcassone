#ifndef meeple_h
#define meeple_h

#include <string>

#include "enum.h"

class Joueur;

class Meeple{
    std::string type;
    bool disponible;
    const Joueur* joueur;
public:
    const std::string getType() const {return type;}
    bool getDisponible() const {return disponible;}
    const Joueur* getJoueur() const {return joueur;}
    Meeple() = default;
    Meeple(const std::string& type, const bool& d): type(type),disponible(d),joueur(nullptr){}
    Meeple(const Meeple& m)=default;
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
