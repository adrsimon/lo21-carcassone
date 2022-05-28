#ifndef element_h
#define element_h

#include <iostream>
#include <list>
#include "position.h"

class Element {
private:
    bool hasMeeple;
    std::string type;
    std::list<std::string> orientations;
    bool blason;

public:
    // Getters
    std::list<std::string> getOrientations() const {return orientations;}
    bool getBlason() const {return blason;}
    std::string getType() const {return type;}
    void rotateOrientation();

    Element(std::string type, std::list<std::string> orients, bool blason=false) :
            hasMeeple(false), type(type), orientations(orients), blason(blason) { }
    ~Element()=default;
};

#endif
