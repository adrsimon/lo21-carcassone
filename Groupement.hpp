#ifndef Groupement_hpp
#define Groupement_hpp

#include <stdio.h>

enum types string {'riviere', 'ville', 'abbaye','cathedrale','pre','route','jardin'};

class Groupement{
private:
    Meeple** liste[]; // Liste de pointeurs pointant sur la classe Meeple
    unsigned int dim_l;
    enum types;
    unsigned int points;
    Element* element[];
    unsigned int dim_e;
    unsigned int id;
    bool complete=FALSE;
public:
    unsigned int getPoint() const {return points;}
    unsigned int getID() const {return id;}
    Meeple** getMeeple() const {return (**liste).Id;}
    string getType() const {return types;}
    void setMeeple(){
        Meeple* pt=new Meeple; 
        dim_l+=1;
        liste[dim_l-1]=pt->Id;
        return;
    }

    void setComplete(){
        complete=TRUE;
        return;
    }

    ~Groupement(){delete[] element; delete[] liste;}
    Groupement(const Groupement& g): dim_l(g.dim_l), dim_e(g.dim_e),liste(new Meeple** [dim_l]),element(new double [dim_e]),id(g.id),types(g.types),complete(FALSE){
        for (unsigned int i=0; i<dim_l; i++){
            liste[i]=g.liste[i];
        }
        for (unsigned int i=0; i<dim_e; i++){
            element[i]=g.element[i];
        }
    }
    Groupement& operator=(const Groupement& g){
        Meeple** newliste=new Meeple*[g.dim_l];
        for(unsigned int i=0; i<g.dim_l;i++) newliste[i]=g.liste[i];
        Meeple** old=liste;
        liste=newliste;
        dim_l=g.dim_l;
        delete[] old;

        Element* newel=new Element[g.dim_e];
        for(unsigned int i=0; i<g.dim_e;i++) newel[i]=g.element[i];
        Element* old=element;
        element=newel;
        dim_e=g.dim_e;
        delete[] old;

        return *this;
    }
    
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
    iterator get_iterator(){return iterator(liste, liste+dim_l);}
};

#endif Groupement_hpp


