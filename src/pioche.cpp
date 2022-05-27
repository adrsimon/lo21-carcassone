#include <cstdlib>
#include <string>
#include <list>
#include "pioche.h"
#include "tuile.h"
#include "element.h"

#include "../utils/libraries/tinyxml2.h"

const Tuile &Pioche::piocher() {
    if (tuiles_riviere != nullptr) {
        int i;
        if (nbTuilesRiviere == nbTuilesRiviereMax) {
            i = 0;
        } else {
            i = std::rand() % sizeof tuiles_riviere;
        }
        const Tuile* tmp = &tuiles_riviere[i];
        tuiles_riviere[i] = tuiles_riviere[nbTuilesRiviere - 1];
        nbTuilesRiviere--;
        return *tmp;
    } else {
        int i = std::rand() % sizeof tuiles;
        const Tuile* tmp = &tuiles[i];
        tuiles[i] = tuiles[nbTuiles - 1];
        nbTuiles--;
        return *tmp;
    }
}

using namespace tinyxml2;

void Pioche::genererTuiles() {
    // loading XML file
    XMLDocument main_tiles;
    main_tiles.LoadFile("../utils/tuiles-main.xml");
    XMLElement *root = main_tiles.FirstChildElement("tuiles");
    XMLElement *tuile = root->FirstChildElement("tuile");

    // iterating through all tiles of the XML
    nbTuiles = 0;
    while (tuile != nullptr) {
        bool monastere = (tuile->Attribute("M") == "true");
        bool jardin = (tuile->Attribute("J") == "true");

        // iterating through all elements of the tile
        int nbElements = 0;
        XMLElement *element = tuile->FirstChildElement("element");
        while (element != nullptr) {
            string type = element->Attribute("type");
            bool blason = (element->Attribute("blason") == "true");

            // parsing the orientation of the element
            string orientations = element->Attribute("orientation");

            size_t nb_orientations;
            size_t orientation_size;
            if (type == "pre") {
                orientation_size = 2;
                nb_orientations = (orientations.length() + 1) / 3;
            } else {
                orientation_size = 1;
                nb_orientations = (orientations.length() + 1) / 2;
            }

            // we need to split orientations string into the final_orientations list
            list<string> final_orientations;
            for (size_t i = 0; i < nb_orientations; i++) {
                string orientation = orientations.substr(i * (orientation_size + 1), orientation_size);
                final_orientations.push_back(orientation);
            }

            // creating the element
            Element *e = new Element(); // waiting for the constructor to be implemented
            nbElements++;
            element = element->NextSiblingElement("element");
        }

        // creating the tile
        tuiles[nbTuiles] = Tuile(); // waiting for the constructor to be implemented
        nbTuiles++;
        tuile = tuile->NextSiblingElement("tuile");
    }
}

