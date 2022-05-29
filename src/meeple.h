#ifndef meeple_h
#define meeple_h

#include <string>

#include "enum.h"

class Meeple{
    std::string type;
    bool isAvailable;
public:
    const std::string getType() const {return type;}
    bool isPlaced() const {return !isAvailable;}
    Meeple() = default;
    Meeple(const Meeple& m)=default;
    Meeple& operator=(const Meeple& m)=delete;
    ~Meeple()=default;
    virtual TypeMeeple const getType() { return TypeMeeple::normal; }
    void setAvailable(const bool b){ isAvailable = b; }
};

class BigMeeple: public Meeple {
public:
    BigMeeple() : Meeple() {}
    TypeMeeple const getType() override { return TypeMeeple::big; }
};

class AbbeMeeple: public Meeple {
public:
    AbbeMeeple() : Meeple() {}
    TypeMeeple const getType() override { return TypeMeeple::abbe; }
};

#endif
