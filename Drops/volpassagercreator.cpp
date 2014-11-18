#include "volpassagercreator.h"

VolPassagerCreator::VolPassagerCreator()
{
}

Show* VolPassagerCreator::createShow(QString s,bool type)
{
    return (new GuichetShow(s));
}
