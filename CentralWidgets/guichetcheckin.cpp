#include "guichetcheckin.h"
#include "Lists/voldaujourd.h"
#include "Lists/flight.h"
#include "Shows/guichetshow.h"
#include <QDebug>

GuichetCheckin::GuichetCheckin(QWidget *parent) :
    AbstractCentWid(parent)
{
    setObjectName("Guichet Check-In");
    lc=new ListCollection;
    lc->append(new CommonList("Les Vol Actifs",new VolDaujourd));
    set_lc(lc);


    _counter=new Counter();
   // _counter->getVolsActifs();

   // QList<QString> l; l<<"Sawma"<<"Farid"<<"Men"<<"Naw3o"<<"yaShabab";
   // l<<l<<l;
   // qDebug()<<_counter->Prog.at(0);
    //qDebug()<<"ll";

    connect(_counter,SIGNAL(done()),this,SLOT(setModel()));
    connect(_counter,SIGNAL(donePassager()),this,SLOT(setPass()));

    sc=new OneATimeShowCollection(_counter);
    //DropReceiver *dr=new DropReceiver(sc,true);
    DropReceiver *dr=new DropReceiver(sc);
    set_sc(sc);
    add_dr(dr);
    //add_dr(dr1);
    lay();
}

void GuichetCheckin::setIndModel(int i)
{
    _counter->setVolSel(QString::number(_counter->Vols[i]->getIdVol()));
    connect(static_cast<GuichetShow*>(sc->_zOne),SIGNAL(check(int)),this,SLOT(checkPass(int)));
}

void GuichetCheckin::setModel()
{
    (*lc)[0]->leReste()->setModel(_counter->Prog);

//    QList<int> intl;
//    foreach (Vol *v, _counter->Vols) {
//        intl.append(v->getIdVol());
//    }
//    (*lc)[0]->leReste()->setModel(intl);
}

void GuichetCheckin::checkPass(int i)
{
   // qDebug()<<i;
    _counter->check(QString::number(i));
}

void GuichetCheckin::setPass(){
    static_cast<GuichetShow *>(sc->_zOne)->setModels(_counter->Passagers);
}
