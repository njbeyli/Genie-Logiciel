#include "tousvol.h"
#include "Filters/textfilter.h"
#include "Drops/volcreator.h"
#include <QVBoxLayout>
#include <QHeaderView>

TousVol::TousVol(QWidget *parent) :
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
    _ml=new MyTableWidget;
    _zL=_ml;
    _ml->verticalHeader()->hide();

    _ml->set_sh(new VolCreator);

    vbl->addWidget(_ml);

    setLayout(vbl);

}

void TousVol::setModel(QAbstractItemModel *im)
{
    _model=im;
    _zModel->setSourceModel(_model);

    _ml->setModel(_zModel);
}

void TousVol::setModel(QList<QString> s)
{
    //A implementer si on veut
}
