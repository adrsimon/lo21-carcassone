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
    bool isMeeple() const { return hasMeeple; }
    virtual int getElementPoints() const { return -1; };
    virtual bool hasModifier() const { return false; }
    virtual TypeElement::points getType() { return TypeElement::last; }
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
    int getElementPoints() const override { return 2 + (blason ? 2: 0); }
    TypeElement::points getType() override { return TypeElement::ville; }
    bool hasModifier() const override { return cathedrale; }
};

class ElementPre : public Element {
public:
    ElementPre(std::list<TypeCardinaux::points> orients) : Element(orients) {}
    int getElementPoints() const override { return 0; }
    TypeElement::points getType() override { return TypeElement::pre; }
};

// Unitairement 1 point
class ElementRoute : public Element {
private:
    bool auberge;
public:
    ElementRoute(std::list<TypeCardinaux::points> orients, bool a=false) : Element(orients), auberge(a) {}
    int getElementPoints() const override { return 1; }
    TypeElement::points getType() override { return TypeElement::route; }
    bool hasModifier() const override { return auberge; }
};

class ElementRiviere : public Element {
public:
    ElementRiviere(std::list<TypeCardinaux::points> orients) : Element(orients) {}
    TypeElement::points getType() override { return TypeElement::riviere; }
    int getElementPoints() const override { return 5; }
};

//
class ElementJardin : public Element {
public:
    ElementJardin() : Element() {}
    TypeElement::points getType() override { return TypeElement::jardin; }
    int getElementPoints() const override { return 9; }
};

// 9 Points quand complété
class ElementAbbaye : public Element {
public:
    ElementAbbaye() : Element() {}
    TypeElement::points getType() override { return TypeElement::abbaye; }
    int getElementPoints() const  override { return 9; }
};
#endif
