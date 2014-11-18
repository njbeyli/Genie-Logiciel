#include "rapportdropreceiver.h"
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QMimeData>
#include "Lists/mylistwidget.h"

RapportDropReceiver::RapportDropReceiver(QWidget *parent) :
    QLabel(parent)
{
    setObjectName("Drager");
    setText("Drag Operation Here");
    setFixedHeight(40);
    setAcceptDrops(true);
    setAlignment(Qt::AlignCenter);

}

void RapportDropReceiver::dragEnterEvent(QDragEnterEvent *e)
{
    if(e->mimeData()->formats()[0]=="application/x-qabstractitemmodeldatalist")
    {
        e->acceptProposedAction();
    }
}
void RapportDropReceiver::dragMoveEvent(QDragMoveEvent *e)
{
    e->accept();
}

void RapportDropReceiver::dropEvent(QDropEvent *e){
    if(e->mimeData()->formats()[0]=="application/x-qabstractitemmodeldatalist")
    {
        QMap<int ,QVariant> ddaa;
        int i,j;
        QByteArray md=e->mimeData()->data("application/x-qabstractitemmodeldatalist");
        QDataStream ds(&md,QIODevice::ReadOnly);
        ds>>i>>j>>ddaa;
        emit alMawloud(ddaa[0].toString());
   // static_cast<const MyTableWidget *>(e->source())->sendSignalToParent(i);
    }
}

void RapportDropReceiver::dragLeaveEvent(QDragLeaveEvent *e)
{

}
