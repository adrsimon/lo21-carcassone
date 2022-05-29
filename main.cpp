#include <iostream>
#include <QApplication>

//#include "src/jeu.h"
#include "VuePartie.h"

int main(int argc, char** argv) {
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

    QApplication app(argc, argv);
    VuePartie vuepartie;
    vuepartie.show();
    return app.exec();

    return 0;
}
