#ifndef DIRECTIONWIDGET_H
#define DIRECTIONWIDGET_H

#include "abstractcentwid.h"

#include "Shows/horizontalshowcollection.h"
#include "direction.h"

class DirectionWidget : public AbstractCentWid
{
    Q_OBJECT

    ListCollection *lc;
    HorizontalShowCollection *sc;
    Direction *_dir;

public:

    explicit DirectionWidget(QWidget *parent = 0);

protected slots:
    void setIndModel(int i);

    void setPDM();
    void setEqA();
    void setEqM();
    void setComp();
    void setModele();
    void setAvion();
    void setAero();

signals:

public slots:
    void setModel();
};

#endif // DIRECTIONWIDGET_H
