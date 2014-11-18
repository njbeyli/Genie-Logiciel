#include "mylistwidget.h"



#include <QDebug>

MyListWidget::MyListWidget(QWidget *parent) :
    QListView(parent)
{
    setEditTriggers(QListView::NoEditTriggers);
    setDragEnabled(true);
    _sh=0;
}

void MyListWidget::set_sh(ShowCreators *sh)
{
    _sh=sh;
}

ShowCreators* MyListWidget::sh()const
{
    return _sh;
}

MyListWidget::~MyListWidget()
{
    delete _sh;
}

void MyListWidget::sendSignalToParent(int i) const
{
    emit fetFiyyiEsm(i);
}

