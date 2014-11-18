#include "programeshow.h"
#include "ui_programeshow.h"

#include "Drops/mystringmodel.h"
#include "direction.h"

#include <QDebug>

ProgrameShow::ProgrameShow(QString s, bool t,QWidget *parent) :
    Show(parent),
    ui(new Ui::ProgrameShow)
{
    ui->setupUi(this);
    ui->code->setText(s);
    _av=new MyListWidget;
    _ae=new MyListWidget;
    _eqm=new MyListWidget;
    _eqa=new MyListWidget;
    ui->Aeroport->layout()->addWidget(_ae);
    ui->Avion->layout()->addWidget(_av);
    ui->IdeqA->layout()->addWidget(_eqa);
    ui->IdeM->layout()->addWidget(_eqm);
    js.append(ui->lun);
    js.append(ui->mar);
    js.append(ui->merc);
    js.append(ui->jeud);
    js.append(ui->vend);
    js.append(ui->sam);
    js.append(ui->dim);

    setExitPos();
    //setReadOnly allways after setExitPos.
    setReadOnly(t);
}

void ProgrameShow::setg(Gerance *g)
{
    Show::setg(g);
    if((dynamic_cast<Direction *>(g)))
    {
        Direction *dir=dynamic_cast<Direction *>(g);
        dir->setIProgramme();
        connect(submit(),SIGNAL(clicked()),this,SLOT(saveProg()));
    }
}

void ProgrameShow::setReadOnly(bool t)
{
    ui->progwid->setEnabled(t);
    if(t)
    {
        _mav=new MyStringModel(this,true);
        _mae=new MyStringModel(this,true);
        _meqm=new MyStringModel(this,true);
        _meqa=new MyStringModel(this,true);

        _av->setDragEnabled(false);
        _av->setAcceptDrops(true);
        _av->setModel(_mav);
        _ae->setDragEnabled(false);
        _ae->setAcceptDrops(true);
        _ae->setModel(_mae);
        _eqm->setDragEnabled(false);
        _eqm->setAcceptDrops(true);
        _eqm->setModel(_meqm);
        _eqa->setDragEnabled(false);
        _eqa->setAcceptDrops(true);
        _eqa->setModel(_meqa);

    }
    ui->code_2->setVisible(t);
    t=!t;

    if(t)
    {
        ui->progwid->setAttribute(Qt::WA_TransparentForMouseEvents);
        submit()->deleteLater();
    }
    ui->dateentree->setReadOnly(t);
    ui->datesortie->setReadOnly(t);
    ui->direction->setReadOnly(t);
    ui->duree->setReadOnly(t);
}

void ProgrameShow::saveProg()
{

    if((dynamic_cast<Direction *>(g())))
    {
        Direction *dir=dynamic_cast<Direction *>(g());
        for(int i=0;i<js.length();++i)
        {
            if(static_cast<QPushButton*>(js[i]->itemAt(1)->widget())->isChecked())
            {
                dir->addJour(QString::number(i+1),\
                             static_cast<QTimeEdit*>(js[i]->itemAt(2)->widget())->time(),
                             static_cast<QSpinBox *>(js[i]->itemAt(0)->widget())->text());
            }
        }
        dir->addProgramme(_mav->index(0,0).data().toString()
                          ,_meqm->index(0,0).data().toString()
                          ,_mae->index(0,0).data().toString().split(QRegularExpression("\\s+"))[0]
                          ,_meqa->index(0,0).data().toString()
                          ,ui->code_2->text()
                          ,ui->direction->text()
                          ,ui->dateentree->date()
                          ,ui->datesortie->date()
                          ,ui->duree->text());
//        qDebug()<<_mav->index(0,0).data().toString()<<" "
//                  <<_meqm->index(0,0).data().toString()<<" "
//                  <<_mae->index(0,0).data().toString()<<" "
//                  <<_meqa->index(0,0).data().toString()<<" "
//                  <<ui->code_2->text()<<" "
//                  <<ui->direction->text()<<" "
//                  <<ui->dateentree->date()<<" "
//                  <<ui->datesortie->date()<<" "
//                  <<ui->duree->text();
    }
}

ProgrameShow::~ProgrameShow()
{
    delete ui;
}
