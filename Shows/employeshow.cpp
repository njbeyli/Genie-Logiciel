#include "employeshow.h"
#include "ui_employeshow.h"

#include "direction.h"

EmployeShow::EmployeShow(QString s,bool type,QWidget *parent) :
    Show(parent),
    ui(new Ui::EmployeShow)
{
    ui->setupUi(this);
    setExitPos();
    setReadOnly(type);
}

void EmployeShow::setg(Gerance *g)
{
    Show::setg(g);
    if(dynamic_cast<Direction*>(g))
    {
        Direction *dir=dynamic_cast<Direction*>(g);
        connect(submit(),SIGNAL(clicked()),this,SLOT(addAero()));
    }

}

void EmployeShow::shuMeshi()
{
    static_cast<Direction *>(g())->getAero();
}

void EmployeShow::addAero()
{
    static_cast<Direction *>(g())->setIAero();
    static_cast<Direction *>(g())->addAero(ui->Nom->text(),ui->Ville->text());
    connect(static_cast<Direction *>(g()),SIGNAL(doneAddingAero()),this,SLOT(shuMeshi()));
}

void EmployeShow::setReadOnly(bool t)
{
    t=!t;
    if(t)
    {
        submit()->deleteLater();
        ui->Nom->setReadOnly(t);
        ui->Ville->setReadOnly(t);
    }
}

EmployeShow::~EmployeShow()
{
    delete ui;
}
