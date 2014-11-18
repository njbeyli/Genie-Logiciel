#include "eqmcreator.h"
#include "Shows/eqdmshow.h"

EqmCreator::EqmCreator()
{
}

Show * EqmCreator::createShow(QString s, bool type)
{
    return (new EqDMShow(s,type));
}
