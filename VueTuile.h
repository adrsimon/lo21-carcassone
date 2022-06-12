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
    explicit VueTuile(int x, int y, QWidget *parent = nullptr, size_t id=-1, int rot = 0);
    void setTuile(const size_t newId, const int rotation=0);
    size_t getTuileId() const { return id; }
    int getVueTuileX() const { return x; }
    int getVueTuileY() const { return y; }
    void addMeeple(TypeCardinaux::points card, TypeCouleur::points cou, TypeMeeple::points type) { meeples.push_back(std::tuple<TypeCardinaux::points, TypeCouleur::points, TypeMeeple::points>(card,cou, type)); }
    void clearMeeples();
    void retirerAbbe(TypeCouleur::points c);
    QColor toQColor(TypeCouleur::points c);

protected:
    void paintEvent(QPaintEvent *event) override;
private:
    bool cleared=false;
    bool removingAbbe=false;
    size_t id;
    int rotation;
    std::vector<std::tuple<TypeCardinaux::points, TypeCouleur::points, TypeMeeple::points>> meeples;
    void updateTuilePicture();
    int x;
    int y;

signals:
    void tuileClicked(VueTuile*);

private slots:
    void clickedEvent() { emit tuileClicked(this); }

};


#endif //TESTING_THINGS_VUETUILE_H
