#include "mybotdock.h"
#include "dockbutton.h"
#include <QHBoxLayout>

#include <QDebug>

const QSize BS(120,120);
const QSize SS(100,100);

MyBotDock::MyBotDock(QList<QWidget *> l,QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout *hbl=new QHBoxLayout;
    hbl->setMargin(0);
    hbl->setSpacing(20);
    hbl->addStretch();
    _selectedPos=0;
    foreach(QWidget * qw,l)
    {
        QPushButton *b=new DockButton(_l.length(),BS,SS,qw->objectName());
        hbl->addWidget(b,0,Qt::AlignBottom);
        b->setCheckable(true);
        _l.append(b);
        connect(static_cast<DockButton *>(b),SIGNAL(pos(int)),this,SLOT(sendCheckedPos(int)));

    }
    hbl->addStretch();
    setLayout(hbl);
    sizingEvent();
}

void MyBotDock::sizingEvent()
{
    setGeometry(0,static_cast<QWidget*>(parent())->height()-BS.height(),static_cast<QWidget*>(parent())->width(),BS.height());
}

void MyBotDock::leaveEvent(QEvent *)
{
    setVisible(false);
}

void MyBotDock::sendCheckedPos(int t)
{
    if(t==_selectedPos)
    {
        _l[t]->setChecked(true);
        return;
    }
     _l[_selectedPos]->setChecked(false);
     _selectedPos=t;
     emit inElementClicked(t);
}


