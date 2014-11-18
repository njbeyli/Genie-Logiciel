#include "emplcreator.h"
#include "Shows/empdemaintshow.h"

EmplCreator::EmplCreator()
{
}

Show *EmplCreator::createShow(QString s, bool type)
{
    return new EmpDeMaintShow;
}
