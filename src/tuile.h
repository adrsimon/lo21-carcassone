#ifndef tuile_h
#define tuile_h
#include <list>
#include "element.h"
#include "position.h"

class Tuile {
private:
    Position position;
    const int ID;
    const bool hasMonastere;
    const bool hasJardin;
    const std::list <Element> elements;
public:
    Tuile(const bool &m,const bool &j, const int &id, const std::list<Element> e);
    ~Tuile() = default;
    Tuile(const Tuile& j)=delete;
    Tuile& operator=(const Tuile& j)=delete;
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