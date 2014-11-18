#include "textfilter.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>

TextFilter::TextFilter(QWidget *parent) :
    AbstractFilter(parent)
{
    QHBoxLayout *qhb=new QHBoxLayout;
    qhb->setSpacing(0);qhb->setMargin(0);

    QLabel *l=new QLabel("Cherche :");
    l->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
    l->setFixedHeight(20);

    _le=new QLineEdit;
    _le->setPlaceholderText("Cherche");
    _le->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    _le->setFixedHeight(20);

    qhb->addWidget(l);
    qhb->addWidget(_le);

    setLayout(qhb);

    connect(_le,SIGNAL(textEdited(QString)),this,SLOT(iShouldSend()));
}

void TextFilter::iShouldSend()
{
    //qDebug()<<_le->text();
    emit filterExp(/*QString("\^")+=*/_le->text()/*+=".*"*/);
}
