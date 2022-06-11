//
// Created by Leo Peron on 28/05/2022.
//

#ifndef TESTING_THINGS_VUETUILE_H
#define TESTING_THINGS_VUETUILE_H

#include <QWidget>
#include <QPushButton>
#include "src/enum.h"


class VueTuile : public QPushButton
{
    Q_OBJECT
public:
    explicit VueTuile(int x, int y, QWidget *parent = nullptr, size_t id=-1);
    void setTuile(const size_t newId, const int rotation);
    size_t getTuile() const { return id; }
    int getVueTuileX() const { return x; }
    int getVueTuileY() const { return y; }
    void addMeeple(TypeCardinaux::points card, TypeCouleur::points cou) { meeples.push_back(std::pair<TypeCardinaux::points, TypeCouleur::points>(card,cou)); }
    QColor toQColor(TypeCouleur::points c);

protected:
    void paintEvent(QPaintEvent *event) override;
private:
    size_t id;
    std::vector<std::pair<TypeCardinaux::points, TypeCouleur::points>> meeples;
    int x;
    int y;

signals:
    void tuileClicked(VueTuile*);

private slots:
    void clickedEvent() { emit tuileClicked(this); }

};


#endif //TESTING_THINGS_VUETUILE_H
