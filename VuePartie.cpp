//
// Created by Leo Peron on 27/05/2022.
//

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QProgressBar>
#include <QLCDNumber>
#include <QMessageBox>
#include <iostream>

#include "VuePartie.h"
#include "VueSettings.h"
#include "src/jeu.h"

VuePartie::VuePartie(QWidget *parent): QWidget(parent) {

    // DEFAULT
    vueSettings = nullptr;

    // Title and Picture
    setWindowTitle("Projet LO21 - Carcassonne");
    // Pioche
    nbCartesPioche = new QProgressBar;
    nbCartesPioche->setRange(0, 100);
    nbCartesPioche->setValue(100);
    nbCartesPioche->setTextVisible(false);

    // Buttons
    settingsBoutton = new QPushButton("Paramètres");
    tournerBoutton = new QPushButton("Tourner Tuile");
    jouerBoutton = new QPushButton("Jouer");
    scoreButton = new QPushButton("Score");
    quitterBoutton = new QPushButton("Quitter");

    // Buttons connection
    connect(settingsBoutton, &QPushButton::released, this, &VuePartie::cliqueSettings);
    connect(jouerBoutton, &QPushButton::released, this, &VuePartie::cliqueJouer);
    connect(tournerBoutton, &QPushButton::released, this, &VuePartie::cliqueTourner);
    connect(quitterBoutton, &QPushButton::released, this, &VuePartie::cliqueQuitter);
    connect(scoreButton, &QPushButton::released, this, &VuePartie::cliqueScore);

    // Player information
    QImage* tuileImage = new QImage();
    tuileImage->load("C:/Users/peron/Desktop/runwindows/lo21-carcassone/utils/tiles_illustrations/1.jpeg");
    tuile->setPixmap(QPixmap::fromImage(*tuileImage));

    // LAYOUT BUTTONS
    layoutRight = new QVBoxLayout();
    layoutRight->addWidget(jouerBoutton, 0,Qt::AlignHCenter);
    layoutRight->addWidget(scoreButton, 0, Qt::AlignHCenter);
    layoutRight->addWidget(settingsBoutton, 0,Qt::AlignHCenter);
    layoutRight->addWidget(quitterBoutton, 0,Qt::AlignHCenter);
    layoutRight->addWidget(piocheText, 0, Qt::AlignHCenter);
    layoutRight->addWidget(nbCartesPioche, 0,Qt::AlignHCenter);
    layoutRight->addWidget(tuileText, 0, Qt::AlignHCenter);
    layoutRight->addWidget(tuile, 0,Qt::AlignHCenter);
    layoutRight->addWidget(tournerBoutton, 0,Qt::AlignHCenter);
    layoutRight->addWidget(nomJoueur, 0,Qt::AlignHCenter);
    layoutRight->addWidget(scoreJoueur, 0, Qt::AlignHCenter);
    layoutRight->addWidget(meepleNRestant, 0,Qt::AlignHCenter);
    layoutRight->addWidget(meepleBRestant, 0,Qt::AlignHCenter);
    layoutRight->addWidget(meepleARestant, 0,Qt::AlignHCenter);
    layoutRight->setSpacing(30);

    // Layout Plateau
    layoutPlateau = new VuePlateau();
    connect(layoutPlateau, &VuePlateau::updatePlayers, this, &VuePartie::updateInfo);

    // UI and final layout
    couche = new QHBoxLayout();
    couche->addLayout(layoutPlateau);
    layoutRight->setSpacing(0);
    couche->addLayout(layoutRight);
    setLayout(couche);
    //setStyleSheet("background-color:white; color:black;");
    setFixedSize(1400, 800);

}

void VuePartie::cliqueSettings() {
    if(isPlaying)
        return;
    if(vueSettings == nullptr)
        vueSettings = new VueSettings(this);
    vueSettings->show();
}

void VuePartie::updateInfo() {
    std::string str = "Joueur: " + jeu.getCurrentJoueur()->getNom();
    nomJoueur->setText(QString::fromStdString(str));
    str = "Score: " + std::to_string(jeu.getCurrentJoueur()->getScore());
    scoreJoueur->setText(QString::fromStdString(str));
    str =  std::to_string(jeu.getTuilesAmount()) + " Tuiles dans la pioche";
    piocheText->setText(QString::fromStdString(str));
    auto meeples = jeu.getPlayerMeeplesAmount();
    for(auto it = meeples.begin(); it != meeples.end(); it++) {
        switch(it->first) {
            case TypeMeeple::normal:
                str = "Meeples Normaux restants: " + std::to_string(it->second);
                meepleNRestant->setText(QString::fromStdString(str));
                break;
            case TypeMeeple::big:
                str = "Meeples Big restants: " + std::to_string(it->second);
                meepleBRestant->setText(QString::fromStdString(str));
                break;
            case TypeMeeple::abbe:
                str = "Meeples Abbe restants: " + std::to_string(it->second);
                meepleARestant->setText(QString::fromStdString(str));
                break;
        }
    }
    QImage* tuileImage = new QImage();
    str = "C:/Users/peron/Desktop/runwindows/lo21-carcassone/utils/tiles_illustrations/" + std::to_string(jeu.getCurrentTuileId()) + ".jpeg";
    tuileImage->load(QString::fromStdString(str));
    tuile->setPixmap(QPixmap::fromImage(*tuileImage));
    nbCartesPioche->setValue(jeu.getTuilesAmount());
    update();
}

void VuePartie::cliqueJouer() {
    if(vueSettings == nullptr)
        return;
    if(!isPlaying) {
        layoutPlateau->poserTuile(jeu.getFirstTuileId(), 11, 6);
        nbCartesPioche->setRange(0, jeu.getTuilesAmount());
        nbCartesPioche->setValue(jeu.getTuilesAmount());
    }
    updateInfo();
    isPlaying=true;

}

void VuePartie::cliqueTourner() {
    if(!isPlaying)
        return;
    QPixmap pixmap(tuile->pixmap());
    QTransform t;
    pixmap = pixmap.transformed(t.rotate(90));
    tuile->setPixmap(pixmap);
    jeu.rotateTuile();
}

void VuePartie::cliqueScore() {
    if(!isPlaying)
        return;
    QMessageBox qmsg;
    qmsg.setText("Scores des joueurs");
    std::list<Joueur*> joueurs = jeu.getJoueurs();
    std::string str;
    for(auto it = joueurs.begin(); it != joueurs.end(); it++) {
        str+= (*it)->getNom() + " (" + TypeCouleur::toString((*it)->getCouleur()) + ") - " + std::to_string((*it)->getScore()) + " points \n";
    }
    qmsg.setInformativeText(QString::fromStdString(str));
    qmsg.exec();
}
