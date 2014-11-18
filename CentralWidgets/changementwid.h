#ifndef CHANGEMENTWID_H
#define CHANGEMENTWID_H

#include "abstractcentwid.h"
#include "update.h"
#include "Shows/horizontalshowcollection.h"

class ChangementWid : public AbstractCentWid
{
    Q_OBJECT
    ListCollection *lc;
    HorizontalShowCollection *sc;
    Update *_upd;
public:
    explicit ChangementWid(QWidget *parent = 0);

protected slots:
    void setIndModel(int i);
    void setVol();
    void setAvion();
    void setProg();
    void setEDM();
    //void setPersM();
signals:

public slots:
    void setModel();
};

#endif // CHANGEMENTWID_H
