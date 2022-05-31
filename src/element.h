#ifndef element_h
#define element_h

#include <iostream>
#include <list>
#include "enum.h"

class Element {
private:
    bool hasMeeple;

protected:
    std::list<TypeCardinaux::points> orientations;
    Element(std::list<TypeCardinaux::points> orients = {}) :
            hasMeeple(false), orientations(orients){ }

public:
    // Getters
    std::list<TypeCardinaux::points> getOrientations() const {return orientations;}
    bool const isMeeple() { return hasMeeple; }
    virtual const int getElementPoints() { return -1; };
    virtual bool const hasModifier() { return false; }
    virtual TypeElement getType() { return TypeElement::last; }
    // Setters
    void setMeeple(const bool b) { hasMeeple=b; }
    // Others
    virtual void rotateOrientation();
    ~Element()=default;
};

// 2 Points + 2 points si blason
class ElementVille : public Element {
private:
    bool blason;
    bool cathedrale;
public:
    ElementVille(std::list<TypeCardinaux::points> orients, bool b, bool c=false) : Element(orients), blason(b), cathedrale(c) {}
    const int getElementPoints() override { return 2 + (blason ? 2: 0); }
    TypeElement getType() override { return TypeElement::ville; }
    bool const hasModifier() override { return cathedrale; }
};

class ElementPre : public Element {
public:
    ElementPre(std::list<TypeCardinaux::points> orients) : Element(orients) {}
    void rotateOrientation() override;
    const int getElementPoints() override { return 4; }
    TypeElement getType() override { return TypeElement::pre; }
};

// Unitairement 1 point
class ElementRoute : public Element {
private:
    bool auberge;
public:
    ElementRoute(std::list<TypeCardinaux::points> orients, bool a=false) : Element(orients), auberge(a) {}
    const int getElementPoints() override { return 1; }
    TypeElement getType() override { return TypeElement::route; }
    bool const hasModifier() override { return auberge; }
};

class ElementRiviere : public Element {
public:
    ElementRiviere(std::list<TypeCardinaux::points> orients) : Element(orients) {}
    TypeElement getType() override { return TypeElement::riviere; }
    const int getElementPoints() override { return 5; }
};

//
class ElementJardin : public Element {
public:
    ElementJardin() : Element() {}
    TypeElement getType() override { return TypeElement::jardin; }
    const int getElementPoints() override { return 9; }
};

// 9 Points quand complété
class ElementAbbaye : public Element {
public:
    ElementAbbaye() : Element() {}
    TypeElement getType() override { return TypeElement::abbaye; }
    const int getElementPoints() override { return 9; }
};
#endif
