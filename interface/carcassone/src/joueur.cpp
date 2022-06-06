//
// Created by peron on 01/05/2022.
//

#include "joueur.h"

Meeple* Joueur::getAvailableMeepleByType(TypeMeeple t) {
    for (auto it = meeples.begin(); it != meeples.end(); it++) {
        if(!(*it)->isPlaced() && (*it)->getType() == t)
            return *it;
    }
    return nullptr;
}

std::vector<std::pair<TypeMeeple, int>> Joueur::getAvailableMeeplesAmount() {
    std::vector<std::pair<TypeMeeple, int>> raws;
    int n=0; int b=0; int a=0;
    for(auto it = meeples.begin(); it != meeples.end(); it++) {
        if(!(*it)->isPlaced()) {
            switch ((*it)->getType()) {
                case TypeMeeple::normal:
                    n++;
                    break;
                case TypeMeeple::big:
                    b++;
                    break;
                case TypeMeeple::abbe:
                    a++;
                    break;
            }
        }
    }
    raws.push_back(std::pair<TypeMeeple, int>(TypeMeeple::normal, n));
    raws.push_back(std::pair<TypeMeeple, int>(TypeMeeple::big, b));
    raws.push_back(std::pair<TypeMeeple, int>(TypeMeeple::abbe, a));

    return raws;
}
