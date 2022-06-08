#ifndef meeple_h
#define meeple_h

#include <string>

#include "enum.h"

class Meeple{
    bool isAvailable;
public:
    bool isPlaced() const {return !isAvailable;}
    Meeple() : isAvailable(true) {}
    Meeple(const Meeple& m)=default;
    Meeple& operator=(const Meeple& m)=delete;
    ~Meeple()=default;
    virtual TypeMeeple::points const getType() { return TypeMeeple::normal; }
    void setAvailable(const bool b){ isAvailable = b; }
};

class BigMeeple: public Meeple {
public:
    BigMeeple() : Meeple() {}
    TypeMeeple::points const getType() override { return TypeMeeple::big; }
};

class AbbeMeeple: public Meeple {
public:
    AbbeMeeple() : Meeple() {}
    TypeMeeple::points const getType() override { return TypeMeeple::abbe; }
};

#endif
