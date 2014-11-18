#ifndef MODELCREATOR_H
#define MODELCREATOR_H

#include "showcreators.h"

class ModelCreator : public ShowCreators
{
public:
    ModelCreator();
    Show *createShow(QString s, bool type);
};

#endif // MODELCREATOR_H
