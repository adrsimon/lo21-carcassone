//
// Created by Leo Peron on 28/05/2022.
//

#include <iostream>
#include "VueTuile.h"

VueTuile::VueTuile(QWidget *parent, size_t id) : x(x), y(y), id(id),QPushButton(parent) {
    setStyleSheet("background-color: black;");
}

void VueTuile::setTuile(const size_t newId) {
    id = newId;
    QImage* img = new QImage();
    img->load(":/utils/illu-main/1.jpeg");
}