//
// Created by Leo Peron on 27/05/2022.
//

#ifndef TESTING_THINGS_VUEPARTIE_H
#define TESTING_THINGS_VUEPARTIE_H

#include <QWidget>
#include <vector>
#include <set>
#include "VueSettings.h"
#include "VueValider.h"
#include "utils/VuePlateau.h"

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

    QProgressBar* nbCartesPioche;

    QPushButton* settingsBoutton;
    QPushButton* piocherBoutton;
    QPushButton* jouerBoutton;
    QPushButton* groupementBoutton;
    QPushButton* quitterBoutton;

    VueSettings* vueSettings;
    VueValider* vueValider;
    VuePlateau* layoutPlateau;

    QVBoxLayout* layoutButtons;
    QHBoxLayout* layoutLogo;
    QVBoxLayout* layoutPlayer;
    QGridLayout* couche;
public:
    VuePartie(QWidget *parent = nullptr);
    void updatePage(std::string nom);
private slots:
    void cliqueSettings();
    void cliqueJouer();
    void cliquePiocher();
    void cliqueQuitter() { close(); };
};



#endif //TESTING_THINGS_VUEPARTIE_H
