#include "showcollection.h"
#include <QGridLayout>

#include <QDebug>

ShowCollection::ShowCollection(Gerance *g, QWidget *parent) :
    QWidget(parent)
{
    setObjectName("shows");

    _g=g;
}

Gerance * ShowCollection::g() const
{
    return _g;
}
