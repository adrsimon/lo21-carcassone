#ifndef groupement_h
#define groupement_h

#include <iostream>
#include <string>
#include <list>
#include "enum.h"
#include "meeple.h"
#include "element.h"

class Groupement {
private:
    std::list<Meeple *> meeples; // Liste de meeples
    std::list<Element *> elements;
    TypeElement typeGroupement;
    bool complete = false;

public:
    Groupement(TypeElement t) {
        typeGroupement = t;
    }
    virtual ~Groupement() = default;

    // Getters
    std::list<Meeple *> getMeeples() const { return meeples; }
    TypeElement const getType() { return typeGroupement; }
    bool isComplete() { return complete; }
    std::list<Element *> getElements() const { return elements; }
    int getAllElementsPoints();

    // Checkers
    bool isTypeOf(Element* e) { return e->getType() == typeGroupement; }

    // Setters
    void setComplete() {complete = true;}

    // add and remove Elements and Meeples
    void addMeeple(Meeple* m) { meeples.push_back(m); }
    void addElement(Element* e) { elements.push_back(e); }
    void removeMeeple(Meeple* m) { meeples.remove(m); }
    void removeElement(Element* e) { elements.remove(e); }

    // Operators overloading
    Groupement &operator=(const Groupement &g);
    Groupement &operator+(const Groupement &g);
};

/*
 * i
 */
#endif