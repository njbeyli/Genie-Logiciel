#include "voldaujourd.h"
#include "ui_voldaujourd.h"
#include "Filters/textfilter.h"
#include <QVBoxLayout>

#include "Drops/volpassagercreator.h"
#include "Drops/programecreator.h"
#include "Drops/myteststringmodel.h"


VolDaujourd::VolDaujourd(QWidget *parent) :
    AbstractList(parent)
{
   _l.append(new TextFilter);

   _model=0;
   _zModel=new QSortFilterProxyModel(this);
   _zModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
   connect(_l[0],SIGNAL(filterExp(QString)),_zModel,SLOT(setFilterRegExp(QString)));
   QVBoxLayout *vbl=new QVBoxLayout;
   vbl->setMargin(0);vbl->setSpacing(0);

   foreach (AbstractFilter *af, _l) {
       vbl->addWidget(af);
   }

   _ml=new MyListWidget;
   _zL=_ml;
   _ml->set_sh(new VolPassagerCreator);

//   QStringListModel *qslm=new QStringListModel;
//   QStringList l;
//   l<<"hi"<<"bi"<<"sawwa7"<<"wana"<<"mashi"<<"zazi"<<"zazu"<<"fazu"<<"yaM3allem"<<"MH 370"<<"MV 400";
//   qslm->setStringList(l);

   //_ml->setModel(zModel);

   vbl->addWidget(_ml);

   setLayout(vbl);
}

void VolDaujourd::setModel(QAbstractItemModel *im)
{
    _model=im;
    _zModel->setSourceModel(_model);

    _ml->setModel(_zModel);
}

void VolDaujourd::setModel(QList<QString> s)
{
    if(_model)
        delete _model;
    _model=new QStringListModel(s,this);
    _zModel->setSourceModel(_model);
    _ml->setModel(_zModel);
}
void VolDaujourd::setModel(QList<int> ids)
{
    //static_cast<MyTestStringModel*>(_model)->set_ids(ids);
}
