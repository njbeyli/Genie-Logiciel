#ifndef DIRECTIONWID_H

#define DIRECTIONWID_H

#include "abstractcentwid.h"

#include "Shows/horizontalshowcollection.h"
#include "direction.h"

class DirectionWid : public AbstractCentWid
{
    Q_OBJECT

    ListCollection *lc;
    HorizontalShowCollection *sc;
    Direction *dir;

public:

    explicit DirectionWid(QWidget *parent = 0);

protected slots:
    void setIndModel(int i);

signals:

public slots:
    void setModel();
};

#endif // DIRECTIONWID_H
