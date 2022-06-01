#include <iostream>
// #include <QApplication>

#include "src/jeu.h"
// #include "VuePartie.h"

int main(int argc, char** argv) {

    std::cout<< "Hello world" << std::endl;

    Jeu& jeu = jeu.getJeu();
    jeu.initialiser();

    Pioche* pioche = jeu.getPioche();
    Plateau* plateau = jeu.getPlateau();

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

    /*
    QApplication app(argc, argv);
    VuePartie vuepartie;
    vuepartie.show();
    return app.exec();
    */

    return 0;
}
