#include "listcollection.h"

ListCollection::ListCollection(QWidget *parent) :
    QWidget(parent)
{
    _bl=new QBoxLayout(QBoxLayout::TopToBottom);
    _bl->setMargin(0); _bl->setSpacing(0);
    _bl->addStretch();
    setLayout(_bl);
}

void ListCollection::append(CommonList *l)
{
    _all.append(l);
    //connect(l->leReste(),SIGNAL(toli3menneh(AbstractList*)),this,SLOT(reSend(AbstractList*)));
    _bl->insertWidget(_bl->count()-1,l);
}

CommonList * ListCollection::operator [](int i)
{
    return _all[i];
}

int ListCollection::length()const
{
    return _all.length();
}
