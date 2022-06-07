#include <iostream>
// #include <QApplication>

#include "src/jeu.h"
// #include "VuePartie.h"

int main(int argc, char** argv) {


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
     ****** 2.4. Tourner la carte si besoin                     OK
     ****** 2.5. Ajouter dans les groupements                   OK
     ****** 2.6. Poser un meeple                                OK
     ****** 2.7. Ajouter le meeple dans les groupements         OK
     ****** 2.8. Demander si un groupement est fini             OK
     ****** 2.9. Attribuer les points                           TO DO
     * 3. Fin de la partie ------------------------------------ OK
     ****** 3.1. Afficher le score                              OK
     ****** 3.2. Afficher le gagnant                            OK
     */

    Jeu& jeu = Jeu::getJeu();
    std::vector<std::string> noms = { "Adrien", "Léo"};
    std::vector<TypeCouleur> cs = { TypeCouleur::bleu, TypeCouleur::orange};
    jeu.initialiser(noms, cs, true);

    std::cout<< "----- DEBUT DE LA PARTIE -----" << std::endl;
    std::cout << std::endl;
    std::cout << "Nombre de joueurs : " << jeu.getJoueurs().size() << std::endl;
    int compteurJoueur = 1;
    for (auto& j : jeu.getJoueurs()) {
        std::cout << "Joueur " << compteurJoueur << " : " << j->getNom() << std::endl;
        compteurJoueur++;
    }

    while (!jeu.isGameFinished()) {
        // CREATION D'UN NOUVEAU TOUR
        std::cout << std::endl;
        std::cout << "-------- NOUVEAU TOUR --------" << std::endl;
        std::cout << std::endl;

        // ETAT DU TOUR
        std::cout << "C'est au tour de : " << jeu.getCurrentJoueur()->getNom() << std::endl;
        std::cout << "Il reste " << jeu.getTuilesAmount() << " cartes dans la pioche" << std::endl;
        std::cout << "Tuile à jouer: " << jeu.getCurrentTuileId() << std::endl;

        // TUILES PLACEMENT
        bool tuilePlaced = false;
        do {
            // pour tourner la tuile si besoin
            char choixTourner;
            std::cout << "Tourner la case ? (o/n) : ";
            std::cin >> choixTourner;
            if (choixTourner == 'o') {
                std::cout << "Tuile tournée de 90 degrés" << std::endl;
                jeu.rotateTuile();
            } else std::cout << "Tuile non-tournée." << std::endl;

            // pour choisir la case
            int x = 0, y = 0;
            if (jeu.getPlateau()->getMap().empty()) { // Si c'est la première case on la place forcément en 0, 0
                std::cout << "Tuile automatiquement placée." << std::endl;
            } else {
                std::cout << "Cases libres : " << std::endl;
                int compteurOption = 0, choix;
                std::vector<std::pair<int,int>> casesLibres = jeu.getAvailableTuilesChoices();
                for (auto i: casesLibres) {
                    std::cout << compteurOption << " - (X, Y): (" << i.first << ", " << i.second << ")" << std::endl;
                    compteurOption++;
                }
                // on demande au joueur de choisir une case
                std::cin >> choix;
                x = casesLibres[choix].first;
                y = casesLibres[choix].second;
            }
            // on vérifie que la case choisie est bien compatible
            tuilePlaced = jeu.tuileAction(x,y);
            if (tuilePlaced)
                std::cout << "Tuile placée en (" << x << ", " << y << ")" << std::endl;
            else
                std::cout << "Tuile incompatible" << std::endl;
        } while(!tuilePlaced);

        //MEEPLE PLACEMENT
        bool meeplePlaced = false;
        char choixMeeple;
        do {
            std::cout << "Poser un meeple sur cette tuile ? (o/n) : ";
            std::cin >> choixMeeple;
            if (choixMeeple == 'n') {
                std::cout << "Pas de meeple placé." << std::endl;
                meeplePlaced = true;
            } else {
                std::cout << "Placement du meeple :" << std::endl;
                int compteurOption = 0, choixElement;
                Element* e;
                TypeMeeple t;
                std::cout << "Elements disponibles : " << std::endl;
                for (auto i : jeu.getCurrentTuile()->getElements()) {
                    const char *elem = "";
                    switch(i->getType()) {
                        case TypeElement::ville:
                            elem = "Ville";
                            break;
                        case TypeElement::abbaye:
                            elem = "Abbaye";
                            break;
                        case TypeElement::pre:
                            elem = "Pré";
                            break;
                        case TypeElement::route:
                            elem = "Route";
                            break;
                        case TypeElement::jardin:
                            elem = "Jardin";
                            break;
                        default:
                            break;
                    }
                    if (std::strcmp(elem, "") != 0) {
                        std::cout << compteurOption << " - " << elem << std::endl;
                        compteurOption++;
                    }
                }
                std::cin >> choixElement;

                // retrouver le bon element dans la liste
                int i = 0;
                for (auto elem : jeu.getCurrentTuileElements()) {
                    if (i == choixElement) {
                        e = elem;
                        break;
                    }
                    i++;
                }

                // on choisit le type de meeple à poser
                int choixType;
                compteurOption = 0;
                std::cout << "Meeples disponibles : " << std::endl;
                int compteurNormal = 0, compteurAbbe = 0, compteurBig = 0;
                for (auto i : jeu.getPlayerMeeplesAmount()) {
                    switch (i.first) {
                        case TypeMeeple::normal:
                            compteurNormal=i.second;
                            break;
                        case TypeMeeple::big:
                            compteurBig=i.second;
                            break;
                        case TypeMeeple::abbe:
                            compteurAbbe=i.second;
                            break;
                    }
                }

                std::cout << "0 - Normal : " << compteurNormal << " meeple(s) diponible(s)" << std::endl;
                std::cout << "1 - Big : " << compteurBig << " meeple diponible" << std::endl;
                std::cout << "2 - Abbe : " << compteurAbbe << " meeple diponible" << std::endl;
                std::cin >> choixType;

                switch (choixType) {
                    case 0:
                        t = TypeMeeple::normal;
                        break;
                    case 1:
                        t = TypeMeeple::big;
                        break;
                    case 2:
                        t = TypeMeeple::abbe;
                        break;
                }

                meeplePlaced = jeu.meepleAction(e, t);
                if (meeplePlaced) {
                    std::cout << "Meeple placé" << std::endl;
                }
                else std::cout << "Meeple incompatible ou Element inexistant" << std::endl;
            }
        } while(!meeplePlaced);

        /*
        // GROUPEMENT VALIDATION
        bool groupementValidated = false;
        char choixGroupement;
        do {
            std::cout << "Un groupement est-il fini ? (o/n) : ";
            std::cin >> choixGroupement;
            if (choixGroupement == 'o') {
                int compteurOption = 0, choixNumGroupement;
                std::list<Groupement*> groupements = jeu.getPlateau()->getGroupements();
                for (auto i : groupements) {
                    switch (i->getType()) {
                        case TypeElement::ville:
                            std::cout << compteurOption << " - Ville " << std::endl;
                            break;
                        case TypeElement::abbaye:
                            std::cout << compteurOption << " - Abbaye " << std::endl;
                            break;
                        case TypeElement::pre:
                            std::cout << compteurOption << " - Pré " << std::endl;
                            break;
                        case TypeElement::route:
                            std::cout << compteurOption << " - Route " << std::endl;
                            break;
                        case TypeElement::jardin:
                            std::cout << compteurOption << " - Jardin " << std::endl;
                            break;
                        default:
                            break;
                    }
                    compteurOption++;
                }
                std::cin >> choixNumGroupement;


                // RETROUVER LE BON JOUEUR POUR LE GROUPEMENT, LUI DONNER LES POINTS, RENDRE LES MEEPLES

                int points;
                Joueur* joueur;
                joueur->setScore(joueur->getScore() + points);


                std::cout << "Groupement validé" << std::endl;
                groupementValidated = true;
            } else std::cout << "Groupement non-validé" << std::endl;
        } while(!groupementValidated);
        */
        jeu.nextTurn();
    }

    // FIN DE LA PARTIE

    int maxPoints = 0;
    std::string nomGagnant;
    compteurJoueur = 0;
    for (auto& j : jeu.getJoueurs()) {
        std::cout << "Joueur " << compteurJoueur << " : " << j->getNom()  << " - " << j->getScore() << " points." << std::endl;
        compteurJoueur++;
        if (j->getScore() > maxPoints) {
            maxPoints = j->getScore();
            nomGagnant = j->getNom();
        }
        std::cout << "Le gagnant est : " << nomGagnant << std::endl;
    }

    /*
    QApplication app(argc, argv);
    VuePartie vuepartie;
    vuepartie.show();
    return app.exec();
    */

    return 0;
}
