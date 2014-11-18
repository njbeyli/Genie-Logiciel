#include "abstractcentwid.h"
#include "ui_abstractcentwid.h"
#include "Lists/mylistwidget.h"
#include "Lists/mytablewidget.h"

AbstractCentWid::AbstractCentWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AbstractCentWid)
{
    ui->setupUi(this);
}

void AbstractCentWid::resizeEvent(QResizeEvent *)
{
    QList<int> l;
    l<<200<<width()-200;
    ui->splitter->setSizes(l);
}

void AbstractCentWid::lay()
{
    ui->collect->setWidget(_lc);
    //static_cast<QVBoxLayout*>(ui->collect->layout())->addStretch();
    for(int i=0;i<_lc->length();++i)
    {
        //connect(static_cast<MyListWidget *>((*_lc)[0]->leReste()->_zL),SIGNAL(fetFiyyiEsm(int)),this,SLOT(setIndModel(int)));
        connect(static_cast<MyTableWidget *>((*_lc)[0]->leReste()->_zL),SIGNAL(fetFiyyiEsm(int)),this,SLOT(setIndModel(int)));

    }
    foreach(DropReceiver *dr,_dr)
    {
        ui->drops->layout()->addWidget(dr);
        ui->drops->layout()->setAlignment(dr,Qt::AlignLeft);
        QLabel *n=new QLabel;
        n->setText(dr->objectName());
        n->setAlignment(Qt::AlignCenter);
        n->setObjectName("dropsLabel");
        ui->drops->layout()->addWidget(n);
        //connect(dr,SIGNAL(fetFiyyiEsm(int)),this,SLOT(setIndModel(int)));
        static_cast<QHBoxLayout *>(ui->drops->layout())->addStretch();
    }

    ui->scrollArea->setWidget(_sc);
    //ui->shows->layout()->addWidget(_sc);
}

void AbstractCentWid::set_lc(ListCollection *lc)
{
    _lc=lc;
}
void AbstractCentWid::add_dr(DropReceiver *dr)
{
    _dr.append(dr);
}
void AbstractCentWid::set_sc(ShowCollection *sc)
{
    _sc=sc;
}


AbstractCentWid::~AbstractCentWid()
{
    delete ui;
}
