#include "avioncreator.h"
#include "Shows/avionshow.h"

AvionCreator::AvionCreator()
{
}

Show * AvionCreator::createShow(QString s,bool t)
{
    return new AvionShow(s,t);
}
