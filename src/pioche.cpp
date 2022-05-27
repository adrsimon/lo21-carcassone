#include <cstdlib>
#include <string>
#include <list>
#include "pioche.h"
#include "tuile.h"
#include "element.h"

#include "../utils/libraries/tinyxml2.h"

const Tuile &Pioche::piocher() {
    
}

using namespace tinyxml2;

void Pioche::genererTuiles() {
    // loading XML file
    XMLDocument main_tiles;
    main_tiles.LoadFile("../utils/tuiles-main.xml");
    XMLElement *root = main_tiles.FirstChildElement("tuiles");
    XMLElement *tuile = root->FirstChildElement("tuile");

    while (tuile != nullptr) {
        bool monastere = (tuile->FirstChildElement("M")->GetText() == "true");
        bool jardin = (tuile->FirstChildElement("J")->GetText() == "true");
        size_t id = atoi(tuile->Attribute("id"));
        list<Element> elements;

        int nbElements = 0;
        XMLElement *element = tuile->FirstChildElement("element");
        while (element != nullptr) {
            string type = element->FirstChildElement("type")->GetText();
            bool blason = (element->FirstChildElement("blason")->GetText() == "true");

            string orientations = element->FirstChildElement("orientation")->GetText();

            size_t nb_orientations;
            size_t orientation_size;
            if (type == "pre") {
                orientation_size = 2;
                nb_orientations = (orientations.length() + 1) / 3;
            } else {
                orientation_size = 1;
                nb_orientations = (orientations.length() + 1) / 2;
            }

            list<string> final_orientations;
            for (size_t i = 0; i < nb_orientations; i++) {
                string orientation = orientations.substr(i * (orientation_size + 1), orientation_size);
                final_orientations.push_back(orientation);
            }

            // creating the element
            Element *e = new Element(type, final_orientations, blason);
            elements.push_back(*e);
            nbElements++;
            element = element->NextSiblingElement("element");
        }

        tuiles->push_back(Tuile(monastere, jardin, id, elements));
        tuile = tuile->NextSiblingElement("tuile");
    }
}

