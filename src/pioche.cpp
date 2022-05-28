#include <random>
#include <string>
#include <list>
#include "pioche.h"
#include "tuile.h"
#include "element.h"

#include "../utils/libraries/tinyxml2.h"


Pioche* Pioche::instance = nullptr;

Pioche &Pioche::getInstance() {
    if (nullptr == instance) {
        instance = new Pioche();
    }
    return *instance;
}

void Pioche::libereInstance() {
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}

Pioche::~Pioche() = default;


Tuile Pioche::piocher() {
    if (!tuiles.empty()) {
        srand(time(NULL));
        int random = rand() % tuiles.size();
        Tuile selected = tuiles[random];
        tuiles.erase(tuiles.begin() + random);
        return selected;
    }
}

using namespace tinyxml2;

void Pioche::genererTuiles() {
    // loading XML file
    XMLDocument main_tiles;
    main_tiles.LoadFile("../utils/tuiles-main.xml");
    XMLElement *root = main_tiles.FirstChildElement("tuiles");
    XMLElement *tuile = root->FirstChildElement("tuile");

    while (tuile != nullptr) {
        bool monastere = (strcmp(tuile->FirstChildElement("M")->GetText(), "true")) == 0;
        bool jardin = (strcmp(tuile->FirstChildElement("J")->GetText(), "true")) == 0;
        int tuile_id = atoi(tuile->Attribute("id"));
        std::list<Element> elements;

        int nbElements = 0;
        XMLElement *element = tuile->FirstChildElement("element");
        while (element != nullptr) {
            std::string type = element->FirstChildElement("type")->GetText();
            bool blason = (strcmp(element->FirstChildElement("blason")->GetText(), "true")) == 0;

            std::string orientations = element->FirstChildElement("orientation")->GetText();

            size_t nb_orientations;
            size_t orientation_size;
            if (type == "pre") {
                orientation_size = 2;
                nb_orientations = (orientations.length() + 1) / 3;
            } else {
                orientation_size = 1;
                nb_orientations = (orientations.length() + 1) / 2;
            }

            std::list<std::string> final_orientations;
            for (size_t i = 0; i < nb_orientations; i++) {
                std::string orientation = orientations.substr(i * (orientation_size + 1), orientation_size);
                final_orientations.push_back(orientation);
            }

            // creating the element
            Element *e = new Element(type, final_orientations, blason);
            elements.push_back(*e);
            nbElements++;
            element = element->NextSiblingElement("element");
        }

        // creating the tuile
        Tuile  *t = new Tuile(monastere, jardin, tuile_id, elements);
        tuiles.push_back(*t);
        tuile = tuile->NextSiblingElement("tuile");
    }
}
