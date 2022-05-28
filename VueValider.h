//
// Created by Leo Peron on 28/05/2022.
//

#ifndef TESTING_THINGS_VUEVALIDER_H
#define TESTING_THINGS_VUEVALIDER_H

#include <QDialog>
#include <QtWidgets>

class VueValider : public QDialog {
    Q_OBJECT
public:
    explicit VueValider(QWidget *parent = nullptr);
    ~VueValider();
    bool const getResult() { return result; }

private:

    // Settings to export
    bool result;

    // UX
    QPushButton* ouiBoutton;
    QPushButton* nonBoutton;
    QHBoxLayout* grid;

private slots:
    void cliquerOui();
    void cliquerNon();
};

#endif //TESTING_THINGS_VUEVALIDER_H
