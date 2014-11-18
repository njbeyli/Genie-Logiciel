#ifndef COMPFILTRE_H
#define COMPFILTRE_H

#include "listefiltre.h"

class CompFiltre : public ListeFiltre
{
    Q_OBJECT
public:
    explicit CompFiltre(QWidget *parent = 0);

protected:

    void remplirMod();

signals:


public slots:

};

#endif // COMPFILTRE_H
