#include "empdemaintshow.h"
#include "ui_empdemaintshow.h"

#include "direction.h"

EmpDeMaintShow::EmpDeMaintShow(QWidget *parent) :
    Show(parent),
    ui(new Ui::EmpDeMaintShow)
{
    ui->setupUi(this);
    setExitPos();
}

void EmpDeMaintShow::setg(Gerance *g)
{
    Show::setg(g);
    if(dynamic_cast<Direction*>(g))
    {
        Direction *dir=dynamic_cast<Direction*>(g);
        connect(submit(),SIGNAL(clicked()),this,SLOT(addPerson()));
    }
}

void EmpDeMaintShow::addPerson()
{
    Direction *dir;
    if(dir=dynamic_cast<Direction*>(g()))
    {
        dir->setIPDM();
        connect(dir,SIGNAL(doneAddingPDm()),this,SLOT(leffha()));
        dir->addPersonnel(ui->Nom->text(),ui->Pronom->text());
    }
}

void EmpDeMaintShow::leffha()
{
    Direction *dir;
    if(dir=dynamic_cast<Direction*>(g()))
        dir->getAllPDM();
}

void EmpDeMaintShow::setReadOnly(bool t)
{

}

EmpDeMaintShow::~EmpDeMaintShow()
{
    delete ui;
}
