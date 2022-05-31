#ifndef jeu_h
#define jeu_h

#include <list>
#include "joueur.h"
#include "plateau.h"
#include "enum.h"

#include "iostream"
using namespace std; 

class Jeu{
public:
    static Jeu& getJeu();
    void libererJeu();
    Jeu(const Jeu& j)=delete;
    Jeu& operator=(const Jeu& j)=delete;
    
    Pioche *const getPioche() const {return pioche;}
    Tuile* getLastTuile() const {return currentTuile;}
    const Joueur* getCurrent() const {return currentJoueur; }
    Plateau *const getPlateau() const {return plateau;}
    list<Joueur*> getJoueurs() const {return joueurs;}
    
    void addJoueur(std::string nom){
        joueurs.push_back(new Joueur(nom));
    }

    void setExtensions(const bool b, const bool r, const bool ac) {
        abbaye = b;
        riviere = r;
        aubergecathedrale = ac;
    }

    void poserMeeple(Joueur* j, Element* e, TypeMeeple t);
    void recupererMeeple(Meeple* m);
    void updateJoueur();
    void updateTuile();
    void tourTuile(int x, int y);
private:
    static Jeu* instance;
    Jeu();
    ~Jeu();
    Tuile* currentTuile;
    list<Joueur*> joueurs;
    Joueur* currentJoueur;
    Plateau* plateau;
    Pioche* pioche;
    bool abbaye=false;
    bool riviere=false;
    bool aubergecathedrale = false;
};

#endif

