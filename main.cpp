#include <iostream>
// #include <QApplication>

#include "src/jeu.h"
// #include "VuePartie.h"

int main(int argc, char** argv) {

    std::cout<< "Hello world" << std::endl;

    /* TODO LIST
     * 1. Initialisation de la partie ------------------------- OK
     ****** 1.1. Création du jeu                                OK
     ****** 1.2. Création du plateau                            OK
     ****** 1.3. Création de la pioche                          OK
     ****** 1.4. Création des joueurs                           OK
     * 2. Déroulement de la partie ---------------------------- DOING
     ****** 2.0. Boucle sur les tours                           OK
     ****** 2.1. Pioche une carte                               OK
     ****** 2.2. Poser une carte                                OK
     ****** 2.3. Vérifier la compatibilité                      OK
     ****** 2.4. Tourner la carte si besoin                     DOING
     ****** 2.5. Ajouter dans les groupements
     ****** 2.6. Poser un meeple
     ****** 2.7. Ajouter le meeple dans les groupements
     ****** 2.8. Demander si un groupement est fini
     ****** 2.9. Attribuer les points
     * 3. Fin de la partie ------------------------------------ TO DO
     ****** 3.1. Afficher le score
     ****** 3.2. Afficher le gagnant
     */


    Jeu& jeu = Jeu::getJeu();
    jeu.initialiser();


    while (!jeu.getPioche()->getTuiles().empty()) {
        std::cout << std::endl;
        std::cout << "-------- NOUVEAU TOUR --------" << std::endl;
        std::cout << std::endl;
        jeu.nextTurn();
        // ETAT DU TOUR
        std::cout << "C'est au tour de : " << jeu.getCurrentJoueur()->getNom() << std::endl;
        std::cout << "Il reste " << jeu.getPioche()->getTuiles().size() + jeu.getPioche()->getTuilesRiviere().size() << " cartes dans la pioche" << std::endl;

        // SI C'EST VIDE (premier tour) ON LA PLACE AU MILIEU
        if (jeu.getPlateau()->getMap().empty()) {
            jeu.getPlateau()->placerTuile(jeu.getCurrentTuile(), 0, 0);
        } else { // SINON
            bool tuilePlacable = false;
            while (!tuilePlacable) {
                std::cout << "Voisins libres : " << std::endl;
                int compteurOption = 0;
                int choix;
                // CASES DISPONIBLES
                std::vector<std::pair<int,int>> casesLibres;
                for (auto caseOccupee : jeu.getPlateau()->getMap()) { // POUR TOUTES LES CASES OCCUPEES DE LA CARTE
                    for (auto caseVide : jeu.getPlateau()->getNullVoisins(caseOccupee.first.first, caseOccupee.first.second)) // ON RECUPERE TOUTES LES CASES VIDES
                    casesLibres.push_back(caseVide); // ET ON LES AJOUTE A LA LISTE DE CASE VIDE
                }
                for (auto i : casesLibres) {
                    std::cout << compteurOption << " - (X, Y): (" << i.first << ", " << i.second << ")" << std::endl; // ON AFFICHE TOUTES LES CASES VIDES
                    compteurOption++;
                }
                std::cin >> choix;
                int x = casesLibres[choix].first;
                int y = casesLibres[choix].second;
                if (jeu.getPlateau()->isTuileCompatible(x, y, jeu.getCurrentTuile())) {
                    jeu.getPlateau()->placerTuile(jeu.getCurrentTuile(), x, y);
                    tuilePlacable = true;
                } else {
                    std::cout << "Tuile incompatible" << std::endl;
                }
            }
        }

    }

    /*

    Tuile* t;
    t = pioche->piocher();
    Groupement* g1 = new Groupement(TypeElement::pre);
    g1->addElement(new ElementPre({TypeCardinaux::nord}));
    g1->addElement(new ElementPre({TypeCardinaux::est}));

    Groupement* g2 = new Groupement(TypeElement::pre);
    g2->addElement(new ElementPre({TypeCardinaux::ouest}));
    g2->addElement(new ElementPre({TypeCardinaux::nord}));

    //Groupement* g3 = new Groupement(TypeElement::ville);
    *g1 + *g2;
    std::cout << "Tuile 1:" << t->getID() << std::endl;
    plateau->placerTuile(t, 5,5);
    t = pioche->piocher();
    std::cout << "Tuile 2:" << t->getID() << std::endl;
    std::cout << "Test: " << plateau->isTuileCompatible(4,5, t);
    if(plateau->isTuileCompatible(4,5, t))
        plateau->placerTuile(t,4,5);
    std::cout << "FINI";
    */

    /*
    QApplication app(argc, argv);
    VuePartie vuepartie;
    vuepartie.show();
    return app.exec();
    */

    return 0;
}
