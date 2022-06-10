//
// Created by Leo Peron on 28/05/2022.
//

#include "VuePlateau.h"

VuePlateau::VuePlateau(QWidget *parent) : QGridLayout(parent){
    for (int i = 0; i < 13; i++) {
        for(int j=0; j <22; j++) {
            tuiles[i][j] = new VueTuile(j-11,-(i-6));
            addWidget(tuiles[i][j], i, j);
            connect(tuiles[i][j],&VueTuile::tuileClicked, this, &VuePlateau::tuileClick);
        }
    }
    //QGridLayout::setHorizontalSpacing(5);
    //QGridLayout::setVerticalSpacing(5);
}

void VuePlateau::tuileClick(VueTuile* vt) {
    std::cout <<  vt->getVueTuileX() << vt->getVueTuileY() << std::endl;
    if(j.tuileAction( vt->getVueTuileX(), vt->getVueTuileY())) {
        poserTuile(j.getCurrentTuileId(), vt->getVueTuileX(), vt->getVueTuileY());
        j.nextTurn();
        endTour();
    } else {
        QMessageBox qmsgbox;
        qmsgbox.setText("Tuile Non Compatible");
        qmsgbox.exec();
    }
}

void VuePlateau::poserTuile(int id, int x, int y) {
    tuiles[x+6][y+11]->setTuile(id);
}
