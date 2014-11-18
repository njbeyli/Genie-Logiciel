#include "volshow.h"
#include "ui_volshow.h"
#include <QStringListModel>
#include <QDebug>
#include "Drops/eqmcreator.h"
#include "chi.h"
#include "fly.h"
#include "update.h"
#include "Drops/rapportcreator.h"
#include "Drops/mystringmodel.h"

VolShow::VolShow(QString s, bool type, QWidget *parent) :
    Show(parent),
    ui(new Ui::VolShow)
{
    ui->setupUi(this);
    id=s.toInt();
    //ui->Code->setText(s);
    _eq=new MyListWidget; _eq->set_sh(new EqmCreator);
    _av=new MyListWidget;
    _rp=new MyListWidget; _rp->set_sh(new RapportCreator);
    _ae=new MyListWidget;

    connect(_rp,SIGNAL(fetFiyyiEsm(int)),this,SLOT(setRapVolRef(int)));
    ui->avionC->layout()->addWidget(_av);
    ui->EquipeC->layout()->addWidget(_eq);
    ui->RapportC->layout()->addWidget(_rp);
    ui->aeroC->layout()->addWidget(_ae);
    setExitPos();
    setReadOnly(type);
    pos=-1;
}

void VolShow::setReadOnly(bool t)
{
    if(!t)
    {
        submit()->deleteLater();
    }
}

void VolShow::setg(Gerance * g)
{
    Show::setg(g);
    if((dynamic_cast<CHI *>(g)))
    {
        CHI * chi=dynamic_cast<CHI *>(g);
        connect(chi,SIGNAL(doneLoad()),this,SLOT(setLastVolAtt()));
        connect(chi,SIGNAL(doneLoadProg()),this,SLOT(setLastVolAttProg()));
        chi->getVolSel(QString::number(id));
    }
    else if(dynamic_cast<Fly *>(g))
    {
        Fly* chi=dynamic_cast<Fly *>(g);
        ui->aeroC->setVisible(false);
        ui->direction->setVisible(false);
        ui->duree->setVisible(false);
        ui->RapportC->setVisible(false);

                chi->selectVol(QString::number(id));
               ui->datePrevu->setDate(chi->Vc->getDatPreVol());
                ui->heurePrevu->setTime(chi->Vc->getHeurPreVol());
                ui->Etat->setText(chi->Vc->getEtatVol());
                QStringList l; l<<QString::number(chi->Vc->getIdAvion());
                QStringListModel *lm=new QStringListModel(l,this);
                _av->setModel(lm);
                l.clear(); l<<QString::number(chi->Vc->getIdEquipe());
                lm=new QStringListModel(l);
                _eq->setModel(lm);
                l.clear();
                submit()->setText("Take-Off");
                if(chi->Vc->getDatReVol().isNull())
                {
                ui->dateReel->setVisible(false);
                ui->heureReel->setVisible(false);
                }
                connect(submit(),SIGNAL(clicked()),this,SLOT(take()));
     }
    else if(dynamic_cast<Update *>(g))
    {
       Update * chi=dynamic_cast<Update *>(g);
        int i;
       for(i=0;i<chi->Vo.length();++i)
       {
           if(chi->Vo[i]->getIdVol()==id)
               break;
       }

       ui->datePrevu->setDate(chi->Vo[i]->getDatPreVol());
       ui->heurePrevu->setTime(chi->Vo[i]->getHeurPreVol());

       ui->datePrevu->setReadOnly(false);
       ui->heurePrevu->setReadOnly(false);

       QStringList l; l<<QString::number(chi->Vo[i]->getIdAvion());
       QStringListModel *lm=new MyStringModel(this,true);
       lm->setStringList(l);
       _av->setModel(lm);
       _av->setAcceptDrops(true);
       l.clear(); l<<QString::number(chi->Vo[i]->getIdEquipe());
       lm=new MyStringModel(this,true);
       lm->setStringList(l);
       _eq->setModel(lm);
       _eq->setAcceptDrops(true);
       l.clear();

       _rp->setVisible(false);
       ui->dateReel->setVisible(false);
       ui->heureReel->setVisible(false);
       ui->direction->setVisible(false);
       ui->duree->setVisible(false);
       ui->aeroC->setVisible(false);
       ui->Etat->setVisible(false);
       connect(submit(),SIGNAL(clicked()),this,SLOT(updatevole()));
    //connect(chi,SIGNAL(doneLoad()),this,SLOT(setLastVolAtt()));

    //connect(exit(),SIGNAL(clicked()),this,SLOT(close()));
    //qDebug()<<chi->InfoProg.length();
    //chi->getVolSel(QString::number(id));
    }
}

