#include <iostream>
#include "jeu.h"

Jeu* Jeu::instance=nullptr;

Jeu& Jeu::getJeu(){
    if(instance==nullptr){
        instance = new Jeu;
    }
    return *instance;
}

void Jeu::libererJeu(){
    delete instance;
    instance=nullptr;
}


void Jeu::poserMeeple(const std::string type, Element* e) {

    auto it=current->getMeeples().begin();
    if(type=="Normal"){
        for (it=current->getMeeples().begin();it!=current->getMeeples().end();it++) {
            if(it->getType()=="Normal") continue;
            if(it->getDisponible()==true)
                break;
        }
        if(it==current->getMeeples().end())
            throw "Exception Pas de meeple disponible";
        it->updateMeeple();
        //e->setMeeple();
        //e->getGroupement()->addMeeples(*it);
    }
    else { if (type=="Abbe"){
            for (it=current->getMeeples().begin();it!=current->getMeeples().end();it++) {
                if(it->getType()!="Abbe") continue;
                if(it->getDisponible()==true) break;
            }
            if(it==current->getMeeples().end())
                throw "Exception Pas de meeple disponible";
            if(e->getType()=="abbaye" && e->getType()=="jardin"){
                it->updateMeeple();
                //e->setMeeple();
                //e->getGroupement()->addMeeples(*it);
            }
            else  {throw "Exception : vous ne pouvez poser de abbé sur cette élément";}
        }
        else { if(type=="Big"){
                for (it=current->getMeeples().begin();it!=current->getMeeples().end();it++) {
                    if(it->getType()!="Big") continue;
                    if(it->getDisponible()==true) break;
                }
                if(it!=current->getMeeples().end())
                    throw "Exception pas de meeple disponible";
                it->updateMeeple();
                //e->setMeeple();
                //e->getGroupement()->addMeeples(*it);
            }
            else {
                throw "Exception : le type n'existe pas";
            }
        }
    }
}

void Jeu::recupererMeeple(Meeple& m){
    m.updateMeeple(); 
}


void Jeu::updateJoueur(){
    auto it = find(joueurs.begin(),joueurs.end(),current);
    if(next(it,1)==joueurs.end()){
        it=joueurs.begin();
        current=*it;
    }
    else { it=next(it,1);
        current=*it;
    }
}

void Jeu::updateTuile(){
    //last_tuile=pioche->piocher();
}