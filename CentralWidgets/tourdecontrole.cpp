#include "tourdecontrole.h"
#include "Lists/commonlist.h"
#include <QDebug>
#include "Shows/horizontalshowcollection.h"
#include <QStandardItemModel>
#include "Lists/tousvol.h"
#include "Shows/volshow.h"

TourDeControle::TourDeControle(QWidget *parent) :
    AbstractCentWid(parent)
{
    setObjectName("Tour de Controle");

    lc=new ListCollection;
    lc->append(new CommonList("Les Vols",new TousVol));
    set_lc(lc);

    _chi=new CHI();
    connect(_chi,SIGNAL(doneVol()),this,SLOT(setModel()));
//    connect(_chi,SIGNAL(doneLoad()),this,SLOT(setLastVolAtt()));
//    connect(_chi,SIGNAL(doneLoadProg()),this,SLOT(setLastVolAttProg()));

    sc=new FlexibleShowCollection(_chi);
    DropReceiver *dr=new DropReceiver(sc);
    set_sc(sc);
    add_dr(dr);

    lay();
}



void TourDeControle::setIndModel(int i)
{
    //_chi->getVolSel(QString::number(_chi->Vols[i]->getIdVol()));
}
void TourDeControle::setModel()
{
        QStandardItemModel *si=new QStandardItemModel(this);
        QStringList sl; sl<<"id"<<"Code"<<"Date Depart"<<"Aeroport";
        QList<QStandardItem *> l;
        si->setHorizontalHeaderLabels(sl);
        for(int i=0;i<_chi->Vols.length();++i)
        {l.clear();
        l<<new QStandardItem(QString::number(_chi->Vols[i]->getIdVol()))<<new QStandardItem(_chi->InfoProg[i])<<new QStandardItem(_chi->Vols[i]->getDatPreVol().toString())<<new QStandardItem(_chi->InfoAero[i]);
        si->appendRow(l);
        }
        //si->appendRow(QStandardItem(4));

        (*lc)[0]->leReste()->setModel(si);
}

void TourDeControle::setLastVolAtt()
{
//    int i=_chi->getCounter()-1;
//    //qDebug()<<i;
//    static_cast<VolShow *>(sc->_zLast)->setModels(_chi->V[i],_chi->Rapportss[i]);//a cont
}
void TourDeControle::setLastVolAttProg()
{
//    int i=_chi->getCounter()-1;
//    static_cast<VolShow *>(sc->_zLast)->setModels(_chi->Programmes[i]);
}
