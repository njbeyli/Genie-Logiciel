#include "oneatimeshowcollection.h"

OneATimeShowCollection::OneATimeShowCollection(Gerance *g,QWidget *parent) :
    ShowCollection(g,parent)
{
    _hb=new QVBoxLayout;
    _hb->setMargin(5);
    _hb->addStretch();
    setLayout(_hb);
    _zOne=0;
}

void OneATimeShowCollection::addShow(Show *s)
{
    if(s)
    {
    connect(s->exit(),SIGNAL(clicked()),s,SLOT(deleteLater()));
    connect(s,SIGNAL(destroyed(QObject*)),this,SLOT(elimin(QObject*)));
    if(_zOne)
    {
        delete _zOne;
    }
    _zOne=s;
    _hb->insertWidget(0,_zOne,0,Qt::AlignHCenter);
    s->setg(g());
    }
}

void OneATimeShowCollection::elimin(QObject *o)
{
    _zOne=0;
    _hb->removeWidget(static_cast<QWidget *>(o));
}
