#ifndef EQMCREATOR_H
#define EQMCREATOR_H

#include "showcreators.h"

class EqmCreator : public ShowCreators
{
public:
    EqmCreator();
    Show * createShow(QString s, bool type=false);
};

#endif // EQMCREATOR_H
