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
    
    class IteratorPioche{
        const Tuile* debut;
        const Tuile* fin;
        IteratorPioche(const Tuile* d, const Tuile* f) : debut(d), fin(f){}
        friend class Jeu;
    public:
        bool isDone() const {return debut==fin;}
        void next(){
            if(debut==fin) throw "Exception : fin de la pioche";
            debut++;
        }
        const Tuile* currentItem() const {
            if(debut==fin) throw "Exception : fin de la pioche";
            return debut;
        }
    };
    IteratorPioche getIteratorPioche(){
        int nb=tuiles->getNbTuiles();
        return IteratorPioche(last_tuile, last_tuile+nb);
    }
    class IteratorJoueur{
        const Joueur* debut;
        const Joueur* fin;
        IteratorJoueur(const Joueur* d, const Joueur* f) : debut(d),fin(f){}
        friend class Jeu;
    public:
        bool isDone() const {return debut==fin;}
        void next(){
            if(debut==fin) throw "Exception : fin du tour";
            debut++;
        }
        const Joueur* currentItem(){
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
    const Tuile* last_tuile;
    Joueur* liste;
    const Joueur* current;
    Plateau* plateau;
    Pioche* tuiles;
    int nb_joueur;
};

#endif

