#ifndef SHOWCREATORS_H
#define SHOWCREATORS_H

#include "Shows/show.h"

class ShowCreators
{
    //int i;
public:
    explicit ShowCreators();
    virtual Show *createShow(QString s,bool type=false)=0;
    virtual Show *createShow(QString s, bool type,int i);
    //virtual QString debuging();
};

#endif // SHOWCREATORS_H
