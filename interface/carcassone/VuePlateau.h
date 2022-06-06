//
// Created by Leo Peron on 28/05/2022.
//

#ifndef VUEPLATEAU_H
#define VUEPLATEAU_H

#include <QGraphicsScene>
#include <QMenu>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QLabel>

#include "VueTuile.h"


class VuePlateau : public QGraphicsScene {
    Q_OBJECT
public:
    explicit VuePlateau(QObject *parent = nullptr, QLabel* tuile=nullptr);

    void createGrille();
    void addTuile(QGraphicsPixmapItem* item, QPointF* pos);
    void setCurrentTuile(QLabel* tuile) {currentTuile=tuile;}

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;


private:
    //QMenu *myItemMenu;
    QObject *parent;
    QLabel *currentTuile;
    /*
    VueTuile* tuiles[20][20];
    void test();
signals:
    void attemptToPutTuile();
    */
signals:
    void itemSelected(QGraphicsItem *item);

};

#endif //TESTING_THINGS_VUEPLATEAU_H
