#include "element.h"
#include "enum.h"


void Element::rotateOrientation() {
    std::list<TypeCardinaux::points> raw;
    for(auto it = orientations.begin(); it != orientations.end();  it++) {
        raw.push_back(TypeCardinaux::getNextOrientations(*it));
    }
    orientations = raw;
}