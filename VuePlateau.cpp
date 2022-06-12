//
// Created by Leo Peron on 28/05/2022.
//

#include "VuePlateau.h"
#include "VuePoseMeeple.h"
#include "VueGroupement.h"
#include <QFormLayout>
#include <QRadioButton>

VuePlateau::VuePlateau(QWidget *parent) : QGridLayout(parent) {
    for (int i = 0; i < 22; i++) {
        for(int j=0; j < 13; j++) {
            tuiles[i][j] = new VueTuile(j,i);
            addWidget(tuiles[i][j], j, i);
            connect(tuiles[i][j],&VueTuile::tuileClicked, this, &VuePlateau::tuileClick);
        }
    }
}

void VuePlateau::tuileClick(VueTuile* vt) {
    QMessageBox qmsgbox;
    if(j.tuileAction( vt->getVueTuileX(), vt->getVueTuileY())) {

        // Meeple Interaction
        poserTuile(j.getCurrentTuileId(), vt->getVueTuileY(), vt->getVueTuileX());
        qmsgbox.setText("Voulez-vous poser un Meeple ?");
        qmsgbox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        qmsgbox.setDefaultButton(QMessageBox::No);
        int mpl = qmsgbox.exec();
        if(mpl == QMessageBox::Yes)
            poserMeeple(vt);
        else if(j.isPlayerAbbePlaced()) {
            qmsgbox.setText("Voulez-vous rétirer votre Abbé ?");
            qmsgbox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            qmsgbox.setDefaultButton(QMessageBox::No);
            mpl = qmsgbox.exec();
            if(mpl == QMessageBox::Yes) {
                j.retirerPlayerAbbe();
                for (int x = 0; x < 22; x++)
                    for(int y=0; y < 13; y++)
                        tuiles[x][y]->retirerAbbe(j.getCurrentJoueurColor());
            }
        }

        // TRY GROUPEMENT AUTOMATIQUE
        j.checkCurrentTuileGroupements();

        // REMOOVE MEEPLES
        std::vector<pair<int,int>> deletedMeeples = j.getCordsOfDeletedMeeples();
        for(auto it = deletedMeeples.begin(); it != deletedMeeples.end(); it++) {
            tuiles[it->second][it->first]->clearMeeples();
            poserTuile(tuiles[it->second][it->first]->getTuileId(), it->second, it->first);
        }
        // Tour FINI
        j.nextTurn();
        endTour();

        // FIN DU JEU
        if(j.isGameFinished()) {

        }
    } else {
        qmsgbox.setText("Tuile Non Compatible");
        qmsgbox.exec();
    }
}

void VuePlateau::poserTuile(int id, int x, int y) {
    int rotation = (j.getCurrentTuileId() == id)  ? j.getRotation() : 0;
    tuiles[x][y]->setTuile(id, rotation);
}

void VuePlateau::poserMeeple(VueTuile* vt) {
    VuePoseMeeple* pose = new VuePoseMeeple(vt);
    pose->exec();
}

void VuePlateau::groupementFini() {
    VueGroupement* grp = new VueGroupement();
    grp->exec();
}
