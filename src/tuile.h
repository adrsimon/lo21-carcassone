#ifndef tuile_h
#define tuile_h
#include <list>
#include "element.h"
#include "position.h"

class Tuile {
private:
    Position position;
    const int ID;
    bool hasMonastere;
    bool hasJardin;
    std::list <Element> elements;
public:
    Tuile(const bool &m,const bool &j, const int &id, std::list<Element> &e): hasMonastere(m), hasJardin(j), elements(e), ID(id), position(Position()) {}
    ~Tuile() = default;
    Tuile(const Tuile& j)=default;
    Tuile& operator=(const Tuile& j);
    void setOrientation();
    //void updatePosition (const int& x, const int& y);
    Position& getPosition (){return position;}

    void setPosition (const int &x, const int &y){
        position.setPosition(x,y);
    }

    std::list<Element> getElement()const{
        return elements;
    }
    const bool getM()const{
        return hasMonastere;
    }
    const bool getJ()const{
        return hasJardin;
    }
    const int getID()const{
        return ID;
    }

};

#endif