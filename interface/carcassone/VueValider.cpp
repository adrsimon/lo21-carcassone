//
// Created by Leo Peron on 28/05/2022.
//

#include <QPushButton>
#include <QtWidgets>
#include <QHBoxLayout>

#include "VueValider.h"

VueValider::VueValider(QWidget *parent) : QDialog(parent) {

    setWindowTitle("Voulez-vous valider votre choix ?");

    ouiBoutton = new QPushButton("Oui");
    nonBoutton = new QPushButton("Non");

    connect(ouiBoutton, &QPushButton::released, this, &VueValider::cliquerOui);
    connect(nonBoutton, &QPushButton::released, this, &VueValider::cliquerNon);

    grid = new QHBoxLayout();
    grid->addWidget(ouiBoutton);
    grid->addWidget(nonBoutton);

    setLayout(grid);
}

VueValider::~VueValider() {}

void VueValider::cliquerOui() {
    result = true;
    close();
}

void VueValider::cliquerNon() {
    result = false;
    close();
}