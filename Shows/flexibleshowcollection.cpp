#include "flexibleshowcollection.h"
#include <QDebug>

FlexibleShowCollection::FlexibleShowCollection(Gerance *g,QWidget *parent) :
    ShowCollection(g,parent)
{
    _mqvb=new QHBoxLayout;
    _mqvb->setMargin(5); _mqvb->setSpacing(10);
    //_mqvb->addStretch();
    addingLayout();
    _mqvb->addStretch();
    _ind[0]=0;_ind[1]=-1;
    setLayout(_mqvb);
}
void FlexibleShowCollection::addingLayout()
{

    for(int i=0;i<2;++i)
    {
        _mqhb[i]=new QVBoxLayout;
        _mqhb[i]->setMargin(0);
        _mqhb[i]->setSpacing(10);
        _mqhb[i]->addStretch();
        _mqvb->addLayout(_mqhb[i]);
    }


}

void FlexibleShowCollection::addShow(Show *s)
{

    if(s)
    {
    connect(s->exit(),SIGNAL(clicked()),s,SLOT(deleteLater()));
    connect(s,SIGNAL(destroyed(QObject*)),this,SLOT(elimin(QObject*)));



    if(_ind[0]==0)
        ++_ind[1];
    _mqhb[_ind[0]]->insertWidget(_ind[1],s);
    _ind[0]=1-_ind[0];

    _zLast=s;
    s->setg(g());
    }
}

void FlexibleShowCollection::elimin(QObject *o)
{
    for(int i=0;i<2;++i)
    {
        int ind;
        if((ind=_mqhb[i]->indexOf(static_cast<Show*>(o)))!=-1)
        {
            _mqhb[i]->takeAt(ind);
            if(_ind[0]==i)
            {
                _mqhb[i]->insertItem(_ind[1]-i,_mqhb[1-i]->takeAt(_ind[1]));
                _ind[1]-=i;
            }
            else
            {
                _ind[1]-=1-i;
            }
            _ind[0]=1-_ind[0];
            break;
        }
    }
}
