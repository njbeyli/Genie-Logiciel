#include "operationshow.h"
#include <QHBoxLayout>
#include <QDebug>

OperationShow::OperationShow(QWidget *parent) :
    QWidget(parent)
{
    _code=new QLabel("Id : ");_code->setFixedSize(50,20);
    _desc=new QLabel("Description : ");_desc->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    _grav=new QSpinBox;
    _rem= new QTextEdit;_rem->setFixedHeight(40);
    QHBoxLayout *hb=new QHBoxLayout;
    hb->setMargin(0);hb->setSpacing(2);

    hb->addWidget(_code);
    hb->addWidget(_desc);
    hb->addWidget(new QLabel("Gravite : "));
    hb->addWidget(_grav);

    QVBoxLayout *vb=new QVBoxLayout;
    vb->setContentsMargins(30,2,3,2);vb->setSpacing(0);
    vb->addLayout(hb);
    vb->addWidget(_rem);
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
    setLayout(vb);
}

void OperationShow::setDateh(QString c, QString d, int g, QString r)
{
    _code->setText(_code->text()+c);
    _desc->setText(_desc->text()+d);
    _grav->setValue(g);
    _rem->setText(r);
}
QString OperationShow::getid()const
{
    return _code->text();
}
QString OperationShow::getgrav()const
{
    return _grav->text();
}
QString OperationShow::getrem()const
{
    return _rem->toPlainText();
}
void OperationShow::setReadOnly(bool t)
{
    _grav->setReadOnly(!t);
    _rem->setReadOnly(!t);
}
