#include "dummyshow.h"

DummyShow::DummyShow(QWidget *parent) :
    Show(parent)
{
    setFixedSize(500,300);
    //QSize s(exit()->size());
    //setExitPos(QPoint(width()-2*s.width(),s.height()));
}


void DummyShow::setReadOnly(bool t)
{

}
