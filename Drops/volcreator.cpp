#include "volcreator.h"

#include "Shows/volshow.h"
#include "Shows/programeshow.h"

VolCreator::VolCreator()
{
}


Show* VolCreator::createShow(QString s,bool type)
{
    return (new VolShow(s,type));
}
