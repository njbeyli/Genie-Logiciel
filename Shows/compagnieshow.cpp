#include "compagnieshow.h"
#include "ui_compagnieshow.h"

#include "direction.h"

CompagnieShow::CompagnieShow(QString s, bool type, QWidget *parent) :
    Show(parent),
    ui(new Ui::CompagnieShow)
{
    ui->setupUi(this);
    setExitPos();
    setReadOnly(type);
}

void CompagnieShow::setReadOnly(bool t)
{
    t=!t;
    if(t)
    {
        submit()->deleteLater();
        ui->lineEdit->setReadOnly(t);
        ui->lineEdit_2->setReadOnly(t);
    }
}

void CompagnieShow::setg(Gerance *g)
{
    Show::setg(g);
    if(dynamic_cast<Direction *>(g))
    {
        Direction *dir=dynamic_cast<Direction*>(g);
        connect(submit(),SIGNAL(clicked()),this,SLOT(addCompagnie()));
    }
}

void CompagnieShow::addCompagnie()
{
    static_cast<Direction *>(g())->setICompagnie();
    static_cast<Direction *>(g())->addCompagnie(ui->lineEdit->text(),ui->lineEdit_2->text());
    connect(static_cast<Direction *>(g()),SIGNAL(doneAddingComp()),this,SLOT(leffha()));
}

void CompagnieShow::leffha()
{
    static_cast<Direction *>(g())->getCompagnie();
}

CompagnieShow::~CompagnieShow()
{
    delete ui;
}
