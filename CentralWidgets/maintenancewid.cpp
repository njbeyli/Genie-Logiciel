#include "maintenancewid.h"
#include "Lists/tousvolrapport.h"
#include "Lists/generiquelist.h"
#include <QStandardItemModel>

MaintenanceWid::MaintenanceWid(QWidget *parent) :
    AbstractCentWid(parent)
{
    setObjectName("Maintenance");

    lc=new ListCollection;
    lc->append(new CommonList("Les Vols",new TousVolRapport));
    lc->append(new CommonList("Les Equipes",new GeneriqueList));
    lc->append(new CommonList("Les Operations d'arrivee",new GeneriqueList));
    lc->append(new CommonList("Les Operations de Depart",new GeneriqueList));
    set_lc(lc);

    _maint=new Maintenance;
    connect(_maint,SIGNAL(doneVol()),this,SLOT(setVol()));
    connect(_maint,SIGNAL(doneEDM()),this,SLOT(setEq()));
    connect(_maint,SIGNAL(doneOpArr()),this,SLOT(setOpA()));
    connect(_maint,SIGNAL(doneOpDep()),this,SLOT(setOpD()));

    sc=new OneATimeShowCollection(_maint);

    DropReceiver *dr=new DropReceiver(sc,true);
    set_sc(sc);
    add_dr(dr);
    lay();
}
void MaintenanceWid::setVol()
{
    QStandardItemModel *si=new QStandardItemModel(this);
    QStringList sl; sl<<"id"<<"Code"<<"Date Depart"<<"Aeroport";
    QList<QStandardItem *> l;
    si->setHorizontalHeaderLabels(sl);
    for(int i=0;i<_maint->Vo.length();++i)
    {l.clear();
       // qDebug()<<_fly->InfoProg[i];
    l<<new QStandardItem(QString::number((_maint->Vo[i])->getIdVol()))<<new QStandardItem(_maint->InfoProg[i])<<new QStandardItem(_maint->Vo[i]->getDatPreVol().toString())<<new QStandardItem(_maint->InfoAero[i]);
    si->appendRow(l);
    }
    //si->appendRow(QStandardItem(4));

    (*lc)[0]->leReste()->setModel(si);
}
void MaintenanceWid::setEq()
{
    QStringList m;
    foreach (Item *pdm, _maint->EqM) {
        m<<QString::number(static_cast<EDM *>(pdm)->getIdEquipe());
    }
    (*lc)[1]->leReste()->setModel(m);
}
void MaintenanceWid::setOpA()
{
    QStringList m;
    foreach (Item *pdm, _maint->OpAr) {
        qDebug()<<static_cast<Operations *>(pdm)->getIdOp();
        m<<QString::number(static_cast<Operations *>(pdm)->getIdOp())+" "+static_cast<Operations *>(pdm)->getDescOp();
    }
    (*lc)[2]->leReste()->setModel(m);
}
void MaintenanceWid::setOpD()
{
    QStringList m;
    foreach (Item *pdm, _maint->OpDep) {
        m<<QString::number(static_cast<Operations *>(pdm)->getIdOp())+" "+static_cast<Operations *>(pdm)->getDescOp();
    }
    (*lc)[3]->leReste()->setModel(m);
}


void MaintenanceWid::setIndModel(int i)
{i=0;}
void MaintenanceWid::setModel()
{}
