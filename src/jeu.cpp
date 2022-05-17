//
//  jeu.cpp
//  
//
//  Created by Claire Louard on 01/05/2022.
//

#include "jeu.h"

void Jeu::poserMeeple(){
    // à completer, pb pour différencier dans groupement : meeple, big meeple, abbé 
    
    
    for(unsigned int i=0; i<len(last_tuile.listElement), i++) {
        if(last_tuile.listElement[i].groupement.ListMeeple==NULL)
            cout <<last_tuile.listElement.type<<"\n";
    }
    cout<<"1 : pour ajouter un meeple\n";
    cout<<"2 : pour ajouter un abbé\n";
    cout<<"3 : pour ajouter un Big Meeple\n";
    cout<<"4 : pour ne pas ajouter de meeple\n";
    int a;
    cin<<a;
    switch (a) {
        case 1:
            if(current.getnbmeeple==0) throw "Exception : Vous n'avez plus de meeple";
            current.updateMeeple();
            updateMeeple(Joueur* current);
            break;
        
        case 2:
            if(current.abbe=false) throw "Exeption : Vous n'avez plus d'abbé";
            current.updateAbbe();
            updateMeeple(Joueur* current);
            break;
        
        case 3:
            if(current.bigMeepl=false) throw "Exception : vous n'avez plus de Big Meeple";
            currentupdateBigMeeple();
            updateMeeple(Joueur* current);
            break;
            
        default:
            break;
            
        // pb différencier les types de meeple
        
    }
}

void Jeu::updateJoueur(){
    unsigned int i=0;
    while(liste[i]!=current) i++;
    if(i+1>nb_joueur) current=liste[0];
    else {current=liste[i+1]}
}

void Jeu::updateTuile(){
    //voir avec la pioche 
}

void jeu::evaluerScore(){
    //évaluation des scores fin du jeu
    for(unsigned int i=0; i<plateau.nbGroupement; i++){
        //Tous les scores sont évaluer en fin de jeu
        //sinon ajouter un boolean pour indiquer les groupements ou les points sont déjà évaluer
        if(groupement[i].Complete==TRUE){
            switch (plateau. groupement[i].type){
                case ville:
                    if(len(plateau.groupement[i].listMeeple)==1)
                        int nb=0;
                    for(unsigned int j=0;j<len(plateau.groupement[i].listElement);j++) nb++;
                    plateau.groupement[i].listMeeple.score+=2*nb;
                    //ajouter blason
                    
                    break;
                case route:
                    if(len(plateau.groupement[i].listMeeple)==1)
                        int nb=0;
                    for(unsigned int j=0;j<len(plateau.groupement[i].listElement);j++) nb++;
                    plateau.groupement[i].listMeeple.score+=nb;
                    break;
                case pres:
                    break;
                case abbaye:
                    if(len(listMeeple)==1)
                        plateau.groupement[i].listMeeple.score+=9;
                    else{
                        
                    }
                    break;
                default:
                    break;
            }
        }
        else {switch (groupement[i].type){
            case ville:
                break;
            case route:
                if(len(plateau.groupement[i].listMeeple)==1)
                    int nb=0;
                for(unsigned int j=0;j<len(plateau.groupement[i].listElement);j++) nb++;
                plateau.groupement[i].listMeeple.score+=nb;
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

void jeu::play(){
    
}
