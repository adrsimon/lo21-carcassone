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

VuePartie::VuePartie() {
    createToolBox();
    //affichagePlacerMeeple();
    //affichageGroupementFini();

    setWindow
    //Plateau
    scene = new VuePlateau(this,tuile);
    scene->setSceneRect(QRectF(0,0,500,500));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(toolBox);
    view = new QGraphicsView(scene);
    layout->addWidget(view);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    setCentralWidget(widget);
    setWindowTitle(tr("Carcassone"));

    //connect(scene, SIGNAL(itemInserted(VuePlateau*)),this, SLOT(itemInserted(VuePlateau*)));
    //connect(scene, SIGNAL(textInserted(QGraphicsTextItem*)), this, SLOT(textInserted(QGraphicsTextItem*)));
    connect(scene, SIGNAL(itemSelected(QGraphicsItem*)), this, SLOT(itemSelected(QGraphicsItem*)));

}

void VuePartie::createToolBox(){
    // DEFAULT
    vueSettings = nullptr;

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
    rotationDroite = new QPushButton("Rotation Tuile");
    quitterBoutton = new QPushButton("Quitter");

    // Buttons connection
    connect(settingsBoutton, &QPushButton::released, this, &VuePartie::cliqueSettings);
    connect(jouerBoutton, &QPushButton::released, this, &VuePartie::cliqueJouer);
    connect(piocherBoutton, &QPushButton::released, this, &VuePartie::cliquePiocher);
    connect(rotationDroite, &QPushButton::released, this, &VuePartie::cliqueRotate);
    connect(quitterBoutton, &QPushButton::released, this, &VuePartie::cliqueQuitter);

    // Player information
    QImage* tuileImage = new QImage();
    tuileImage->load("utils/tiles_illustrations/1.jpeg");
    tuile = new QLabel();
    tuile->setPixmap(QPixmap::fromImage(*tuileImage));
    QLabel* nomJoueur = new QLabel("Joueur x");
    QLabel* meepleRestant = new QLabel("Meeple restants : x");
    QLabel* piocheText = new QLabel("Tuile Restantes: x");
    QLabel* tuileText = new QLabel("Tuile à placer");

    /*
    // HEADER LAYOUT
    layoutLogo = new QHBoxLayout();
    layoutLogo->addWidget(header, 0, Qt::AlignHCenter);
    */

    // LAYOUT
    layout = new QVBoxLayout();
    layout->addWidget(piocheText, 0, Qt::AlignHCenter);
    layout->addWidget(nbCartesPioche, 0,Qt::AlignHCenter);
    layout->addWidget(tuileText, 0, Qt::AlignHCenter);
    layout->addWidget(rotationDroite, 0, Qt::AlignHCenter);
    layout->addWidget(tuile, 0,Qt::AlignHCenter);
    layout->addWidget(nomJoueur, 0,Qt::AlignHCenter);
    layout->addWidget(meepleRestant, 0,Qt::AlignHCenter);
    layout->addWidget(piocherBoutton, 0,Qt::AlignHCenter);
    layout->addWidget(jouerBoutton, 0,Qt::AlignHCenter);
    layout->addWidget(groupementBoutton, 0,Qt::AlignHCenter);
    layout->addWidget(settingsBoutton, 0,Qt::AlignHCenter);
    layout->addWidget(quitterBoutton, 0,Qt::AlignHCenter);


    layout->setSpacing(20);


    QWidget *itemWidget=new QWidget;
    itemWidget->setLayout(layout);

    toolBox = new QToolBox;
    toolBox->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Ignored));
    toolBox->setMinimumWidth(itemWidget->sizeHint().width());

    toolBox->addItem(itemWidget,tr("Placer Tuile"));


    // Layout Plateau
    //layoutPlateau = new VuePlateau(parent());

    /*
    // UI and final layout
    couche = new QGridLayout();
    //couche->addLayout(layoutLogo, 0, 0, 2, 0);
    //couche->addLayout(layoutPlateau, 0, 0);
    couche->addLayout(layoutButtons, 1, 1);
    couche->addLayout(layoutPlayer, 0, 1);
    setLayout(couche);
    //setStyleSheet("background-color:white; color:black;");
    setFixedSize(1100, 750);
    */
}

