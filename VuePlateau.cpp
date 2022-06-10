//
// Created by Leo Peron on 28/05/2022.
//

#include <iostream>
#include "VuePlateau.h"

VuePlateau::VuePlateau(QObject* parent, QLabel* tuile) : parent(parent), currentTuile(tuile) {}

void VuePlateau::createGrille(){
    for (int x=0; x<=2000; x+=50)
        for (int y=0; y<=2000; y+=50) {
            QRectF rect(x,y,50,50);
            QGraphicsRectItem* item;
            item=this->addRect(rect,QPen(Qt::black));
            item->setFlag(QGraphicsItem::ItemIsSelectable);
        }
    //view->fitInView(scene->itemsBoundingRect());
}

void VuePlateau::addTuile(QGraphicsPixmapItem* item, QPointF* pos) {
    int x=pos->rx();
    int y=pos->ry();

    //VueTuile* tuile=new VueTuile(x,y,this,1);
    //tuile->setTuile(1);

    item->setScale(0.47);
    item->setPos(x,y);
    this->addItem(item);


}

void VuePlateau::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (event->button() != Qt::LeftButton)
        return;
    //QGraphicsItem* parent = this->selectedItems()[0];
    QPixmap tuile=this->currentTuile->pixmap();
    QGraphicsPixmapItem* item;
    item=this->addPixmap(tuile);
    QPointF pos(0,0);//this->selectedItems().first()->pos();
    addTuile(item, &pos);

}