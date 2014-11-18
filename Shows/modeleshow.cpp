#include "modeleshow.h"
#include "ui_modeleshow.h"

#include "direction.h"

ModeleShow::ModeleShow(QString s,bool type,QWidget *parent) :
    Show(parent),
    ui(new Ui::ModeleShow)
{
    ui->setupUi(this);
   setExitPos();
   setReadOnly(type);
}

ModeleShow::~ModeleShow()
{
    delete ui;
}

void ModeleShow::addModele()
{
    static_cast<Direction *>(g())->setIModele();
    static_cast<Direction *>(g())->addModele(ui->Reser->text(),ui->DistM->text(),ui->vitC->text(),ui->lineEdit->text());
    connect(static_cast<Direction *>(g()),SIGNAL(doneAddingModel()),this,SLOT(leffha()));
}

void ModeleShow::leffha()
{
    static_cast<Direction *>(g())->getModele();
}

void ModeleShow::setg(Gerance *g)
{
    Show::setg(g);
    if(dynamic_cast<Direction*>(g))
    {
        Direction *dir=dynamic_cast<Direction*>(g);
        connect(submit(),SIGNAL(clicked()),this,SLOT(addModele()));
    }
}

void ModeleShow::setReadOnly(bool t)
{
    t=!t;
    if(t)
    {
        submit()->deleteLater();

        ui->DistM->setReadOnly(t);
        ui->Reser->setReadOnly(t);
        ui->vitC->setReadOnly(t);
        ui->lineEdit->setReadOnly(t);
    }
}
