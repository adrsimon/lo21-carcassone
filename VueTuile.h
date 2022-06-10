//
// Created by Leo Peron on 28/05/2022.
//

#ifndef TESTING_THINGS_VUETUILE_H
#define TESTING_THINGS_VUETUILE_H

#include <QWidget>
#include <QPushButton>
#include "src/plateau.h"

class VueTuile : public QPushButton
{
Q_OBJECT
public:
    explicit VueTuile(int x, int y, QWidget *parent = nullptr, size_t id=-1);
    void setTuile(const size_t newId);
    size_t getTuile() const { return id; }
    bool tuilePresente() const { return id!=-1; }

private:
    size_t id;
    int x;
    int y;
    QImage img;
private slots:
    void test();
};



#endif //TESTING_THINGS_VUETUILE_H
