#ifndef groupement_h
#define groupement_h

#include <iostream>
#include <string>
#include <list>
#include <array>
#include <vector>
#include "enum.h"
#include "meeple.h"
#include "element.h"

using namespace std;
enum class Type{riviere, ville, abbaye, pre, route, jardin};

class Groupement {
private:
    std::list<Meeple *> meeples; // Liste de meeples
    const enum Type type;
    size_t points;
    std::list<Element *> element;
    bool complete = false;

public:
    size_t getPoints() const { return points; }

    std::list<Meeple *> getMeeples() const { return meeples; }

    const enum Type getType() const { return type; }

    bool isComplete() { return complete; }

    std::list<Element *> getElement() const { return element; }

    inline void addMeeples(Meeple *const m) {
        meeples.push_back(m);
    }

    inline void addElement(Element *const e) {
        element.push_back(e);
    }

    void setComplete() {
        complete = true;
    }

    virtual ~Groupement() = default;

    Groupement(const enum Type t, size_t p) : type(t), points(p) {}

    virtual Groupement &operator=(const Groupement &g) = delete;

    virtual inline Groupement &operator+(const Groupement &g) {
        for (unsigned int i = 0; i < (g.meeples).size(); i++) { (this->meeples).push_back(g.meeples[i]); }
        for (unsigned int i = 0; i < (g.element).size(); i++) { (this->element).push_back(g.element[i]); }
        this->type = g.type;
        this->complete = g.complete;
        this->points += g.points;
        //Groupement(this->type, this->points, this->complete);
        return (*this);
    }
};

    /*
     class iterator{ //Accès en écriture ici
         friend class Groupement;
         double* courant;
         double* fin;
         iterator(double* deb, double* f):courant(deb), fin(f){}
     public:
         void next(){
             if(courant==fin) throw "erreur:débordement d'iterator";
             ++courant;
         }
         bool is_done(){return courant==fin;}
         double& current_item(){return *courant;}
     };
     iterator get_iterator(){return iterator(meeples, meeples+meeples.size();}
 };
     */


    class GroupementRoute: public Groupement{
    private:
        int nbSegments;
        int nbAuberges;
    public:
        GroupementRoute(const enum Type t, size_t p, int nbS, int nbA) : Groupement(t, p), nbSegments(nbS),nbAuberges(nbA) {}
        ~GroupementRoute()=default;
        int getNbSegments()const {return nbSegments;}
        int getNbAuberges()const {return nbAuberges;}

        void setNbSegments(int nb) {
            nbSegments = nb;
        }

        void setNbAuberges(int nb) {
            nbAuberges = nb;
        }
    };
    
    class GroupementVille: public Groupement{
    private:
        int nbSegments;
    public:
        GroupementVille(const enum Type t, size_t p, int nbS) : Groupement(t, p), nbSegments(nbS) {}
        ~GroupementVille()=default;
        int getNbSegments()const {return nbSegments;}
        void setNbSegments(int nb) {
            nbSegments = nb;
        }
    };
    
    class GroupementPre: public Groupement{
    private:
        int nbSegments;
    public:
        GroupementPre(const enum Type t, size_t p, int nbS) : Groupement(t, p), nbSegments(nbS) {}
        ~GroupementPre()=default;
        int getNbSegments()const {return nbSegments;}
        void setNbSegments(int nb) {
            nbSegments = nb;
        }
    };
    
    class GroupementAbbaye: public Groupement{
    private:
        int nbCases;
    public:
        GroupementAbbaye(const enum Type t, size_t p, int nbC) : Groupement(t, p), nbCases(nbC) {}
        ~GroupementAbbaye()=default;
        int getNbCases()const {return nbCases;}
        void setNbCases(int nb) {
            nbCases = nb;
        }
    };
    
    class GroupementJardin: public Groupement {
    private:
        int nbCases;
    public:
        GroupementJardin(const enum Type t, size_t p, int nbC) : Groupement(t, p), nbCases(nbC) {}

        ~GroupementJardin() = default;

        int getNbCases() const { return nbCases; }

        void setNbCases(int nb) {nbCases = nb;}
    };

#endif