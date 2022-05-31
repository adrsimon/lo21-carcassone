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
    Groupement* g1 = new Groupement(TypeElement::pre);
    g1->addElement(new ElementPre({TypeCardinaux::nord}));
    g1->addElement(new ElementPre({TypeCardinaux::est}));

    Groupement* g2 = new Groupement(TypeElement::pre);
    g2->addElement(new ElementPre({TypeCardinaux::ouest}));
    g2->addElement(new ElementPre({TypeCardinaux::nord}));

    std::cout << "etrange";
    //Groupement* g3 = new Groupement(TypeElement::ville);
    *g1 + *g2;
    std::cout << "Tuile 1:" << t->getID() << std::endl;
    pl.placerTuile(t, 5,5);
    t = p.piocher();
    std::cout << "Tuile 2:" << t->getID() << std::endl;
    std::cout << "Test: " << pl.isTuileCompatible(4,5, t);
    if(pl.isTuileCompatible(4,5, t))
        pl.placerTuile(t,4,5);
    std::cout << "FINI";

    /*
    QApplication app(argc, argv);
    VuePartie vuepartie;
    vuepartie.show();
    return app.exec();
    */
    return 0;
}
