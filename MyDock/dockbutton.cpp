#include "dockbutton.h"

DockButton::DockButton(int i,QSize b,QSize s,QString t,QWidget *parent) :
    QPushButton(t,parent),_i(i),_s(s),_b(b)
{
    setFixedSize(_s);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedInDock()));
}

void DockButton::clickedInDock()
{

    emit this->pos(_i);
}

void DockButton::enterEvent(QEvent *)
{
    setFixedSize(_b);
}
void DockButton::leaveEvent(QEvent *)
{
    setFixedSize(_s);
}
