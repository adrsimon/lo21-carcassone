#include <iostream>
#include <QApplication>

#include "VuePartie.h"
#include "VuePlateau.h"
#include "VueSettings.h"
#include "VueTuile.h"
#include "VueValider.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    //VueValider mainWindow= VueValider();

    VuePartie mainWindow = VuePartie();
    mainWindow.getScene()->createGrille();
    mainWindow.show();
    return app.exec();
}
