#ifndef GUICHETONBOARD_H
#define GUICHETONBOARD_H

#include "abstractcentwid.h"
#include "Lists/listcollection.h"
#include "obcounter.h"
#include "Shows/oneatimeshowcollection.h"

class GuichetOnBoard : public AbstractCentWid
{
    Q_OBJECT
    OBCounter * _counter;
    ListCollection *lc;
    OneATimeShowCollection *sc;
public:
    explicit GuichetOnBoard(QWidget *parent = 0);

signals:

protected slots:
    void setIndModel(int i);

public slots:
    void setModel();
    void setPass();
    void checkPass(int);

};

#endif // GUICHETONBOARD_H
