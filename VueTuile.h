//
// Created by Leo Peron on 28/05/2022.
//

#ifndef TESTING_THINGS_VUETUILE_H
#define TESTING_THINGS_VUETUILE_H

#include <QWidget>
#include <QPushButton>


class VueTuile : public QPushButton
{
    Q_OBJECT
public:
    explicit VueTuile(int x, int y, QWidget *parent = nullptr, size_t id=-1);
    void setTuile(const size_t newId, const int rotation);
    size_t getTuile() const { return id; }
    int getVueTuileX() const { return x; }
    int getVueTuileY() const { return y; }

private:
    size_t id;
    int x;
    int y;

signals:
    void tuileClicked(VueTuile*);

private slots:
    void clickedEvent() { emit tuileClicked(this); }

};


#endif //TESTING_THINGS_VUETUILE_H
