#ifndef VUESETTINGS_H
#define VUESETTINGS_H

#include <QDialog>
#include <QFormLayout>
#include <QtWidgets>

class VueSettings : public QDialog
{
    Q_OBJECT

public:
    explicit VueSettings(QWidget *parent = nullptr);
    ~VueSettings();
    std::list<std::string> const getNomJoueurs() { return nomJoueurs; }

private:

    // Settings to export
    std::list<std::string> nomJoueurs;
    std::list<bool> extensions;

    // UX
    QPushButton* validerBoutton;
    QLineEdit* joueurs[6];
    QPushButton* annulerBoutton;
    QGridLayout* couche;
    QVBoxLayout* layoutExtensions;
    QHBoxLayout* layoutBouttons;
    QFormLayout* form_joueurs;
private slots:
    void cliquerValider();
    void cliquerAnnuler();
};

#endif // VUESETTINGS_H
