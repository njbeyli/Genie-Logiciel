#include "multicreator.h"

MultiCreator::MultiCreator()
{
}

Show *MultiCreator::createShow(QString s, bool type)
{}

Show * MultiCreator::createShow(QString s, bool type, int i)
{
    if(i<l.length()&&(l[i]))
        return l[i]->createShow(s,type);
}
