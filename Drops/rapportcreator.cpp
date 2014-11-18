#include "rapportcreator.h"
#include "Shows/rapportshow.h"

RapportCreator::RapportCreator()
{
}

Show* RapportCreator::createShow(QString s, bool t)
{
    return (new RapportShow(s,t));
}
