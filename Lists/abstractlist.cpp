#include "abstractlist.h"

AbstractList::AbstractList(QWidget *parent) :
    QWidget(parent)
{
//        setAcceptDrops(true);
}

void AbstractList::setModel(QList<int> ids)
{}

//void AbstractList::dragEnterEvent(QDragEnterEvent *)
//{
//    emit toli3menneh(this);
//}
