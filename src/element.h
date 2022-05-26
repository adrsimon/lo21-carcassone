#ifndef element_h
#define element_h

#include <iostream>
#include "groupement.h"
#include "position.h"

const std::list<std::string> orientation = {"N", "E", "S", "O"};
const std::list<std::string> orientationPre = { "ON", "NO", "NE", "EN", "ES", "SE", "SO", "OS"};

class Element {
private:
    bool hasMeeple;
    const std::string type;
    Groupement* groupement;
    std::string orientation;
    const bool blason;
public:
    std::string getOrientation() const {return orientation;}
    bool getBlason() const {return blason;}
    Groupement* getGroupement() const {return groupement;}
    std::string getType() const {return type;}
    void setPosition(const int& x,const int& y);
    void setGroupement(Groupement* grp);
    void setOrientation(const std::string orient) {orientation = orient;}

    Element(std::string type, std::string orientation, bool blason=false) :
        hasMeeple(false), type(type), groupement(NULL), orientation(orientation), blason(blason) { }
    ~Element()=default;
};

#endif
