#include "element.h"

const std::list<std::string> orientationPrincipale = {"N", "E", "S", "O"};
const std::list<std::string> orientationPre = { "ON", "NO", "NE", "EN", "ES", "SE", "SO", "OS"};


void Element::rotateOrientation() {
    // Creating raw of new orientations
    std::list<std::string> raw;
    if(type == "Pré") {
        for(auto it = orientations.begin(); it != orientations.end();  ++it) {
            auto finded = std::find(orientationPre.begin(), orientationPre.end(), *it);
            if(finded == std::prev(orientationPre.end()))
                raw.push_back(*(std::next(orientationPre.begin())));
            else if(finded == std::prev(orientationPre.end(),2))
                raw.push_back(*(orientationPre.begin()));
            else
                raw.push_back(*(std::next(finded,2)));
        }
    } else {
        for(auto it = orientations.begin(); it != orientations.end();  it++) {
            auto finded = std::find(orientationPrincipale.begin(), orientationPrincipale.end(), *it);
            if(finded == std::prev(orientationPrincipale.end()))
                raw.push_back(*(orientationPrincipale.begin()));
            else
                raw.push_back(*(std::next(finded)));
        }
    }
    orientations = raw;
}

