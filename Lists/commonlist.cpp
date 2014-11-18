#include "commonlist.h"
#include <QVBoxLayout>

CommonList::CommonList(QString s, AbstractList *leReste, QWidget *parent) :
    QWidget(parent),_leReste(leReste)
{
    setObjectName(s);

    QLayout *l=new QVBoxLayout;
    st[0]="Click to Maximize";
    st[1]="Click to Minimize";
    _header=new QPushButton(s);
    _header->setFixedHeight(40);
    _header->setToolTip(st[1]);
    l->setMargin(0);
    l->setSpacing(0);
    l->addWidget(_header);
    l->addWidget(_leReste);
    //static_cast<QVBoxLayout *> (l)->addStretch();

    connect(_header,SIGNAL(clicked()),this,SLOT(miniMax()));

    //connect(_leReste,SIGNAL(toli3menneh(AbstractList*)),this,SLOT(reSend(AbstractList*)));

    setLayout(l);
}

AbstractList *CommonList::leReste()const
{
    return _leReste;
}



void CommonList::miniMax()
{
    _header->setToolTip(st[_leReste->isHidden()]);
    _leReste->setVisible(_leReste->isHidden());

}
