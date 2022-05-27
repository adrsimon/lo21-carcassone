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


void Jeu::poserMeeple() {

    std::cout << "1 : pour ajouter un meeple\n";
    std::cout << "2 : pour ajouter un abbé\n";
    std::cout << "3 : pour ajouter un Big Meeple\n";
    std::cout << "4 : pour ne pas ajouter de meeple\n";
    int a;
    std::cin >> a;
    int j;
    auto it=current->getMeeple().begin();


    switch (a) {
        case 1:
            for (it=current->getMeeple().begin();it!=current->getMeeple().end();it++) {
                if(it->getType()!=Normal) continue;
                if(it->getDisponible()==true)
                    break;
            }
            if(it!=current->getMeeple().end()) it->updateMeeple();
            for (auto i = last_tuile->getElement().begin(); i < last_tuile->getElement().end(); i++) {
                if (last_tuile->getElement()[i]->getGroupement()->getMeeple() == nullptr)
                    std::cout <<i<<" : "<< last_tuile->getElement()[i]->getType() << "\n";
            }
            std::cin>>j;
            last_tuile->getElement()[j]->getGroupement()->setMeeple(it);
            break;

        case 2:
            for (it=current->getMeeple().begin();it!=current->getMeeple().end();it++) {
                if(it->getType()!=Abbe) continue;
                if(it->getDisponible()==true) break;
            }
            if(it!=current->getMeeple().end()) it->updateMeeple();

            for (auto i = last_tuile->getElement().begin(); i < last_tuile->getElement().end(); i++) {
                if (last_tuile->getElement()[i]->getGroupement()->getMeeple() == nullptr)
                    std::cout <<i<<" : "<< last_tuile->getElement()[i]->getType() << "\n";
            }
            std::cin>>j;
            if(last_tuile->getElement()[j]->getType()!=abbaye || last_tuile->getElement()[j]->getType()!=jardin)
                throw "Exception : vous ne pouvez poser de abbé sur cette élément";
            last_tuile->getElement()[j]->getGroupement()->setMeeple(it);

            break;

        case 3:
            for (it=current->getMeeple().begin();it!=current->getMeeple().end();it++) {
                if(it->getType()!=Big) continue;
                if(it->getDisponible()==true) break;
            }
            if(it!=current->getMeeple().end()) it->updateMeeple();

            for (auto i = last_tuile->getElement().begin(); i < last_tuile->getElement().end(); i++) {
                if (last_tuile->getElement()[i]->getGroupement()->getMeeple == nullptr)
                    std::cout <<i<<" : "<< last_tuile->getElement()[i]->getType() << "\n";
            }
            std::cin>>j;
            last_tuile->getElement()[j]->getGroupement()->setMeeple(it);

            break;

        default:
            break;

    }
}

void Jeu::updateJoueur(){
    auto it = find(joueur.begin(),joueur.end(),current);
    if(next(it,1)==joueur.end()){
        it=joueur.begin();
        current=*it;
    }
    else { it=next(it,1);
        current=*it;
    }
}

void Jeu::updateTuile(){
    last_tuile=pioche->piocher(); 
}
