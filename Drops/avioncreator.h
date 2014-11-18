#ifndef AVIONCREATOR_H
#define AVIONCREATOR_H

#include "showcreators.h"

class AvionCreator : public ShowCreators
{
public:
    AvionCreator();
    Show * createShow(QString s, bool type);
};

#endif // AVIONCREATOR_H
