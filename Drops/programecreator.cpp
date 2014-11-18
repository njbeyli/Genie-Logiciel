#include "programecreator.h"
#include "Shows/programeshow.h"
#include <QDebug>

ProgrameCreator::ProgrameCreator()
{
}

Show * ProgrameCreator::createShow(QString s, bool type)
{
    qDebug()<<"hi";
    return (new ProgrameShow(s,type));
}
