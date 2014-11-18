#ifndef TAKEOF_H
#define TAKEOF_H

#include "abstractcentwid.h"
#include "Lists/listcollection.h"
#include "Shows/oneatimeshowcollection.h"
#include "fly.h"

class TakeOf : public AbstractCentWid
{
    Q_OBJECT
    Fly * _fly;
    ListCollection *lc;
    OneATimeShowCollection *sc;
public:
    explicit TakeOf(QWidget *parent = 0);

signals:

protected slots:
    void setIndModel(int i);

public slots:
    void setModel();
};

#endif // TAKEOF_H
