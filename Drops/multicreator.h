#ifndef MULTICREATOR_H
#define MULTICREATOR_H

#include "showcreators.h"

class MultiCreator : public ShowCreators
{
public:
    MultiCreator();
    QList<ShowCreators *> l;
    Show * createShow(QString s, bool type);
    Show *createShow(QString s, bool type,int i);
};

#endif // MULTICREATOR_H
