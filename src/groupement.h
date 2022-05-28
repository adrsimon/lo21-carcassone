#ifndef groupement_h
#define groupement_h

#include <iostream>
#include <string>
#include <list>
#include "enum.h"
#include "meeple.h"
#include "element.h"

using namespace std;

class Groupement {
private:
    std::list<Meeple *> meeples; // Liste de meeples
    std::string type;
    size_t points;
    std::list<Element *> element;
    bool complete = false;

public:
    virtual ~Groupement() = default;
    Groupement(const std::string t, size_t p) : type(t), points(p) {}

    size_t getPoints() const { return points; }
    std::list<Meeple *> getMeeples() const { return meeples; }
    const std::string getType() const { return type; }
    bool isComplete() { return complete; }
    std::list<Element *> getElement() const { return element; }

    inline void addMeeples(Meeple *const m) {meeples.push_back(m);}
    inline void addElement(Element *const e) {element.push_back(e);}
    void setComplete() {complete = true;}

    Groupement &operator=(const Groupement &g);
    Groupement &operator+(const Groupement &g);
};


class GroupementRoute: public Groupement{
private:
    int nbSegments;
    int nbAuberges;
public:
    GroupementRoute(std::string t, size_t p, int nbS, int nbA) : Groupement(t, p), nbSegments(nbS),nbAuberges(nbA) {}
    ~GroupementRoute()=default;
    int getNbSegments()const {return nbSegments;}
    int getNbAuberges()const {return nbAuberges;}
    void setNbSegments(int nb) {nbSegments = nb;}
    void setNbAuberges(int nb) {nbAuberges = nb;}
};
    
class GroupementVille: public Groupement{
private:
    int nbSegments;
public:
    GroupementVille(std::string t, size_t p, int nbS) : Groupement(t, p), nbSegments(nbS) {}
    ~GroupementVille()=default;
    int getNbSegments()const {return nbSegments;}
    void setNbSegments(int nb) {nbSegments = nb;}
};
    
class GroupementPre: public Groupement{
private:
    int nbSegments;
public:
    GroupementPre(std::string t, size_t p, int nbS) : Groupement(t, p), nbSegments(nbS) {}
    ~GroupementPre()=default;
    int getNbSegments()const {return nbSegments;}
    void setNbSegments(int nb) {nbSegments = nb;}
};
    
class GroupementAbbaye: public Groupement{
private:
    int nbCases;
public:
     GroupementAbbaye(std::string t, size_t p, int nbC) : Groupement(t, p), nbCases(nbC) {}
     ~GroupementAbbaye()=default;
     int getNbCases()const {return nbCases;}
     void setNbCases(int nb) {nbCases = nb;}
};
    
class GroupementJardin: public Groupement {
private:
    int nbCases;
public:
    GroupementJardin(std::string t, size_t p, int nbC) : Groupement(t, p), nbCases(nbC) {}
    ~GroupementJardin() = default;
    int getNbCases() const { return nbCases; }
    void setNbCases(int nb) {nbCases = nb;}
};

#endif