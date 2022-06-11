//
// Created by Leo Peron on 11/06/2022.
//

#ifndef LO21_CARCASSONE_VUEPOSEMEEPLE_H
#define LO21_CARCASSONE_VUEPOSEMEEPLE_H

#include <QDialog>
#include <QFormLayout>
#include <QtWidgets>
#include "src/jeu.h"

class VuePoseMeeple : public QDialog
{
    Q_OBJECT

public:
    explicit VuePoseMeeple(QWidget *parent = nullptr);
    ~VuePoseMeeple();

private:

    // Settings to export
    Jeu& j = Jeu::getJeu();

    std::vector<pair<QCheckBox*, Element*>> elemsButtons;
    std::vector<pair<QCheckBox*, TypeMeeple::points>> meeplesButtons;
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
