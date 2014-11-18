#include "rapportshow.h"
#include "ui_rapportshow.h"
#include "chi.h"
#include "Drops/rapportdropreceiver.h"
#include "CentralWidgets/maintenancewid.h"
#include "Drops/mystringmodel.h"

RapportShow::RapportShow(QString s,bool type, QWidget *parent) :
    Show(parent),
    ui(new Ui::RapportShow)
{
    ui->setupUi(this);
    t=type;
    ui->IdR->setText(s);
    setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Minimum);
    ui->datetime->setDateTime(QDateTime().currentDateTime());
    ml=new MyListWidget;
    ui->idEq->layout()->addWidget(ml);


    setExitPos();
    if(!t)
    {
        submit()->deleteLater();

    }
    else
    {
        RapportDropReceiver *rp=new RapportDropReceiver;
        ui->widget->layout()->addWidget(rp);
        connect(rp,SIGNAL(alMawloud(QString)),this,SLOT(addOp(QString)));
        ml->setAcceptDrops(true);
        MyStringModel *msm=new MyStringModel(this,true);
        ml->setModel(msm);
    }
}

void RapportShow::addOp(QString s)
{
    if(dynamic_cast<Maintenance *>(g()))
    {
        Maintenance *m=static_cast<Maintenance *>(g());
        m->selectOp(s.split(QRegularExpression("\\s+"))[0]);
        QVBoxLayout *v=static_cast<QVBoxLayout*>(ui->widget->layout());
        Operations *o=m->OpEf.last();
        OperationShow *op=new OperationShow;
        op->setDateh(QString::number(o->getIdOp()),o->getDescOp(),0,"");
        v->insertWidget(v->count()-1,op);
        _l.append(op);
    }
}

void RapportShow::addLeRapport()
{
    Maintenance *m=static_cast<Maintenance *>(g());
    m->selectEDM(ml->model()->index(0,0).data().toString());
    m->selectVol(ui->IdR->text());
    foreach (OperationShow *op, _l) {
        m->addRemGrav(op->getid(),op->getrem(),op->getgrav());
    }
    m->addRapport();
}


void RapportShow::addOperation(OperationShow *op)
{
    ui->widget->layout()->addWidget(op);
    _l.append(op);
    setReadOnly(t);
}

void RapportShow::setReadOnly(bool t)
{
    _l.last()->setReadOnly(t);
}

void RapportShow::setg(Gerance *g)
{
    Show::setg(g);
    CHI * chi;
    if((chi=dynamic_cast<CHI *>(g)))
    {
    connect(chi,SIGNAL(doneOperation()),this,SLOT(setList()));
    }else if(dynamic_cast<Maintenance *>(g))
    {
        Maintenance *m=static_cast<Maintenance *>(g);
        connect(submit(),SIGNAL(clicked()),this,SLOT(addLeRapport()));
    }
}

void RapportShow::setList()
{
    CHI * chi;
    if((chi=dynamic_cast<CHI *>(g())))
    {
    foreach(Item *r, chi->Operationss[chi->getRapCounter()-1])
    {
        OperationShow *op=new OperationShow;
        Operations * o=static_cast<Operations *>(r);
        op->setDateh(QString::number(o->getIdOp()),o->getDescOp(),o->getGravite(),o->getRemarque());
        addOperation(op);
    }
    }
}

RapportShow::~RapportShow()
{
    delete ui;
}
