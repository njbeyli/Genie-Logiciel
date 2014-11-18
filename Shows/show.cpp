#include "show.h"

Show::Show(QWidget *parent) :
    QFrame(parent)
{
    setFrameShadow(QFrame::Raised);
    setFrameShape(QFrame::Box);
}

QPushButton* Show::exit()
{
    return _exit;
}

QPushButton* Show::submit()
{
    return _submit;
}

Gerance * Show::g()const
{
    return _g;
}
void Show::setg(Gerance *g)
{
    _g=g;
}

void Show::setExitPos()
{
    _exit=new QPushButton("X",this);
    _exit->setFixedSize(15,15);
    _exit->setVisible(false);
    _exit->move(width()-2*exit()->width(),exit()->height());

    _submit=new QPushButton("SUBMIT",this);
    _submit->setVisible(false);
    _submit->setFixedSize(80,20);
    _submit->move(width()-3*exit()->width()-_submit->width(),10);
    connect(_submit,SIGNAL(destroyed()),this,SLOT(mySubmitDestroyed()));
}

void Show::enterEvent(QEvent *)
{
    _exit->setVisible(true);
    if(_submit)
        _submit->setVisible(true);
}

void Show::mySubmitDestroyed()
{
    _submit=0;
}

void Show::leaveEvent(QEvent *)
{
    _exit->setVisible(false);
    if(_submit)
        _submit->setVisible(false);
}
