//
// Created by Leo Peron on 28/05/2022.
//

#include "VuePlateau.h"

VuePlateau::VuePlateau(QWidget *parent) : QGridLayout(parent){
    for (int i = 0; i < 13; i++) {
        for(int j=0; j <22; j++) {
            tuiles[i][j] = new VueTuile(i-6,j-11);
            addWidget(tuiles[i][j], i, j);
            connect(tuiles[i][j],&VueTuile::tuileClicked, this, &VuePlateau::tuileClick);
        }
    }
    //QGridLayout::setHorizontalSpacing(5);
    //QGridLayout::setVerticalSpacing(5);
}

void VuePlateau::tuileClick(VueTuile* vt) {
    if(j.tuileAction(vt->getVueTuileX(), vt->getVueTuileY())) {
        poserTuile(j.getCurrentTuileId(), vt->getVueTuileX(), vt->getVueTuileY());
    } else {
        QMessageBox msgBox;
        msgBox.setText("Tuile non compatible");
        msgBox.setInformativeText("Pose ta tuile à un autre endroit !");
        msgBox.setStandardButtons(QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Cancel);
    }
}

void VuePlateau::poserTuile(int id, int x, int y) {
    tuiles[x+6][y+11]->setTuile(id);
}
