//
// Created by Leo Peron on 28/05/2022.
//

#ifndef VUEPLATEAU_H
#define VUEPLATEAU_H

#include <QGridLayout>
#include "VueTuile.h"

class VuePlateau : public QGridLayout {
    Q_OBJECT
public:
    explicit VuePlateau(QWidget *parent = nullptr);

private:
    VueTuile* tuiles[20][20];
    void test();
signals:
    void attemptToPutTuile();
};

#endif //TESTING_THINGS_VUEPLATEAU_H
