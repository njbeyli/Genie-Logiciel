#include "dropreceivedir.h"

#include "Lists/mylistwidget.h"
#include <QDropEvent>
#include <QMimeData>


DropReceiveDir::DropReceiveDir(ShowCollection *sc,QWidget *parent) :
    DropReceiver(sc,true,parent)
{
}

void DropReceiveDir::dropEvent(QDropEvent *e)
{
    QMap<int ,QVariant> ddaa;
    int i,j;
    QByteArray md=e->mimeData()->data("application/x-qabstractitemmodeldatalist");
    QDataStream ds(&md,QIODevice::ReadOnly);
    ds>>i>>j>>ddaa;
    _recever->addShow(static_cast<const MyListWidget *>(e->source())->sh()->createShow(ddaa[0].toString(),true,i));
    //emit fetFiyyiEsm(i);
}
