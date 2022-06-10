#include <iostream>
 #include <QApplication>

#include "src/jeu.h"
#include "VuePartie.h"

int main(int argc, char** argv) {

    QApplication app(argc, argv);
    VuePartie vuepartie;
    vuepartie.show();
    return app.exec();

}
