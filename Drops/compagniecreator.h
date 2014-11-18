#ifndef COMPAGNIECREATOR_H
#define COMPAGNIECREATOR_H

#include "showcreators.h"

class CompagnieCreator : public ShowCreators
{
public:
    CompagnieCreator();
    Show *createShow(QString s, bool type);
};

#endif // COMPAGNIECREATOR_H
