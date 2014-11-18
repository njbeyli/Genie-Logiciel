#ifndef RAPPORTCREATOR_H
#define RAPPORTCREATOR_H

#include "showcreators.h"

class RapportCreator : public ShowCreators
{
public:
    RapportCreator();
    Show *createShow(QString s,bool t=false);
};

#endif // RAPPORTCREATOR_H