void VolShow::updatevole()
{
    Update * upd=static_cast<Update *>(g());
    upd->setIVol(QString::number(id));

    upd->updateVo(_eq->model()->index(0,0).data().toString()
                  ,_eq->model()->index(0,0).data().toString()
                  ,ui->datePrevu->date(),ui->heurePrevu->time());
}

void VolShow::take()
{
    Fly* chi=static_cast<Fly *>(g());
    chi->takeOff();
    ui->dateReel->setVisible(true);
    ui->heureReel->setVisible(true);
    ui->dateReel->setDate(chi->Vc->getDatReVol());
    ui->heureReel->setTime(chi->Vc->getHeurReVol());
}

void VolShow::close()
{
//    CHI * chi=static_cast<CHI *>(g());
//    qDebug()<<pos;
//    chi->closeVol(QString::number(pos));
}

void VolShow::setLastVolAtt()
{
    CHI * chi;
    if((chi=dynamic_cast<CHI *>(g())))
    {
    if(pos==-1)
        pos=chi->getCounter()-1;
    QString s;
    for(int i=0;i<chi->InfoProg.length();++i)
    {
        if(chi->Vols[i]->getIdVol()==id)
            s=chi->InfoProg[i];
    }
    setModels(chi->V[pos],chi->Rapportss[pos],s);//a cont

    }
}
void VolShow::setLastVolAttProg()
{
    CHI * chi;
    if((chi=dynamic_cast<CHI *>(g())))
   {if(pos==-1)
        pos=chi->getCounter()-1;
    setModels(chi->Programmes[pos]);
    }
}

void VolShow::setRapVolRef(int i)
{
    CHI * chi;
    if((chi=dynamic_cast<CHI *>(g())))
        chi->RapportsSelected(QString::number(static_cast<Rapports*>(chi->Rapportss[pos][i])->getIdRapport()),QString::number(chi->V[pos]->getIdVol()));
}


void VolShow::setModels(Vol *v, QList<Item *> rapport,QString s)
{
  //  qDebug()<<v->getEtatVol();

    ui->datePrevu->setDate(v->getDatPreVol());
    ui->heurePrevu->setTime(v->getHeurPreVol());
    //ui->direction->setText(v->);
    if(v->getDatReVol().isNull()||v->getDatReVol()==QDate(0,0,0))
    {
        ui->dateReel->setVisible(false);
        ui->heureReel->setVisible(false);
    }
    ui->dateReel->setDate(v->getDatReVol());
    ui->heureReel->setTime(v->getHeurReVol());

    ui->Etat->setText(v->getEtatVol());
    ui->Code->setText(s);
    QStringList l; l<<QString::number(v->getIdAvion());
    QStringListModel *lm=new QStringListModel(l,this);
    _av->setModel(lm);
    l.clear(); l<<QString::number(v->getIdEquipe());
    lm=new QStringListModel(l);
    _eq->setModel(lm);
    l.clear();
    foreach(Item * ra,rapport)
    {
        l<<QString::number(static_cast<Rapports *>(ra)->getIdRapport());
    }
    lm=new QStringListModel(l);
    _rp->setModel(lm);
}

void VolShow::setModels(Programme *p)
{
    ui->duree->setText(QString::number(p->getDuree())+=" heur");
    ui->direction->setText(p->getDirection());
    QStringList l; l<<QString::number(p->getNumAero());
    QStringListModel *lm=new QStringListModel(l,this);
    _ae->setModel(lm);
}

VolShow::~VolShow()
{
    delete ui;
}
