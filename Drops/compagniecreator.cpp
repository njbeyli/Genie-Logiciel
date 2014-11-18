#include "compagniecreator.h"
#include "Shows/compagnieshow.h"

CompagnieCreator::CompagnieCreator()
{
}
Show *CompagnieCreator::createShow(QString s, bool type)
{
    return new CompagnieShow(s,type);
}
