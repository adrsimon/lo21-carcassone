#include "plateau.h"

// SINGLETON

Plateau* Plateau::instance = nullptr;

Plateau::Plateau() = default;

Plateau& Plateau::getInstance() {
    if (instance == nullptr) {
        instance = new Plateau();
    }
    return *instance;
}

void Plateau::libereInstance() {
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}

std::vector<Tuile*> Plateau::getVoisins(int x, int y) {
    std::vector<Tuile*> raw;
    raw.push_back(getTuile(x+1, y));
    raw.push_back(getTuile(x-1, y));
    raw.push_back(getTuile(x, y+1));
    raw.push_back(getTuile(x, y-1));
    return raw;
}

Groupement* Plateau::getGroupementWithElement(Element* e) {
    auto it = groupements.begin();
    while(it != groupements.end()) {
        if(std::find((*it)->getElements().begin(), (*it)->getElements().end(), e) != (*it)->getElements().end())
            return *it;
        it++;
    }
}

Groupement* Plateau::getGroupementWithMeeple(Meeple* m) {
    auto it = groupements.begin();
    while(it != groupements.end()) {
        if(std::find((*it)->getMeeples().begin(), (*it)->getMeeples().end(), m) != (*it)->getMeeples().end())
            return *it;
        it++;
    }

}