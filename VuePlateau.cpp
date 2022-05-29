//
// Created by Leo Peron on 28/05/2022.
//

#include "VuePlateau.h"

VuePlateau::VuePlateau(QWidget *parent) : QGridLayout(parent){
    for (int i = 0; i < 10; i++) {
        for(int j=0; j <10; j++) {
            tuiles[i][j] = new VueTuile(i,j);
            addWidget(tuiles[i][j], i, j);
        }
    }
    QGridLayout::setSpacing(5);
}

void VuePlateau::test() {
    tuiles[0][0]->setTuile(3);
}