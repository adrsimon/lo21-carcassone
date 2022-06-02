#ifndef tuile_h
#define tuile_h
#include <string>
#include <list>
#include "element.h"

class Tuile {
private:
    const int ID;
    std::list <Element*> elements;
public:
    Tuile(const int &id, std::list<Element*> e): elements(e), ID(id) {}
    ~Tuile() = default;
    Tuile(const Tuile& j)=default;
    Tuile& operator=(const Tuile& j);
    void rotateOrientation();
    std::string getIllustation() const {
        std::string path = "../utils/tiles_illustrations/" + std::to_string(ID) + ".jpeg";
        return path;
    }

    std::list<Element*> getElements() const {
        return elements;
    }

    Element* getElementByOrientation(TypeCardinaux::points t);
    std::list<Element*> getElementByType(TypeElement e);

    int getID() const {
        return ID;
    }

};

#endif