#include "avionshow.h"
#include "ui_avionshow.h"
#include "direction.h"
#include "Drops/mystringmodel.h"


AvionShow::AvionShow(QString s,bool type,QWidget *parent) :
    Show(parent),
    ui(new Ui::AvionShow)
{
    ui->setupUi(this);
    setExitPos();
    setReadOnly(type);
    ui->Id->setText(s);
    _idc=new MyListWidget;
    ui->IdC->layout()->addWidget(_idc);
    _idm=new MyListWidget;
    ui->IdMo->layout()->addWidget(_idm);
    _idc->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _idm->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void AvionShow::setReadOnly(bool t)
{
    t=!t;
    if(t)
    {
        submit()->deleteLater();
    }
}

void AvionShow::setg(Gerance *g)
{
    Show::setg(g);
    if((dynamic_cast<Direction *>(g)))
    {
        Direction * dir=dynamic_cast<Direction *>(g);
        MyStringModel * sm=new MyStringModel(this,true);
        _idc->setModel(sm);
        _idc->setAcceptDrops(true);
        sm=new MyStringModel(this,true);
        _idm->setModel(sm);
        _idm->setAcceptDrops(true);
        connect(submit(),SIGNAL(clicked()),this,SLOT(addAvion()));
    }
}

void AvionShow::addAvion()
{
    Direction * dir=dynamic_cast<Direction *>(g());
    QString idc,idm;
    idc=_idc->model()->index(0,0).data().toString().split(QRegularExpression("\\s+"))[0];
    idm=_idm->model()->index(0,0).data().toString().split(QRegularExpression("\\s+"))[0];
    dir->setIAvion();
    connect(dir,SIGNAL(doneAddingAvion()),this,SLOT(maktir3ambetfidbascava()));
    dir->addAvion(idm,idc,ui->IdAvC->text(),"0");
}

void AvionShow::maktir3ambetfidbascava()
{
    static_cast<Direction *>(g())->getAv();
}

AvionShow::~AvionShow()
{
    delete ui;
}