/*
void VuePartie::createMenu(){

}
*/


/*
VuePartie::VuePartie(QWidget *parent): QWidget(parent) {


}
*/

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
    std::vector<std::string> raw = vueSettings->getNomJoueurs();
    for(auto it = raw.begin(); it != raw.end(); it++)
        std::cout << "Joueur:" << *it << std::endl;
}

void VuePartie::cliquePiocher() {
    delete vueValider;
    vueValider = new VueValider(this);
    vueValider->show();
    std::cout << vueValider->getResult() << std::endl;
}

void VuePartie::cliqueRotate(){
    QPixmap pixmap(tuile->pixmap());
    QTransform t;
    pixmap = pixmap.transformed(t.rotate(90));
    tuile->setPixmap(pixmap);
}

void VuePartie::affichagePlacerMeeple(){
    QLabel* nomJoueur = new QLabel("Joueur x");
    QLabel* titreTypeMeeple = new QLabel("Poser un meeple ?");
    QCheckBox* typeMeeple[4];
    typeMeeple[0] = new QCheckBox("Meeple Normal");
    typeMeeple[1] = new QCheckBox("Meeple Abbé");
    typeMeeple[2] = new QCheckBox("Big Meeple");
    typeMeeple[3] = new QCheckBox("Aucun");
    layout = new QVBoxLayout();
    layout->addWidget(nomJoueur);
    layout->addWidget(titreTypeMeeple);
    for (int i=0; i<4; i++){
        layout->addWidget(typeMeeple[i]);
    }

    QLabel* titreLieuMeeple = new QLabel("Ou le poser ?");
    QCheckBox* lieuMeeple[4];
    lieuMeeple[0] = new QCheckBox("Route");
    lieuMeeple[1] = new QCheckBox("Ville");
    lieuMeeple[2] = new QCheckBox("Pré");
    lieuMeeple[3] = new QCheckBox("Nulle part");
    layout->addWidget(titreLieuMeeple);
    for (int i=0; i<4; i++){
        layout->addWidget(lieuMeeple[i]);
    }

    validerMeeple = new QPushButton("Valider");
    layout->addWidget(validerMeeple);
    connect(validerMeeple, &QPushButton::released, this, &VuePartie::validerPlacerMeeple);

    layout->setSpacing(20);

    QWidget *itemWidget=new QWidget;
    itemWidget->setLayout(layout);

    toolBox = new QToolBox;
    toolBox->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Ignored));
    toolBox->setMinimumWidth(itemWidget->sizeHint().width());
    toolBox->addItem(itemWidget,tr("Poser Meeple"));

}

void VuePartie::affichageGroupementFini(){
    QLabel* nomJoueur = new QLabel("Joueur x");
    QLabel* titreGroupementFini = new QLabel("Groupement fini ?");
    QCheckBox* groupementFini[4];
    groupementFini[0] = new QCheckBox("Route");
    groupementFini[1] = new QCheckBox("Ville");
    groupementFini[2] = new QCheckBox("Abbaye");
    groupementFini[3] = new QCheckBox("Aucun");
    layout = new QVBoxLayout();
    layout->addWidget(nomJoueur);
    layout->addWidget(titreGroupementFini);
    for (int i=0; i<4; i++){
        layout->addWidget(groupementFini[i]);
    }

    validerGroupement = new QPushButton("Valider");
    layout->addWidget(validerGroupement);
    connect(validerGroupement, &QPushButton::released, this, &VuePartie::validerGroupementFini);

    layout->setSpacing(20);


    QWidget *itemWidget=new QWidget;
    itemWidget->setLayout(layout);

    toolBox = new QToolBox;
    toolBox->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Ignored));
    toolBox->setMinimumWidth(itemWidget->sizeHint().width());
    toolBox->addItem(itemWidget,tr("Groupement Fini"));

}

void VuePartie::validerPlacerMeeple(){
    affichageGroupementFini();
}

void VuePartie::validerGroupementFini(){
    createToolBox();
}
