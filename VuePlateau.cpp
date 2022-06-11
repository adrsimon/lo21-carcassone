//
// Created by Leo Peron on 28/05/2022.
//

#include "VuePlateau.h"
#include "VuePoseMeeple.h"
#include <QFormLayout>
#include <QRadioButton>

VuePlateau::VuePlateau(QWidget *parent) : QGridLayout(parent){
    for (int i = 0; i < 13; i++) {
        for(int j=0; j <22; j++) {
            tuiles[i][j] = new VueTuile(j-11,-(i-6));
            addWidget(tuiles[i][j], i, j);
            connect(tuiles[i][j],&VueTuile::tuileClicked, this, &VuePlateau::tuileClick);
        }
    }
}

void VuePlateau::tuileClick(VueTuile* vt) {
    std::cout <<  vt->getVueTuileX() << vt->getVueTuileY() << std::endl;
    QMessageBox qmsgbox;
    if(j.tuileAction( vt->getVueTuileX(), vt->getVueTuileY())) {
        poserTuile(j.getCurrentTuileId(), vt->getVueTuileX(), vt->getVueTuileY());
        qmsgbox.setText("Voulez-vous poser un Meeple ?");
        qmsgbox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        qmsgbox.setDefaultButton(QMessageBox::No);
        int mpl = qmsgbox.exec();
        if(mpl == QMessageBox::Yes)
            poserMeeple();
        j.nextTurn();
        endTour();
    } else {
        QMessageBox qmsgbox;
        qmsgbox.setText("Tuile Non Compatible");
        qmsgbox.exec();
    }
}

void VuePlateau::poserTuile(int id, int x, int y) {
    tuiles[-y+6][x+11]->setTuile(id, j.getRotation());
}

void VuePlateau::poserMeeple() {
    VuePoseMeeple* pose = new VuePoseMeeple();
    pose->exec();
}
