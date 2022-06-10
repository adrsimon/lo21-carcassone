//
// Created by Leo Peron on 27/05/2022.
//

#ifndef VUEPARTIE_H
#define VUEPARTIE_H

#include <QWidget>
#include <vector>
#include <set>
#include "VueSettings.h"
#include "VueValider.h"
#include "VuePlateau.h"
//#include "src/jeu.h"

class QLabel;
class QLineEdit;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;
class QProgressBar;
class QLCDNumber;


class VuePartie : public QWidget {
    Q_OBJECT
private:
    bool isPlaying = false;

    Jeu& jeu = Jeu::getJeu();

    QProgressBar* nbCartesPioche;

    QPushButton* settingsBoutton;
    QPushButton* tournerBoutton;
    QPushButton* jouerBoutton;
    QPushButton* groupementBoutton;
    QPushButton* quitterBoutton;

    QLabel* nomJoueur = new QLabel("Joueur x");
    QLabel* meepleRestant = new QLabel("Meeple restants : x");
    QLabel* piocheText = new QLabel("Tuile Restantes: x");
    QLabel* tuileText = new QLabel("Tuile à placer");
    QLabel* tuile = new QLabel();

    VueSettings* vueSettings;
    VueValider* vueValider;
    VuePlateau* layoutPlateau;

    QVBoxLayout* layoutRight;
    QHBoxLayout* couche;
public:
    VuePartie(QWidget *parent = nullptr);
    void updateInfo();
private slots:
    void cliqueSettings();
    void cliqueJouer();
    void cliquePiocher();
    void cliqueQuitter() { close(); };
};



#endif //TESTING_THINGS_VUEPARTIE_H
