#include "horizontalshowcollection.h"

#include <QDebug>

HorizontalShowCollection::HorizontalShowCollection(Gerance *g,QWidget *parent) :
    ShowCollection(g,parent)
{
    _vl=new QVBoxLayout;
    _vl->setMargin(5);_vl->setSpacing(10);



    _vl->addStretch();
    addingLayout();
    setLayout(_vl);
}


QHBoxLayout * HorizontalShowCollection::addingLayout()
{
    _hll.append(new QHBoxLayout);
    _hll.last()->setMargin(0);_hll.last()->setSpacing(10);
    _hll.last()->addStretch();
    _sll.append(0);

    _vl->insertLayout(_vl->count()-1,_hll.last());
    return _hll.last();
}

void HorizontalShowCollection::addShow(Show *s)
{
    if(s)
    {
    connect(s->exit(),SIGNAL(clicked()),s,SLOT(deleteLater()));
    connect(s,SIGNAL(destroyed(QObject*)),this,SLOT(elimin(QObject*)));

    QHBoxLayout *hb=_hll.last();


    if(_sll.last()+s->width()>this->width())
    {
        hb=addingLayout();
    }
    _sll.last()+=s->width();
    hb->insertWidget(hb->count()-1,s);
    _zLast=s;
    s->setg(g());
    }
}

void HorizontalShowCollection::eli(int i)
{
    if(i==_hll.length()-1)
    {
        if(_sll[i]==0&&i!=0)
        {
            _vl->takeAt(i);
            _sll.pop_back();
            _hll.pop_back();
        }
        return;
    }
    int w=_hll[i+1]->itemAt(0)->geometry().width();
    if(w+_sll[i]<this->width())
    {
        _hll[i]->insertItem(_hll[i]->count()-1,_hll[i+1]->takeAt(0));
        _sll[i]+=w;
        _sll[i+1]-=w;
        eli(i+1);
    }
    return;
}

void HorizontalShowCollection::elimin(QObject *o)
{
    for(int i=0;i<_hll.length();++i)
    {
        int ind;
        if((ind=_hll[i]->indexOf(static_cast<Show*>(o)))!=-1)
        {
            _sll[i]-=_hll[i]->takeAt(ind)->geometry().width();
            eli(i);
            break;
        }
    }
}
