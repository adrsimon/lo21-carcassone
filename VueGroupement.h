//
// Created by Leo Peron on 11/06/2022.
//

#ifndef LO21_CARCASSONE_VUEGROUPEMENT_H
#define LO21_CARCASSONE_VUEGROUPEMENT_H

#include <QDialog>
#include <QFormLayout>
#include <QtWidgets>
#include "src/jeu.h"

class VueGroupement : public QDialog
{
    Q_OBJECT

public:
    explicit VueGroupement(QWidget *parent = nullptr);
    ~VueGroupement();

private:

    // Settings to export
    Jeu& j = Jeu::getJeu();

    std::vector<pair<QCheckBox*, Groupement*>> grpsButtons;
    // UX
    QPushButton* validerBoutton;
    QPushButton* annulerBoutton;
    QVBoxLayout* couche;
    QFormLayout* form_joueurs;
private slots:
    void cliquerValider();
    void cliquerAnnuler();
};

#endif //LO21_CARCASSONE_VUEGROUPEMENT_H
