//
// Created by Leo Peron on 28/05/2022.
//

#include <QPainter>
#include "VueTuile.h"

VueTuile::VueTuile(int x, int y, QWidget *parent, size_t id) : x(x), y(y), id(id),QPushButton(parent) {
    setFixedSize(45,45);
    setStyleSheet("background-color: white;");
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(true);
}

void VueTuile::setTuile(const size_t newId, const int rotation) {
    std::string str  = "/Users/leo/Documents/UTC/LO21/lo21-carcassone/utils/tiles_illustrations/" + std::to_string(newId) + ".jpeg";
    QImage* img = new QImage();
    img->load(QString::fromStdString(str));
    QPixmap pix = QPixmap::fromImage(*img);
    QTransform t;
    pix = pix.transformed(t.rotate(90*rotation));
    setIcon(pix);
    setIconSize(QSize(44,44));
    update();
}

void VueTuile::paintEvent(QPaintEvent* e)
{
    QPushButton::paintEvent(e);
    QPainter painter(this);

    QPoint test = QPoint(0, 0);

    QRect buttonRect=rect();

    for(auto it = meeples.begin(); it != meeples.end(); it++) {

        painter.setBrush(QBrush(toQColor(it->second),Qt::SolidPattern));
        switch (it->first) {
            case TypeCardinaux::nord:
                painter.drawRect(15,0, 10, 10);
                break;
            case TypeCardinaux::est:
                painter.drawRect(30,15, 10, 10);
                break;
            case TypeCardinaux::sud:
                painter.drawRect(15,30, 10, 10);
                break;
            case TypeCardinaux::ouest:
                painter.drawRect(0,15, 10, 10);
                break;
        }
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