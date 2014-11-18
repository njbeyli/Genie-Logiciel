#include "directionwidget.h"

#include "Lists/programelist.h"
#include "Lists/voldaujourd.h"
#include "Drops/dropreceivedir.h"
#include "pdm.h"
#include "equipa.h"
#include "edm.h"
#include "compagnie.h"
#include "modele.h"
#include "avion.h"
#include "aeroport.h"

#include "Drops/modelcreator.h"
#include "Drops/eqmcreator.h"
#include "Drops/avioncreator.h"
#include "Drops/aerocreator.h"
#include "Drops/compagniecreator.h"
#include "Lists/generiquelist.h"

DirectionWidget::DirectionWidget(QWidget *parent):AbstractCentWid(parent)
{
    setObjectName("Direction");

    lc=new ListCollection;
    lc->append(new CommonList("Menu",new ProgrameList));
    lc->append(new CommonList("Employee Maintenance",new GeneriqueList));
    lc->append(new CommonList("Equipe Maintenance",new GeneriqueList));
    static_cast<GeneriqueList *>((*lc)[2]->leReste())->set_sh(new EqmCreator);
    lc->append(new CommonList("Equipe Aire",new GeneriqueList));
    static_cast<GeneriqueList *>((*lc)[3]->leReste())->set_sh(new EqmCreator);
    lc->append(new CommonList("Compagnie",new GeneriqueList));

    lc->append(new CommonList("Modele",new GeneriqueList));
    static_cast<GeneriqueList *>((*lc)[5]->leReste())->set_sh(new ModelCreator);
    lc->append(new CommonList("Avion",new GeneriqueList));
    static_cast<GeneriqueList *>((*lc)[6]->leReste())->set_sh(new AvionCreator);
    lc->append(new CommonList("AeroPort",new GeneriqueList));
    static_cast<GeneriqueList *>((*lc)[7]->leReste())->set_sh(new AeroCreator);

    set_lc(lc);
    _dir=new Direction();

    connect(_dir,SIGNAL(doneAero()),this,SLOT(setAero()));
    connect(_dir,SIGNAL(doneAvion()),this,SLOT(setAvion()));
    connect(_dir,SIGNAL(doneCompagnie()),this,SLOT(setComp()));
    connect(_dir,SIGNAL(doneEqA()),this,SLOT(setEqA()));
    connect(_dir,SIGNAL(doneEqM()),this,SLOT(setEqM()));
    connect(_dir,SIGNAL(doneModele()),this,SLOT(setModele()));
    connect(_dir,SIGNAL(donePDM()),this,SLOT(setPDM()));

    QStringList stringlist; stringlist<<"ajout Programe"
                                        <<"ajout Employe"
                                      <<"ajout Equipe"
                                      <<"ajout Model"
                                        <<"ajout AeroPort"
                                        <<"ajout Avion"
                                          <<"ajout Compagnie"
                                            ;

    (*lc)[0]->leReste()->setModel(stringlist);


    sc=new HorizontalShowCollection(_dir);
    set_sc(sc);

    add_dr(new DropReceiveDir(sc));
    add_dr(new DropReceiver(sc));


    lay();
}

void DirectionWidget::setModel()
{}
void DirectionWidget::setIndModel(int i)
{}

void DirectionWidget::setPDM()
{
    QStringList m;
    foreach (Item *pdm, _dir->ToutPersM) {
        m<<QString::number(static_cast<PDM *>(pdm)->getIdPDM())+" "+static_cast<PDM *>(pdm)->getNomPDM()+" "+static_cast<PDM *>(pdm)->getPrenomPDM();
    }
    (*lc)[1]->leReste()->setModel(m);
}
void DirectionWidget::setEqA()
{
    QStringList m;
    foreach (Item *pdm, _dir->EqA) {
        qDebug()<<"eqipa "<<static_cast<EquipA *>(pdm)->getIdEq();
        m<<QString::number(static_cast<EquipA *>(pdm)->getIdEq());
    }
    (*lc)[3]->leReste()->setModel(m);
}
void DirectionWidget::setEqM()
{
    QStringList m;
    foreach (Item *pdm, _dir->EqM) {
        m<<QString::number(static_cast<EDM *>(pdm)->getIdEquipe());
    }
    (*lc)[2]->leReste()->setModel(m);
}
void DirectionWidget::setComp()
{
    QStringList m;
    foreach (Item *pdm, _dir->Comp) {
        m<<QString::number(static_cast<Compagnie*>(pdm)->getIdComp())+" "+static_cast<Compagnie *>(pdm)->getNomComp();
    }
    (*lc)[4]->leReste()->setModel(m);
}
void DirectionWidget::setModele()
{
    QStringList m;
    foreach (Item *pdm, _dir->Mod) {
        m<<QString::number(static_cast<Modele *>(pdm)->getIdModele())+" "+static_cast<Modele *>(pdm)->getNomModele();
    }
    (*lc)[5]->leReste()->setModel(m);
}
void DirectionWidget::setAvion()
{
    QStringList m;
    foreach (Item *pdm, _dir->Av) {
        m<<QString::number(static_cast<Avion *>(pdm)->getIdAvion());
    }
    (*lc)[6]->leReste()->setModel(m);
}
void DirectionWidget::setAero()
{
    QStringList m;
    foreach (Item *pdm, _dir->Aero) {
        m<<QString::number(static_cast<Aeroport*>(pdm)->getNumAero())+" "+static_cast<Aeroport*>(pdm)->getNomAero();
    }
    (*lc)[7]->leReste()->setModel(m);
}
