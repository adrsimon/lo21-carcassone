//
// Created by Leo Peron on 11/06/2022.
//

#include "VuePoseMeeple.h"

VuePoseMeeple::VuePoseMeeple(VueTuile* vt, QWidget *parent) : vt(vt), QDialog(parent) {

    setWindowTitle("Element sur lequel poser un Meeple ?");

    // Displaying Buttons
    QPushButton* validerBoutton = new QPushButton("Valider");
    QPushButton* annulerBoutton = new QPushButton("Annuler");

    QHBoxLayout* layoutBouttons  = new QHBoxLayout();
    layoutBouttons->addWidget(validerBoutton);
    layoutBouttons->addWidget(annulerBoutton);

    QVBoxLayout* elemsdisplay = new QVBoxLayout();
    QLabel* titreElement = new QLabel("Liste des Elements");

    QVBoxLayout* meeplesdisplay = new QVBoxLayout();
    QLabel* titreMeeple = new QLabel("Liste des Meeples");


    elemsdisplay->addWidget(titreElement);
    meeplesdisplay->addWidget(titreMeeple);

    // Générations des éléments
    std::list<Element*> elems = j.getCurrentTuileElements();
    for(auto it = elems.begin(); it != elems.end(); it ++) {
        std::string str = TypeElement::toString((*it)->getType());
        std::list<TypeCardinaux::points> orients = (*it)->getOrientations();
        for(auto it2 = orients.begin(); it2 != orients.end(); it2++)
            str += " - "  + TypeCardinaux::toString(*it2);
        elemsButtons.push_back(pair<QCheckBox*, Element*>(new QCheckBox(QString::fromStdString(str)), *it));
        elemsdisplay->addWidget(elemsButtons.back().first);
    }

    // Générations des meeples
    auto meeples = j.getPlayerMeeplesAmount();
    for(auto it = meeples.begin(); it != meeples.end(); it++) {
        std::cout << TypeMeeple::toString((it->first)) << std::endl;
        std::string str = TypeMeeple::toString((it->first)) + " - " + to_string(it->second) + " restants";
        meeplesButtons.push_back(pair<QCheckBox*, TypeMeeple::points>(new QCheckBox(QString::fromStdString(str)), it->first));
        meeplesdisplay->addWidget(meeplesButtons.back().first);
    }

    connect(validerBoutton, &QPushButton::released, this, &VuePoseMeeple::cliquerValider);
    connect(annulerBoutton, &QPushButton::released, this, &VuePoseMeeple::cliquerAnnuler);

    couche = new QGridLayout();

    couche->addLayout(elemsdisplay, 0, 0);
    couche->addLayout(meeplesdisplay, 0, 1);
    couche->addLayout(layoutBouttons, 1, 1);

    setLayout(couche);

}

void VuePoseMeeple::cliquerValider() {
    Element* e;
    for(auto it = elemsButtons.begin(); it != elemsButtons.end(); it++)
        if(it->first->isChecked())
            e = it->second;
    TypeMeeple::points t;
    for(auto it = meeplesButtons.begin(); it != meeplesButtons.end(); it++)
        if(it->first->isChecked())
            t = it->second;

        if(j.meepleAction(e,t)) {
            QMessageBox qmsgbox;
            qmsgbox.setText("Meeple Posé !");
            qmsgbox.exec();
            vt->addMeeple(e->getOrientations().front(), j.getCurrentJoueurColor(), t);
            vt->update();
            close();
        } else {
            QMessageBox qmsgbox;
            qmsgbox.setText("Action Impossible, Veuillez recommencer");
            qmsgbox.exec();
        }
}

void VuePoseMeeple::cliquerAnnuler() {
    close();
}

VuePoseMeeple::~VuePoseMeeple() noexcept {}