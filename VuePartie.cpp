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
    groupementBoutton = new QPushButton("Grouper");
    quitterBoutton = new QPushButton("Quitter");

    // Buttons connection
    connect(settingsBoutton, &QPushButton::released, this, &VuePartie::cliqueSettings);
    connect(jouerBoutton, &QPushButton::released, this, &VuePartie::cliqueJouer);
    connect(tournerBoutton, &QPushButton::released, this, &VuePartie::cliqueTourner);
    connect(quitterBoutton, &QPushButton::released, this, &VuePartie::cliqueQuitter);

    // Player information
    QImage* tuileImage = new QImage();
    tuileImage->load("/Users/leo/Documents/UTC/LO21/lo21-carcassone/utils/tiles_illustrations/1.jpeg");
    tuile->setPixmap(QPixmap::fromImage(*tuileImage));

    // LAYOUT BUTTONS
    layoutRight = new QVBoxLayout();
    layoutRight->addWidget(jouerBoutton, 0,Qt::AlignHCenter);
    layoutRight->addWidget(settingsBoutton, 0,Qt::AlignHCenter);
    layoutRight->addWidget(groupementBoutton, 0,Qt::AlignHCenter);
    layoutRight->addWidget(quitterBoutton, 0,Qt::AlignHCenter);
    layoutRight->addWidget(piocheText, 0, Qt::AlignHCenter);
    layoutRight->addWidget(nbCartesPioche, 0,Qt::AlignHCenter);
    layoutRight->addWidget(tuileText, 0, Qt::AlignHCenter);
    layoutRight->addWidget(tuile, 0,Qt::AlignHCenter);
    layoutRight->addWidget(tournerBoutton, 0,Qt::AlignHCenter);
    layoutRight->addWidget(nomJoueur, 0,Qt::AlignHCenter);
    layoutRight->addWidget(meepleRestant, 0,Qt::AlignHCenter);
    layoutRight->setSpacing(30);

    // Layout Plateau
    layoutPlateau = new VuePlateau();
    connect(layoutPlateau, &VuePlateau::updatePlayers, this, &VuePartie::updateInfo);

    // UI and final layout
    couche = new QHBoxLayout();
    couche->addLayout(layoutPlateau);
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
    str =  to_string(jeu.getTuilesAmount()) + " Tuiles dans la pioche";
    piocheText->setText(QString::fromStdString(str));
    std::cout << "Tuile à jouer: " << jeu.getCurrentTuileId() << std::endl;
    QImage* tuileImage = new QImage();
    str = "/Users/leo/Documents/UTC/LO21/lo21-carcassone/utils/tiles_illustrations/" + to_string(jeu.getCurrentTuileId()) + ".jpeg";
    tuileImage->load(QString::fromStdString(str));
    tuile->setPixmap(QPixmap::fromImage(*tuileImage));
    nbCartesPioche->setValue(jeu.getTuilesAmount());
    update();
}

void VuePartie::cliqueJouer() {
    if(vueSettings == nullptr)
        return;
    if(!isPlaying) {
        layoutPlateau->poserTuile(jeu.getFirstTuileId(), 0, 0);
        nbCartesPioche->setRange(0, jeu.getTuilesAmount());
        nbCartesPioche->setValue(jeu.getTuilesAmount());
    }
    updateInfo();
    isPlaying=true;

}

void VuePartie::cliqueTourner() {
    QPixmap pixmap(tuile->pixmap());
    QTransform t;
    pixmap = pixmap.transformed(t.rotate(90));
    tuile->setPixmap(pixmap);
    jeu.rotateTuile();
}