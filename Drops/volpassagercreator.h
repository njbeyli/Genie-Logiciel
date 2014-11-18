#ifndef VOLPASSAGERCREATOR_H
#define VOLPASSAGERCREATOR_H

#include "Shows/guichetshow.h"
#include "showcreators.h"

class VolPassagerCreator : public ShowCreators
{
public:
    VolPassagerCreator();
    Show*createShow(QString s,bool type=false);
};

#endif // VOLPASSAGERCREATOR_H
