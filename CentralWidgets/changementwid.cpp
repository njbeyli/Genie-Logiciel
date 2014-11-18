#include "changementwid.h"

#include "Lists/tousvol.h"
#include "Lists/generiquelist.h"
#include "Drops/eqmcreator.h"
#include <QStandardItemModel>

ChangementWid::ChangementWid(QWidget *parent) :
    AbstractCentWid(parent)
{
    setObjectName("UpDate");

    lc=new ListCollection;
    lc->append(new CommonList("Les Vols",new TousVol));
    lc->append(new CommonList("Les Programme",new GeneriqueList));
    lc->append(new CommonList("Equipe Maintenance",new GeneriqueList));
    static_cast<GeneriqueList *>((*lc)[2]->leReste())->set_sh(new EqmCreator);
    lc->append(new CommonList("Avion",new GeneriqueList));

    set_lc(lc);
    _upd=new Update();

    connect(_upd,SIGNAL(doneVol()),this,SLOT(setVol()));
    connect(_upd,SIGNAL(doneProg()),this,SLOT(setProg()));
    connect(_upd,SIGNAL(doneEDM()),this,SLOT(setEDM()));
    connect(_upd,SIGNAL(doneAvion()),this,SLOT(setAvion()));

    sc=new HorizontalShowCollection(_upd);
    set_sc(sc);

    add_dr(new DropReceiver(sc,true));
    add_dr(new DropReceiver(sc));
    lay();
}
void ChangementWid::setModel()
{}
void ChangementWid::setIndModel(int i)
{}
void ChangementWid::setVol()
{
    QStandardItemModel *si=new QStandardItemModel(this);
    QStringList sl; sl<<"id"<<"Code"<<"Date Depart"<<"Aeroport";
    QList<QStandardItem *> l;
    si->setHorizontalHeaderLabels(sl);
    for(int i=0;i<_upd->Vo.length();++i)
    {l.clear();
    l<<new QStandardItem(QString::number(_upd->Vo[i]->getIdVol()))<<new QStandardItem(_upd->InfoProg[i])<<new QStandardItem(_upd->Vo[i]->getDatPreVol().toString())<<new QStandardItem(_upd->InfoAero[i]);
    si->appendRow(l);
    }
    //si->appendRow(QStandardItem(4));

    (*lc)[0]->leReste()->setModel(si);
}
void ChangementWid::setProg()
{
    QStringList m;
    foreach (Item *pdm, _upd->Prog) {
        m<<static_cast<Programme *>(pdm)->getCode();
    }
    (*lc)[1]->leReste()->setModel(m);
}
void ChangementWid::setEDM()
{
    QStringList m;
    foreach (Item *pdm, _upd->E) {
        m<<QString::number(static_cast<EDM *>(pdm)->getIdEquipe());
    }
    (*lc)[2]->leReste()->setModel(m);
}
void ChangementWid::setAvion()
{
    QStringList m;
    foreach (Item *pdm, _upd->Av) {
        m<<QString::number(static_cast<Avion *>(pdm)->getIdAvion());
    }
    (*lc)[3]->leReste()->setModel(m);
}
