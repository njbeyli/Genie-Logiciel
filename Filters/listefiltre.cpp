#include "listefiltre.h"



ListeFiltre::ListeFiltre(QString s,QWidget *parent) :
    AbstractFilter(parent)
{
    _qvb=new QVBoxLayout;
    _qvb->setMargin(0);_qvb->setSpacing(0);

    _head=new QPushButton(s);
    _head->setFixedHeight(20);
    _checkTous=new QCheckBox("Tous");
    _head->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    _checkTous->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);

    QHBoxLayout *qhb=new QHBoxLayout;
    qhb->setMargin(0);qhb->setSpacing(0);

    qhb->addWidget(_head);
    qhb->addWidget(_checkTous);

    connect(_head,SIGNAL(clicked()),this,SLOT(hide_lv()));
    connect(_checkTous,SIGNAL(clicked(bool)),this,SLOT(check(bool)));


    _lv=new QListView;
    _lv->setMaximumHeight(100);
    _lv->setSelectionMode(QAbstractItemView::MultiSelection);
    _lv->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    connect(_lv,SIGNAL(pressed(QModelIndex)),this,SLOT(sCheck()));

    _qvb->addLayout(qhb);
    setLayout(_qvb);
    //_lv->

}

void ListeFiltre::sCheck()
{
    if(_lv->selectionModel()->selectedIndexes().length()==_lm->rowCount())
    {
        _checkTous->setChecked(true);
    }
    else
    {
        _checkTous->setChecked(false);
    }
}

QListView *ListeFiltre::lv() const
{
    return _lv;
}

void ListeFiltre::hide_lv()
{
    _lv->setVisible(_lv->isHidden());
}

void ListeFiltre::check(bool checked)
{
    if(checked)
        _lv->selectAll();
    else
        _lv->clearSelection();
}

void ListeFiltre::iShouldSend()
{
    //qDebug()<<"hala";
}
