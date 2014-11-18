#include "guichetshow.h"
#include "ui_guichetshow.h"

#include <QStringListModel>
#include "Drops/mystringmodel.h"

#include <QDebug>

GuichetShow::GuichetShow(QString s, QWidget *parent) :
    Show(parent),
    ui(new Ui::GuichetShow)
{
    ui->setupUi(this);

    _mo=0;
    _mn=0;

    ui->code->setText(s);
    _co=new TextFilter();
    ui->chercheOui->layout()->addWidget(_co);
    _cn=new TextFilter();
    ui->chercheNo->layout()->addWidget(_cn);
    _lo=new MyListWidget();
    ui->PassagerOui->layout()->addWidget(_lo);
    _ln=new MyListWidget();
    ui->PassagerNo->layout()->addWidget(_ln);

//    QStringList l;
//    l<<"test"<<"wa7ad"<<"tnen"<<"tleteh"<<"arb3a";
//    l<<"5amis"<<"jum3a"<<"alla y3in"<<"kul man"<<"laysa";
//    l<<"biyya3in"<<"hayda ya 7abibi"<<"fred le malin";

    _mo=new MyStringModel(this);
    _mn=new QStringListModel(this);

    _fmo=new QSortFilterProxyModel(this);
    connect(_co,SIGNAL(filterExp(QString)),_fmo,SLOT(setFilterRegExp(QString)));
    _fmo->setSourceModel(_mo);
    //_mo->

    _fmn=new QSortFilterProxyModel(this);
    connect(_cn,SIGNAL(filterExp(QString)),_fmn,SLOT(setFilterRegExp(QString)));
    _fmn->setSourceModel(_mn);


    _lo->setDragEnabled(false);
    //_ln->setDragDropMode(QAbstractItemView::InternalMove);
    _lo->setAcceptDrops(true);

    _lo->setModel(_fmo);
    _ln->setModel(_fmn);
    //set_show;

    connect(static_cast<MyStringModel *>(_mo),SIGNAL(fetFiyi(QString)),this,SLOT(insertThe(QString)));
    //qDebug()<<_mn->index(3,0).data().toString();

    setExitPos();
    setReadOnly(false);
}

void GuichetShow::insertThe(QString s)
{
   emit check(_isz[s]);

              //.toString();
}

void GuichetShow::setReadOnly(bool t)
{
    if(!t)
    {
        submit()->deleteLater();
    }
}

void GuichetShow::setModels(QList<Passager *> l)
{
    QStringList sn,so;
    foreach (Passager * pass, l) {
        if(pass->getCheckIn())
            so.append(pass->getNomPass());
        else
            sn.append(pass->getNomPass());
        _isz.insert(pass->getNomPass(),pass->getIdPass());
    }
    static_cast<QStringListModel*>(_mo)->setStringList(so);
    static_cast<MyStringModel*>(_mn)->setStringList(sn);

}
void GuichetShow::setModels(QList<Passager *> l, int)
{
    QStringList sn,so;
    foreach (Passager * pass, l) {
        if(pass->getOnBoard())
            so.append(pass->getNomPass());
        else if(pass->getCheckIn())
            sn.append(pass->getNomPass());
        _isz.insert(pass->getNomPass(),pass->getIdPass());
    }
    static_cast<QStringListModel*>(_mo)->setStringList(so);
    static_cast<MyStringModel*>(_mn)->setStringList(sn);
}

GuichetShow::~GuichetShow()
{
    delete ui;
}
