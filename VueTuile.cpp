//
// Created by Leo Peron on 28/05/2022.
//

#include "VueTuile.h"

VueTuile::VueTuile(int x, int y, QWidget *parent, size_t id) : x(x), y(y), id(id),QPushButton(parent) {
    setFixedSize(45,45);
    setStyleSheet("background-color: white;");
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(true);
}

void VueTuile::setTuile(const size_t newId) {
    std::string str  = "/Users/leo/Documents/UTC/LO21/lo21-carcassone/utils/tiles_illustrations/" + std::to_string(newId) + ".jpeg";
    QImage* img = new QImage();
    img->load(QString::fromStdString(str));
    setIcon(QPixmap::fromImage(*img));
    setIconSize(QSize(43,43));
    update();
}