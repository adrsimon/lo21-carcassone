#include "VueSettings.h"
#include <QPushButton>
#include <QtWidgets>
#include <QHBoxLayout>

VueSettings::VueSettings(QWidget *parent) : QDialog(parent) {

    setWindowTitle("Paramètres Carcassone");

    // Displaying Buttons
    validerBoutton = new QPushButton("Valider");
    annulerBoutton = new QPushButton("Annuler");

    layoutBouttons = new QHBoxLayout();
    layoutBouttons->addWidget(validerBoutton);
    layoutBouttons->addWidget(annulerBoutton);

    form_joueurs = new QFormLayout();

    // Displaying Players
    QLabel* titreJoueur = new QLabel("Liste des joueurs");
    QString displayJoueurs[6];
    form_joueurs->addWidget(titreJoueur);
    for(int i=0; i<6; i++) {
        std::string str = "Joueur " + std::to_string(i+1);
        displayJoueurs[i] = QString::fromStdString(str);
        joueurs[i] = new QLineEdit(displayJoueurs[i]);
        form_joueurs->addRow(displayJoueurs[i], joueurs[i]);
    }

    // Displaying Extensions
    QLabel* titreExtensions = new QLabel("Liste des Extensions");
    QCheckBox* extensions[2];
    layoutExtensions = new QVBoxLayout();
    layoutExtensions->addWidget(titreExtensions);
    extensions[0] = new QCheckBox("Rivière");
    extensions[1] = new QCheckBox("Auberge");

    for(int i=0; i<2; i++) {
        layoutExtensions->addWidget(extensions[i]);
    }

    couche = new QGridLayout;

    couche->addLayout(form_joueurs, 0, 0);
    couche->addLayout(layoutExtensions, 0, 1);
    couche->addLayout(layoutBouttons, 1, 1);

    setLayout(couche);

    connect(validerBoutton, &QPushButton::released, this, &VueSettings::cliquerValider);
    connect(annulerBoutton, &QPushButton::released, this, &VueSettings::cliquerAnnuler);

}

void VueSettings::cliquerValider() {
    // Saving joueurs Names
    for (int i = 0; i < 6; i++) {
        if(joueurs[i]->text().toStdString() != "")
            nomJoueurs.push_back(joueurs[i]->text().toStdString());
    }
    bool r = *extensions.begin();
    extensions.begin()++;
    bool ac = *extensions.begin();

    std::vector<TypeCouleur::points> couleurs = {
            TypeCouleur::rouge, TypeCouleur::bleu, TypeCouleur::vert, TypeCouleur::jaune, TypeCouleur::rose, TypeCouleur::orange
    };

    Jeu& j=Jeu::getJeu();
    j.initialiser(nomJoueurs,couleurs,true,r,ac);

    close();

}

void VueSettings::cliquerAnnuler() {
    close();
}

VueSettings::~VueSettings() {}


