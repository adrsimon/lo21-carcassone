#ifndef element_h
#define element_h

#include <iostream>
#include "groupement.h"
#include "position.h"

class Element {
private:
    bool hasMeeple;
    const std::string type;
    //Groupement* groupement;
    std::list<std::string> orientations;
    const bool blason;

public:
    // Getters
    std::list<std::string> getOrientations() const {return orientations;}
    bool getBlason() const {return blason;}
    //Groupement* getGroupement() const {return groupement;}
    std::string getType() const {return type;}
    // Setters
    //void setGroupement(Groupement* grp);
    // Others
    void rotateOrientation();

    Element(std::string type, std::list<std::string> orients, bool blason=false) :
            hasMeeple(false), type(type), orientations(orients), blason(blason) { }
    ~Element()=default;
};

#endif
