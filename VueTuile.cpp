//
// Created by Leo Peron on 28/05/2022.
//

#include "VueTuile.h"

VueTuile::VueTuile(int x, int y, QWidget *parent, size_t id) : x(x), y(y), id(id),QPushButton(parent) {
    setFixedSize(50,50);
    connect(this,&QPushButton::clicked,this,&VueTuile::test);
}

void VueTuile::setTuile(const size_t newId) {
    id = newId;
    QImage* img = new QImage();
    img->load(":/utils/illu-main/1.jpeg");
    setIcon(QPixmap::fromImage(*img));
    update();
}

void VueTuile::test() {
    QImage* img = new QImage();
    img->load("/Users/leo/Documents/UTC/LO21/testing things/utils/1.jpeg");
    setIcon(QPixmap::fromImage(*img));
    setIconSize(QPixmap::fromImage(*img).rect().size());
    update();
}