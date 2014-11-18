#ifndef PROGRAMECREATOR_H
#define PROGRAMECREATOR_H

#include "showcreators.h"

class ProgrameCreator : public ShowCreators
{
public:
    ProgrameCreator();
    Show *createShow(QString s, bool type=false);

};

#endif // PROGRAMECREATOR_H
