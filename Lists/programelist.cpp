#include "programelist.h"

#include "Drops/programecreator.h"
#include <QStringListModel>
#include <QVBoxLayout>
#include "Filters/textfilter.h"
#include "Drops/multicreator.h"
#include "Drops/programecreator.h"
#include "Drops/eqmcreator.h"
#include "Drops/emplcreator.h"
#include "Drops/modelcreator.h"
#include "Drops/aerocreator.h"
#include "Drops/compagniecreator.h"
#include "Drops/avioncreator.h"

ProgrameList::ProgrameList(QWidget *parent) :
    AbstractList(parent)
{
    _tf=new TextFilter;
    _model=0;
    _zModel=new QSortFilterProxyModel(this);
    _zModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    connect(_tf,SIGNAL(filterExp(QString)),_zModel,SLOT(setFilterRegExp(QString)));
    QVBoxLayout *vbl=new QVBoxLayout;
    vbl->setMargin(0);vbl->setSpacing(0);

    vbl->addWidget(_tf);

    _ml=new MyListWidget;
    _zL=_ml;

    vbl->addWidget(_ml);

    setLayout(vbl);
}

void ProgrameList::setModel(QAbstractItemModel *im)
{
    _model=im;
    _zModel->setSourceModel(_model);

    _ml->setModel(_zModel);
}

void ProgrameList::setModel(QList<QString> s)
{
    if(_model)
        delete _model;
    _model=new QStringListModel(s,this);
    _zModel->setSourceModel(_model);
    _ml->setModel(_zModel);
    MultiCreator *mc=new MultiCreator;
    mc->l.append(new ProgrameCreator);
    mc->l.append(new EmplCreator);
    mc->l.append(new EqmCreator);
    mc->l.append(new ModelCreator);
    mc->l.append(new AeroCreator);
    mc->l.append(new AvionCreator);
    mc->l.append(new CompagnieCreator);

    _ml->set_sh(mc);
}
