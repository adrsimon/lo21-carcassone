//
// Created by Leo Peron on 27/05/2022.
//

#ifndef VUEPARTIE_H
#define VUEPARTIE_H

#include <QWidget>
#include <vector>
#include <set>
#include "VueSettings.h"
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
    QPushButton* quitterBoutton;

    QLabel* nomJoueur = new QLabel("Joueur: X");
    QLabel* scoreJoueur = new QLabel("Score: X");
    QLabel* meepleNRestant = new QLabel("Meeples Normaux restants: X");
    QLabel* meepleBRestant = new QLabel("Meeples Big restants: X");
    QLabel* meepleARestant = new QLabel("Meeples Abbe restants: X");
    QLabel* piocheText = new QLabel("Tuile Restantes: X");
    QLabel* tuileText = new QLabel("Tuile à placer");
    QLabel* tuile = new QLabel();

    VueSettings* vueSettings;
    VuePlateau* layoutPlateau;

    QVBoxLayout* layoutRight;
    QHBoxLayout* couche;
public:
    VuePartie(QWidget *parent = nullptr);
    void updateInfo();
private slots:
    void cliqueSettings();
    void cliqueJouer();
    void cliqueQuitter() { close(); };

    void cliqueTourner();
};



#endif //TESTING_THINGS_VUEPARTIE_H
