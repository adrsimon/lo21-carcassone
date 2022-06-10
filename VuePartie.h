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
#include "src/jeu.h"

class VuePartie : public QMainWindow
{
Q_OBJECT
private:
    VuePlateau *scene;
    QGraphicsView *view;

    QMenu *itemMenu;
    QToolBox *toolBox;
    bool isPlaying = false;

    Jeu& jeu = Jeu::getJeu();

    QProgressBar* nbCartesPioche;

    QPushButton* settingsBoutton;
    QPushButton* piocherBoutton;
    QPushButton* jouerBoutton;
    QPushButton* groupementBoutton;
    QPushButton* quitterBoutton;
    QPushButton* rotationDroite;
    QPushButton* validerMeeple;
    QPushButton* validerGroupement;

    VueSettings* vueSettings;
    VueValider* vueValider;

    QVBoxLayout* layout;

    /*
    QVBoxLayout* layoutButtons;
    QHBoxLayout* layoutLogo;
    QVBoxLayout* layoutPlayer;
    QGridLayout* couche;
    */

    QLabel* tuile;
public:
    VuePartie();
    VuePlateau* getScene() const {return scene;}

    void createToolBox();
    /*
    VuePartie(QWidget *parent = nullptr);
    void updatePage(std::string nom);
    */
private slots:
    void itemSelected(QGraphicsItem *item) {}

    void cliqueSettings();
    void cliqueJouer();
    void cliquePiocher();
    void cliqueRotate();
    void cliqueQuitter() { close(); };
    void affichagePlacerMeeple();
    void affichageGroupementFini();
    void validerPlacerMeeple();
    void validerGroupementFini();
};





#endif //TESTING_THINGS_VUEPARTIE_H
