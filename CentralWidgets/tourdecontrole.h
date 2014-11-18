#ifndef TOURDECONTROLE_H
#define TOURDECONTROLE_H

#include "abstractcentwid.h"
#include "chi.h"
#include "Shows/flexibleshowcollection.h"

class TourDeControle : public AbstractCentWid
{
    Q_OBJECT
    CHI *_chi;
    ListCollection *lc;
    FlexibleShowCollection *sc;

public:
    explicit TourDeControle(QWidget *parent = 0);

signals:

protected slots:
    void setIndModel(int i);
    void setLastVolAtt();
    void setLastVolAttProg();

public slots:
    void setModel();
};

#endif // TOURDECONTROLE_H
