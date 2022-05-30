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

Tuile* Pioche::piocher() {
    if (!tuiles.empty()) {
        srand(time(NULL));
        int random = rand() % tuiles.size();
        Tuile* selected = tuiles[random];
        tuiles.erase(tuiles.begin() + random);
        return selected;
    }
}

using namespace tinyxml2;

Element* parseElem(XMLNode* element) {
    std::string type = element->FirstChildElement("type")->GetText();;

    Element *e;

    // elements sans orientations
    if (type == "jardin") {
        e = new ElementJardin();
        return e;
    } else if (type == "abbaye") {
        e = new ElementAbbaye();
        return e;
    } else { // elements avec orientations
        // parsing des orientations
        size_t nb_orientations;
        size_t orientation_size;
        std::string orientations = element->FirstChildElement("orientation")->GetText();
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
        if (type == "ville") {
            bool blason, cathedrale;

            if (element->FirstChildElement("blason") != nullptr) {
                blason = true;
            } else {
                blason = false;
            }

            if (element->FirstChildElement("cathedrale") != nullptr) {
                cathedrale = true;
            } else {
                cathedrale = false;
            }

            e = new ElementVille(final_orientations, blason, cathedrale);
            return e;
        } else if (type == "chemin") {
            bool auberge;
            if (element->FirstChildElement("auberge") != nullptr) {
                auberge = strcmp(element->FirstChildElement("auberge")->GetText(), "true") == 0;
            } else {
                auberge = false;
            }
            e = new ElementRoute(final_orientations, auberge);
            return e;
        } else if (type == "pre") {
            e = new ElementPre(final_orientations);
            return e;
        } else if (type == "riviere") {
            e = new ElementRiviere(final_orientations);
            return e;
        } else {
            std::cout << "Erreur : type d'element inconnu" << std::endl;
        }
    }
}

void Pioche::genererTuiles() {
    // loading XML file
    XMLDocument main_tiles;
    main_tiles.LoadFile("../utils/tuiles-main.xml");
    XMLElement *root = main_tiles.FirstChildElement("tuiles");
    XMLElement *tuile = root->FirstChildElement("tuile");

    while (tuile != nullptr) {
        int tuile_id = atoi(tuile->Attribute("id"));

        std::list<Element*> elements;
        XMLElement *element = tuile->FirstChildElement("element");
        while (element != nullptr) {
            Element *e = parseElem(element);
            // creating the element
            elements.push_back(e);
            element = element->NextSiblingElement("element");
        }
        // creating the tuile
        Tuile  *t = new Tuile(tuile_id, elements);
        tuiles.push_back(t);
        tuile = tuile->NextSiblingElement("tuile");
    }
}
