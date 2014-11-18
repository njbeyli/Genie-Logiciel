#include "aerocreator.h"

#include "Shows/employeshow.h"

AeroCreator::AeroCreator()
{
}

Show *AeroCreator::createShow(QString s, bool type)
{
    return new EmployeShow(s,type);
}
