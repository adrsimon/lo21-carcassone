//
// Created by Leo Peron on 28/05/2022.
//

#include <QPainter>
#include "VueTuile.h"
#include <iostream>

VueTuile::VueTuile(int x, int y, QWidget *parent, size_t id, int rot) : x(x), y(y), id(id), rotation(rot), QPushButton(parent) {
    setFixedSize(45,45);
    setStyleSheet("background-color: white;");
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(true);
}

void VueTuile::setTuile(const size_t newId, const int rot) {
    id = newId;
    if(rot !=0)
        rotation = rot;
    updateTuilePicture();
}

void VueTuile::updateTuilePicture() {
    std::string str  = "/Users/leo/Documents/UTC/LO21/lo21-carcassone/utils/tiles_illustrations/" + std::to_string(id) + ".jpeg";
    QImage* img = new QImage();
    img->load(QString::fromStdString(str));
    QPixmap pix = QPixmap::fromImage(*img);
    QTransform t;
    pix = pix.transformed(t.rotate(90*rotation));
    setIcon(pix);
    setIconSize(QSize(44,44));
    update();
}

void VueTuile::clearMeeples() {
    if(meeples.size() != 0) {
        meeples.clear();
        cleared=true;
    }
}

void VueTuile::paintEvent(QPaintEvent* e)
{
    QPushButton::paintEvent(e);
    QPainter painter(this);

    if(cleared)
        return;

    if(removingAbbe) {
        removingAbbe = false;
        return;
    }

    for(auto it = meeples.begin(); it != meeples.end(); it++) {

        painter.setBrush(QBrush(toQColor(std::get<1>(*it)),Qt::SolidPattern));
        switch (std::get<0>(*it)) {
            case TypeCardinaux::nord:
                if(std::get<2>(*it) == TypeMeeple::normal) painter.drawRoundedRect(17.5,0, 10, 10, 5,5);
                else painter.drawRect(17.5,0, 10, 10);
                break;
            case TypeCardinaux::est:
                if(std::get<2>(*it) == TypeMeeple::normal) painter.drawRoundedRect(35,17.5, 10, 10, 5,5);
                else painter.drawRect(35,17.5, 10, 10);
                break;
            case TypeCardinaux::sud:
                if(std::get<2>(*it) == TypeMeeple::normal) painter.drawRoundedRect(17.5,35, 10, 10, 5,5);
                else painter.drawRect(17.5,35, 10, 10);
                break;
            case TypeCardinaux::ouest:
                if(std::get<2>(*it) == TypeMeeple::normal) painter.drawRoundedRect(0,17.5, 10, 10, 5,5);
                else painter.drawRect(0,17.5, 10, 10);
                break;
            case TypeCardinaux::nord_ouest:
            case TypeCardinaux::ouest_nord:
                if(std::get<2>(*it) == TypeMeeple::normal) painter.drawRoundedRect(0,0, 10, 10, 5,5);
                else painter.drawRect(0,0, 10, 10);
                break;
            case TypeCardinaux::nord_est:
            case TypeCardinaux::est_nord:
                if(std::get<2>(*it) == TypeMeeple::normal) painter.drawRoundedRect(35,0, 10, 10, 5,5);
                else painter.drawRect(35,0, 10, 10);
                break;
            case TypeCardinaux::sud_ouest:
            case TypeCardinaux::ouest_sud:
                if(std::get<2>(*it) == TypeMeeple::normal) painter.drawRoundedRect(0,35, 10, 10, 5,5);
                else painter.drawRect(0,35, 10, 10);
                break;
            case TypeCardinaux::est_sud:
            case TypeCardinaux::sud_est:
                if(std::get<2>(*it) == TypeMeeple::normal) painter.drawRoundedRect(35,35, 10, 10, 5,5);
                else painter.drawRect(35,35, 10, 10);
                break;
            default:
                if(std::get<2>(*it) == TypeMeeple::normal) painter.drawRoundedRect(17.5, 17.5, 10,10, 5,5);
                else painter.drawRect(17.5, 17.5, 10,10);
                break;
        }
    }
}

void VueTuile::retirerAbbe(TypeCouleur::points c) {
    bool finded = false;
    auto it = meeples.begin();
    while(it != meeples.end() && !finded) {
        if(std::get<1>(*it) == c) {
            std::cout << "ici" << std::endl;
            meeples.erase(it);
            removingAbbe = true;
            finded = true;
            updateTuilePicture();
        } else
            it++;
    }
}

QColor VueTuile::toQColor(TypeCouleur::points c) {
    switch (c) {
        case TypeCouleur::rose: return QColor(255,55,255);
        case TypeCouleur::rouge: return QColor(255,0,0);
        case TypeCouleur::bleu: return QColor(0,0,255);
        case TypeCouleur::vert: return QColor(0,255,0);
        case TypeCouleur::jaune: return QColor(255,255,0);
        case TypeCouleur::orange: return QColor(255,128,0);
    }
    return QColor(0,0,0);
}