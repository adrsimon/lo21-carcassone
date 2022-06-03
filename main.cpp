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
     ****** 2.6. Poser un meeple                                TO DO
     ****** 2.7. Ajouter le meeple dans les groupements         TO DO
     ****** 2.8. Demander si un groupement est fini             TO DO
     ****** 2.9. Attribuer les points                           TO DO
     * 3. Fin de la partie ------------------------------------ OK
     ****** 3.1. Afficher le score                              OK
     ****** 3.2. Afficher le gagnant                            OK
     */

    Jeu& jeu = Jeu::getJeu();
    std::vector<std::string> noms = { "Adrien", "Chloé", "Léo", "Claire", "Sixtine"};
    std::vector<TypeCouleur> cs = { TypeCouleur::bleu, TypeCouleur::orange, TypeCouleur::rose, TypeCouleur::vert, TypeCouleur::jaune};
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

        jeu.nextTurn();

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
                jeu.getCurrentTuile()->rotateOrientation();
            } else std::cout << "Tuile non-tournée." << std::endl;

            // pour choisir la case
            std::cout << "Cases libres : " << std::endl;
            int compteurOption = 0, choix;
            int x, y;
            std::vector<std::pair<int,int>> casesLibres;
            if (jeu.getPlateau()->getMap().empty()) { // Si c'est la première case on la place forcément en 0, 0
                std::cout << compteurOption << " - (X, Y): (0, 0)" << std::endl;
                std::cin >> choix;
                x = 0;
                y = 0;
            } else {
                casesLibres = jeu.getAvailableTuilesChoices();
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
    Plateau& plateau = Plateau::getInstance();
    Pioche& pioche = Pioche::getInstance();
    pioche.genererTuiles();
    Tuile* t;
    t = pioche.piocher();

    std::cout << "Tuile 1:" << t->getID() << std::endl;
    plateau.placerTuile(t, 0,0);
    bool test;
    do {
        t = pioche.piocher();
        std::cout << "Tuile 2:" << t->getID() << std::endl;
        std::cout << "Test: " << plateau.isTuileCompatible(-1,0, t);
        test = plateau.isTuileCompatible(-1,0, t);
    } while(!test);
    plateau.placerTuile(t,-1,0);
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
