#ifndef EMPLCREATOR_H
#define EMPLCREATOR_H

#include "showcreators.h"

class EmplCreator : public ShowCreators
{
public:
    EmplCreator();
    Show * createShow(QString s, bool type);
};

#endif // EMPLCREATOR_H
