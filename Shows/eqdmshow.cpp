#include "eqdmshow.h"
#include "ui_eqdmshow.h"

#include "chi.h"
#include "edm.h"
#include "pdm.h"
#include <QStringListModel>
#include <QDebug>
#include <QSortFilterProxyModel>
#include "direction.h"
#include "Drops/mystringmodel.h"

EqDMShow::EqDMShow(QString s, bool t, QWidget *parent) :
    Show(parent),
    ui(new Ui::EqDMShow)
{
    ui->setupUi(this);
    ui->IdEq->setText(s);
    _ml=new MyListWidget;
    ui->widget->layout()->addWidget(_ml);

    setExitPos();
    setReadOnly(t);
}

void EqDMShow::setReadOnly(bool t)
{
    if(!t)
    {
        submit()->deleteLater();
        _submit=0;
    }
    else
    {

        _ml->setModel(new MyStringModel);
        _ml->setAcceptDrops(true);
    }
}

void EqDMShow::setModels(QList<Item *> personnel)
{
    QStringList l;
    foreach(Item *it,personnel)
    {
        l<<static_cast<PDM*>(it)->getNomPDM()+" "+static_cast<PDM*>(it)->getPrenomPDM();
    }
    QStringListModel *lm=new QStringListModel(l,this);
    QSortFilterProxyModel *fm=new QSortFilterProxyModel(this);
    fm->setSourceModel(lm);
    TextFilter *tf=new TextFilter;
    ui->widget_2->layout()->addWidget(tf);
    connect(tf,SIGNAL(filterExp(QString)),fm,SLOT(setFilterRegExp(QString)));
    _ml->setModel(fm);
}

void EqDMShow::setg(Gerance *g)
{
    Show::setg(g);
    CHI * chi;
    if((chi=dynamic_cast<CHI *>(g)))
    {
    for(int i=0;i<chi->Equipes.length();++i)
    {
    if(ui->IdEq->text()==QString::number(chi->Equipes[i]->getIdEquipe()))
    {
        setModels(chi->Personnels[i]);
        break;
    }
    }
    }
    else if(dynamic_cast<Direction*>(g))
    {
        Direction * dir=dynamic_cast<Direction*>(g);
        if(!submit())
        {
            connect(dir,SIGNAL(doneZPDM()),this,SLOT(setPersonnel()));
            dir->getPDM(ui->IdEq->text());
        }
        else
        {

            connect(submit(),SIGNAL(clicked()),this,SLOT(addEq()));
        }
    }
}

void EqDMShow::su()
{
    Direction *dir=static_cast<Direction *>(g());
    QString s=QString::number(static_cast<EDM*>(dir->EqM.last())->getIdEquipe());
    for(int i=0;i<_ml->model()->rowCount();++i)
    {
       dir->connectPDMEDM(s,_ml->model()->index(i,0).data().toString().split(QRegularExpression("\\s+"))[0]);
    }
    //dir->connectPDMEDM(s,);
}

void EqDMShow::addpdmtoeq()
{
    Direction *dir=static_cast<Direction *>(g());
    connect(dir,SIGNAL(doneEqM()),this,SLOT(su()));
    dir->getEqM();
}

void EqDMShow::setPersonnel()
{
    setModels(static_cast<Direction *>(g())->PersM.last());
}

void EqDMShow::addEq()
{
    Direction *dir=static_cast<Direction *>(g());
    dir->setIEDM();
    connect(dir,SIGNAL(doneAddingEDm()),this,SLOT(addpdmtoeq()));
    dir->addEDM();

}

EqDMShow::~EqDMShow()
{
    delete ui;
}
