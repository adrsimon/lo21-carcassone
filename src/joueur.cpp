//
// Created by peron on 01/05/2022.
//

#include "joueur.h"

Meeple* Joueur::getAvailableMeepleByType(TypeMeeple t) {
    auto it = meeples.begin();
    // condition d'arrêt fin d'it
    // OU it->not placed AND it typer == t
    while(it != meeples.end() || (!(*it)->isPlaced()) && (*it)->getType() == t) {
        it++;
    }
    if(it == meeples.end())
        return nullptr;
    return *it;
}
