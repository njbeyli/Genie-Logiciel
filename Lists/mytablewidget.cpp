#include "mytablewidget.h"

MyTableWidget::MyTableWidget(QWidget *parent) :
    QTableView(parent)
{
    setEditTriggers(QTableView::NoEditTriggers);
    setDragEnabled(true);
    //setSelectionMode(QAbstractItemView::ExtendedSelection);
    _sh=0;
}
void MyTableWidget::set_sh(ShowCreators *sh)
{
    _sh=sh;
}

ShowCreators* MyTableWidget::sh()const
{
    return _sh;
}

void MyTableWidget::sendSignalToParent(int i) const
{
    emit fetFiyyiEsm(i);
}

MyTableWidget::~MyTableWidget()
{
    delete _sh;
}
