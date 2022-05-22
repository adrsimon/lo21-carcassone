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
            for (unsigned int i = 0; i < sizeof(last_tuile->getElement()); i++) {
                if (last_tuile->getElement()[i]->getGroupement()->liste == nullptr)
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
            
            for (unsigned int i = 0; i < sizeof(last_tuile->getElement()); i++) {
                if (last_tuile->getElement()[i]->getGroupement()->liste == nullptr)
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
            
            for (unsigned int i = 0; i < sizeof(last_tuile->getElement()); i++) {
                if (last_tuile->getElement()[i]->getGroupement()->liste == nullptr)
                    std::cout <<i<<" : "<< last_tuile->getElement()[i]->getType() << "\n";
            }
            std::cin>>j;
            last_tuile->getElement()[j]->getGroupement()->setMeeple(it);
            
            break;

        default:
            break;
 
    }
}

void Jeu::updateJoueur(IteratorJoueur it){
    if(it.isDone())
        it=Jeu::getIteratorJoueur();
    else {it.next();}
    current=it.currentItem();
}

void Jeu::updateTuile(IteratorPioche it){
    it.next();
    last_tuile=it.currentItem();
}

/*
void Jeu::evaluerScore() {
    //évaluation des scores fin du jeu
    for (unsigned int i = 0; i < plateau.nbGroupement; i++) {
        //Tous les scores sont évaluer en fin de jeu
        //sinon ajouter un boolean pour indiquer les groupements ou les points sont déjà évaluer
        if (groupement[i].complete == true) {
            switch (plateau.groupement[i].type) {
                case ville:
                    if (len(plateau.groupement[i].listMeeple) == 1)
                        int nb = 0;
                    for (unsigned int j = 0; j < len(plateau.groupement[i].listElement); j++) nb++;
                    plateau.groupement[i].listMeeple.score += 2 * nb;
                    //ajouter blason

                    break;
                case route:
                    if (len(plateau.groupement[i].listMeeple) == 1)
                        int nb = 0;
                    for (unsigned int j = 0; j < len(plateau.groupement[i].listElement); j++) nb++;
                    plateau.groupement[i].listMeeple.score += nb;
                    break;
                case pres:
                    break;
                case abbaye:
                    if (len(listMeeple) == 1)
                        plateau.groupement[i].listMeeple.score += 9;
                    else {

                    }
                    break;
                default:
                    break;
            }
        } else {
            switch (groupement[i].type) {
                case ville:
                    break;
                case route:
                    if (len(plateau.groupement[i].listMeeple) == 1)
                        int nb = 0;
                    for (unsigned int j = 0; j < len(plateau.groupement[i].listElement); j++) nb++;
                    plateau.groupement[i].listMeeple.score += nb;
                    break;
                case pres:
                    break;
                case abbaye:
                    break;
                default:
                    break;
            }
        }
    }
}
*/
