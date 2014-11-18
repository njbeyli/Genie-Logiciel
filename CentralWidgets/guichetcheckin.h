#ifndef GUICHETCHECKIN_H
#define GUICHETCHECKIN_H

#include "abstractcentwid.h"
#include "Lists/listcollection.h"
#include "counter.h"
#include "Shows/oneatimeshowcollection.h"

class GuichetCheckin : public AbstractCentWid
{
    Q_OBJECT

    Counter * _counter;
    ListCollection *lc;
    OneATimeShowCollection *sc;
public:
    explicit GuichetCheckin(QWidget *parent = 0);

signals:

protected slots:
    void setIndModel(int i);

public slots:
    void setModel();
    void setPass();
    void checkPass(int);
};

#endif // GUICHETCHECKIN_H
