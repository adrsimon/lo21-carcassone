//
// Created by Leo Peron on 11/06/2022.
//

#include "VueGroupement.h"

VueGroupement::VueGroupement(QWidget *parent) : QDialog(parent) {

    setWindowTitle("Liste des groupements non finis");

    // Displaying Buttons
    QPushButton* validerBoutton = new QPushButton("Valider");
    QPushButton* annulerBoutton = new QPushButton("Annuler");

    QHBoxLayout* layoutBouttons  = new QHBoxLayout();
    layoutBouttons->addWidget(validerBoutton);
    layoutBouttons->addWidget(annulerBoutton);

    QVBoxLayout* groupementsdisplay = new QVBoxLayout();
    QLabel* titreGroupement = new QLabel("Liste des Groupements non finis");

    groupementsdisplay->addWidget(titreGroupement);

    // Générations des groupements
    auto grps = j.getCurrentTuileGroupements();
    for(auto it = grps.begin(); it != grps.end(); it++) {
        std::string str = TypeElement::toString((*it)->getType()) + " - " + to_string((*it)->getElements().size()) + " éléments";
        grpsButtons.push_back(pair<QCheckBox*, Groupement*>(new QCheckBox(QString::fromStdString(str)), *it));
        groupementsdisplay->addWidget(grpsButtons.back().first);
    }


    connect(validerBoutton, &QPushButton::released, this, &VueGroupement::cliquerValider);
    connect(annulerBoutton, &QPushButton::released, this, &VueGroupement::cliquerAnnuler);

    couche = new QVBoxLayout();

    couche->addLayout(groupementsdisplay);
    couche->addLayout(layoutBouttons);

    setLayout(couche);

}

void VueGroupement::cliquerValider() {
}

void VueGroupement::cliquerAnnuler() {
    close();
}

VueGroupement::~VueGroupement() noexcept {}
