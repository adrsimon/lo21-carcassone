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
    void poserMeeple();

private:
    VueTuile* tuiles[20][20];
    Jeu& j = Jeu::getJeu();
private slots:
    void tuileClick(VueTuile* vt);
    void endTour() { emit updatePlayers(); }
signals:
    void updatePlayers();
};

#endif //TESTING_THINGS_VUEPLATEAU_H
