//
// Created by Leo Peron on 11/06/2022.
//

#ifndef LO21_CARCASSONE_VUEPOSEMEEPLE_H
#define LO21_CARCASSONE_VUEPOSEMEEPLE_H

#include <QDialog>
#include <QFormLayout>
#include <QtWidgets>
#include "src/jeu.h"
#include "VueTuile.h"

class VuePoseMeeple : public QDialog
{
    Q_OBJECT

public:
    explicit VuePoseMeeple(VueTuile* vt, QWidget *parent = nullptr);
    ~VuePoseMeeple();

private:

    // Settings to export
    Jeu& j = Jeu::getJeu();

    std::vector<std::pair<QCheckBox*, Element*>> elemsButtons;
    std::vector<std::pair<QCheckBox*, TypeMeeple::points>> meeplesButtons;
    VueTuile* vt;
    // UX
    QPushButton* validerBoutton;
    QPushButton* annulerBoutton;
    QGridLayout* couche;
    QFormLayout* form_joueurs;
private slots:
    void cliquerValider();
    void cliquerAnnuler();
};

#endif //LO21_CARCASSONE_VUEPOSEMEEPLE_H
