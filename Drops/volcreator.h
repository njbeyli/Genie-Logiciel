#ifndef VOLCREATOR_H
#define VOLCREATOR_H

#include "showcreators.h"

class VolCreator : public ShowCreators
{
public:
    VolCreator();

    Show *createShow(QString s,bool type=false);
};

#endif // VOLCREATOR_H
