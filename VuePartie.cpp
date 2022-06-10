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
    QImage* logo = new QImage();
    logo->load("/Users/leo/Documents/UTC/LO21/testing things/utils/carcassonelogo.png");
    QLabel* header = new QLabel();
    header->setPixmap(QPixmap::fromImage(*logo));
    header->resize(1100, 600);

    // Pioche
    nbCartesPioche = new QProgressBar;
    nbCartesPioche->setRange(0, 100);
    nbCartesPioche->setValue(45);
    nbCartesPioche->setTextVisible(false);

    // Buttons
    settingsBoutton = new QPushButton("Paramètres");
    piocherBoutton = new QPushButton("Piocher");
    jouerBoutton = new QPushButton("Jouer");
    groupementBoutton = new QPushButton("Grouper");
    quitterBoutton = new QPushButton("Quitter");

    // Buttons connection
    connect(settingsBoutton, &QPushButton::released, this, &VuePartie::cliqueSettings);
    connect(jouerBoutton, &QPushButton::released, this, &VuePartie::cliqueJouer);
    connect(piocherBoutton, &QPushButton::released, this, &VuePartie::cliquePiocher);
    connect(quitterBoutton, &QPushButton::released, this, &VuePartie::cliqueQuitter);

    // Player information
    QImage* tuileImage = new QImage();
    tuileImage->load("/Users/leo/Documents/UTC/LO21/lo21-carcassone/utils/tiles_illustrations/1.jpeg");
    QLabel* tuile = new QLabel();
    tuile->setPixmap(QPixmap::fromImage(*tuileImage));
    QLabel* nomJoueur = new QLabel("Joueur x");
    QLabel* meepleRestant = new QLabel("Meeple restants : x");
    QLabel* piocheText = new QLabel("Tuile Restantes: x");
    QLabel* tuileText = new QLabel("Tuile à placer");

    // LAYOUT BUTTONS
    layoutRight = new QVBoxLayout();
    layoutRight->addWidget(piocherBoutton, 0,Qt::AlignHCenter);
    layoutRight->addWidget(jouerBoutton, 0,Qt::AlignHCenter);
    layoutRight->addWidget(settingsBoutton, 0,Qt::AlignHCenter);
    layoutRight->addWidget(groupementBoutton, 0,Qt::AlignHCenter);
    layoutRight->addWidget(quitterBoutton, 0,Qt::AlignHCenter);
    layoutRight->addWidget(piocheText, 0, Qt::AlignHCenter);
    layoutRight->addWidget(nbCartesPioche, 0,Qt::AlignHCenter);
    layoutRight->addWidget(tuileText, 0, Qt::AlignHCenter);
    layoutRight->addWidget(tuile, 0,Qt::AlignHCenter);
    layoutRight->addWidget(nomJoueur, 0,Qt::AlignHCenter);
    layoutRight->addWidget(meepleRestant, 0,Qt::AlignHCenter);
    layoutRight->setSpacing(30);

    // Layout Plateau
    layoutPlateau = new VuePlateau();


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

void VuePartie::cliqueJouer() {
    if(vueSettings == nullptr)
        return;
    isPlaying=true;
    std::cout << "je suis la " << std::endl;
    layoutPlateau->poserTuile(jeu.getFirstTuileId(), 0, 0);
}

void VuePartie::cliquePiocher() {
    delete vueValider;
    vueValider = new VueValider(this);
    vueValider->show();
    std::cout << vueValider->getResult() << std::endl;
}