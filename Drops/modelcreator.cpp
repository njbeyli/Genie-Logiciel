#include "modelcreator.h"
#include "Shows/modeleshow.h"

ModelCreator::ModelCreator()
{
}
Show * ModelCreator::createShow(QString s, bool type)
{
    return new ModeleShow(s,type);
}
