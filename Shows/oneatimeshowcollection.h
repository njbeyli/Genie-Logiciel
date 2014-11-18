#ifndef ONEATIMESHOWCOLLECTION_H
#define ONEATIMESHOWCOLLECTION_H

#include "showcollection.h"

class OneATimeShowCollection : public ShowCollection
{
    Q_OBJECT
    QVBoxLayout *_hb;

public:
    explicit OneATimeShowCollection(Gerance *g,QWidget *parent = 0);
    void addShow(Show *s);
    Show *_zOne;

signals:

private slots:
    void elimin(QObject *o);

public slots:


};

#endif // ONEATIMESHOWCOLLECTION_H
