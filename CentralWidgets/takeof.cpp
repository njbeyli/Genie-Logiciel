#include "takeof.h"

#include "Lists/tousvol.h"
#include <QStandardItemModel>
#include <QSortFilterProxyModel>


TakeOf::TakeOf(QWidget *parent) :
    AbstractCentWid(parent)
{
    setObjectName("Take-Off");

    lc=new ListCollection;
    lc->append(new CommonList("Les Vols Prets",new TousVol));
    set_lc(lc);

    _fly=new Fly();

    connect(_fly,SIGNAL(doneVol()),this,SLOT(setModel()));

    sc=new OneATimeShowCollection(_fly);
    DropReceiver *dr=new DropReceiver(sc,true);
    set_sc(sc);
    add_dr(dr);
    lay();
}

void TakeOf::setIndModel(int i)
{i=0;}

void TakeOf::setModel()
{
    QStandardItemModel *si=new QStandardItemModel(this);
    QStringList sl; sl<<"id"<<"Code"<<"Date Depart"<<"Aeroport";
    QList<QStandardItem *> l;
    si->setHorizontalHeaderLabels(sl);
    for(int i=0;i<_fly->V.length();++i)
    {l.clear();
       // qDebug()<<_fly->InfoProg[i];
    l<<new QStandardItem(QString::number((_fly->V[i])->getIdVol()))<<new QStandardItem(_fly->InfoProg[i])<<new QStandardItem(_fly->V[i]->getDatPreVol().toString())<<new QStandardItem(_fly->InfoAero[i]);
    si->appendRow(l);
    }
    //si->appendRow(QStandardItem(4));

    (*lc)[0]->leReste()->setModel(si);
}
