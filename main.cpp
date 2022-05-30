#include <iostream>
#include <QApplication>

#include "src/jeu.h"
#include "VuePartie.h"

int main(int argc, char** argv) {
    std::cout<< "Hello world" << std::endl;

    Pioche& p = Pioche::getInstance();
    p.genererTuiles();

    Plateau& pl = Plateau::getInstance();
    Tuile* t;
    t = p.piocher();
    std::cout << t->getID() << std::endl;
    pl.placerTuile(t, 5,5);
    t = p.piocher();
    std::cout << t->getID() << std::endl;
    pl.placerTuile(t, 4,5);
    t = p.piocher();
    std::cout << t->getID() << std::endl;
    pl.placerTuile(t, 6,5);
    t = p.piocher();
    std::cout << t->getID() << std::endl;
    pl.placerTuile(t, 5,4);
    t = p.piocher();
    std::cout << t->getID() << std::endl;
    pl.placerTuile(t, 5,6);
    std::vector<Tuile*> raw = pl.getVoisins(5,5);
    for (auto it = raw.begin(); it != raw.end(); it++) {
        std::cout << (*it)->getID() << std::endl;
    }
    //Jeu& j = Jeu::getJeu();
    /*
    Plateau& plateau = Plateau::getInstance();
    Pioche& pioche = Pioche::getInstance();

    pioche.genererTuiles();
    Tuile t = pioche.piocher();

    std::cout << "TUILE AVANT PLACEMENT" << std::endl;
    std::cout << "Tuile numéro : " << t.getID() << std::endl;
    std::cout << "La tuile possède : " << t.getElement().size() << " élements." << std::endl;
    std::cout << "L'élement 1 est orienté dans : "<< t.getElement().begin()->getOrientations().size() << " directions." << std::endl;

    plateau.placerTuile(&t, 0, 0);

    std::cout << "TUILE APRES PLACEMENT" << std::endl;
    std::cout << "Tuile numéro : " << plateau.getTuile(0, 0).getID() << std::endl;
    std::cout << "La tuile possède : " << plateau.getTuile(0, 0).getElement().size() << " élements." << std::endl;
    std::cout << "L'élement 1 est orienté dans : "<< plateau.getTuile(0, 0).getElement().begin()->getOrientations().size() << " directions." << std::endl;

    // t = pioche.piocher();

    // std::cout << "TEST DE COMPATIBILITE" << std::endl;
    // std::cout << "Tuile numéro : " << t.getID() << std::endl;
    // std::cout << plateau.voisinsCompatibles(0, 0, &t) << std::endl;
     */
    /*
    QApplication app(argc, argv);
    VuePartie vuepartie;
    vuepartie.show();
    return app.exec();
    */

    return 0;
}
