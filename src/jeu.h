#ifndef jeu_h
#define jeu_h

#include <stdio.h>
#include "joueur.h"
#include "plateau.h"

#include "iostream"
using namespace std; 

class Jeu{
public:
    Jeu& getJeu();
    void libererJeu();
    Jeu(const Jeu& j)=delete;
    Jeu& operator=(const Jeu& j)=delete;
    
    const Tuile* getLastTuile() const {return last_tuile;}
    
    const Joueur* getCurrent() const {return current; }
    
    Plateau* getPlateau() const {return plateau;}
    
    int getNbJoueur() const {return nb_joueur; }
    
    void setJoueur(const Joueur& j){
        nb_joueur++;
        Joueur* newtab=new Joueur[nb_joueur];
        for (size_t i=0;i<nb_joueur;i++)
        newtab[i]=liste[i];
        auto old=liste;
        liste=newtab;
        delete old;
        liste[nb_joueur]=j;
    }

    class IteratorPioche{
        Tuile* debut;
        Tuile* fin;
        IteratorPioche(Tuile* d, Tuile* f) : debut(d), fin(f){}
        friend class Jeu;
    public:
        bool isDone() const {return debut==fin;}
        void next(){
            if(debut==fin) throw "Exception : fin de la pioche";
            debut++;
        }
        Tuile* currentItem() const {
            if(debut==fin) throw "Exception : fin de la pioche";
            return debut;
        }
    };
    IteratorPioche getIteratorPioche(){
        int nb=tuiles->getNbTuiles();
        return IteratorPioche(last_tuile, last_tuile+nb);
    }
    class IteratorJoueur{
        Joueur* debut;
        Joueur* fin;
        IteratorJoueur(Joueur* d, Joueur* f) : debut(d),fin(f){}
        friend class Jeu;
    public:
        bool isDone() const {return debut==fin;}
        void next(){
            if(debut==fin) throw "Exception : fin du tour";
            debut++;
        }
        Joueur* currentItem(){
            return debut;}
    };
    IteratorJoueur getIteratorJoueur(){return IteratorJoueur(liste,liste+nb_joueur);}
    
    void poserMeeple();
    void updateJoueur(IteratorJoueur it);
    void updateTuile(IteratorPioche it);
    //void evaluerScore();
private:
    static Jeu* instance;
    Jeu();
    ~Jeu();
    Tuile* last_tuile;
    Joueur* liste;
    Joueur* current;
    Plateau* plateau;
    Pioche* tuiles;
    int nb_joueur;
};

#endif

