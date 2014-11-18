#ifndef AEROFILTRE_H
#define AEROFILTRE_H

#include "listefiltre.h"

class AeroFiltre : public ListeFiltre
{
    Q_OBJECT
public:
    explicit AeroFiltre(QWidget *parent = 0);

    void remplirMod();

signals:

public slots:

};

#endif // AEROFILTRE_H
