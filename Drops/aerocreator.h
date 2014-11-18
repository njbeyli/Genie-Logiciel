#ifndef AEROCREATOR_H
#define AEROCREATOR_H

#include "showcreators.h"

class AeroCreator : public ShowCreators
{
public:
    AeroCreator();
    Show *createShow(QString s, bool type);
};

#endif // AEROCREATOR_H
