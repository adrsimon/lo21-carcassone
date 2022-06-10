//
// Created by Leo Peron on 28/05/2022.
//

#ifndef VUEPLATEAU_H
#define VUEPLATEAU_H

#include <QGridLayout>
#include <QMessageBox>
#include "VueTuile.h"
#include "src/jeu.h"

class VuePlateau : public QGridLayout {
    Q_OBJECT
public:
    explicit VuePlateau(QWidget *parent = nullptr);
    void poserTuile(int id, int x, int y);

private:
    VueTuile* tuiles[20][20];
    void tuileClick(VueTuile* vt);
    Jeu& j = Jeu::getJeu();
signals:
    void attemptToPutTuile();
};

#endif //TESTING_THINGS_VUEPLATEAU_H
