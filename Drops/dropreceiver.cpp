#include "dropreceiver.h"
#include <QPainter>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QBitmap>
#include <QDebug>

#include "Lists/flight.h"
#include "Lists/mytablewidget.h"
#include "Lists/mylistwidget.h"

DropReceiver::DropReceiver(ShowCollection *receiver, bool type, QWidget *parent) :
    QLabel(parent),_type(type)
{
    QString text[2];
    text[0]="Drag Element From List Here\n To View";
    text[1]="Drag Element From List Here\n To Edit";
    setFixedSize(70,70);
    _o.load("/Users/nicolasjbeyli/build-Projet-Desktop_Qt_5_2_1_clang_64bit-Debug/Pics/drop.png");
    _o=_o.scaled(70,70,Qt::KeepAspectRatio);
    _i=_o;
    QPainter p(&_i);
    QBrush b(QColor(128,176,224,128)); // adjust color and alpha to taste
    p.setBrush(b);
    p.setClipRegion(QRegion(_i.mask()));
    p.drawRect(0,0,70,70);
   setPixmap(_o);
   setAcceptDrops(true);
   _recever=receiver;
   setObjectName(text[type]);
   setStyleSheet("background: transparent");
}

void DropReceiver::dragLeaveEvent(QDragLeaveEvent *)
{
   setPixmap(_o);
}

void DropReceiver::enterEvent(QEvent *)
{
    setPixmap(_i);
}

void DropReceiver::leaveEvent(QEvent *)
{
    setPixmap(_o);
}

void DropReceiver::dragEnterEvent(QDragEnterEvent *e)
{
    if(static_cast<const MyTableWidget *>(e->source())->sh()!=0)
    {
        if(e->mimeData()->formats()[0]=="application/x-qabstractitemmodeldatalist"||e->mimeData()->formats()[0]=="MyText")
        {
            e->acceptProposedAction();
            setPixmap(_i);
        }
    }
}

void DropReceiver::dragMoveEvent(QDragMoveEvent *e)
{
    e->accept();
}

void  DropReceiver::dropEvent(QDropEvent *e)
{
    if(e->mimeData()->formats()[0]=="application/x-qabstractitemmodeldatalist")
    {QMap<int ,QVariant> ddaa;
    int i,j;
    QByteArray md=e->mimeData()->data("application/x-qabstractitemmodeldatalist");
    QDataStream ds(&md,QIODevice::ReadOnly);
    ds>>i>>j>>ddaa;
    _recever->addShow(static_cast<const MyTableWidget *>(e->source())->sh()->createShow(ddaa[0].toString(),_type));
    //emit fetFiyyiEsm(i);
    static_cast<const MyListWidget *>(e->source())->sendSignalToParent(i);
   // static_cast<const MyTableWidget *>(e->source())->sendSignalToParent(i);
    }
    else if(e->mimeData()->formats()[0]=="MyText")
    {
        QByteArray md=e->mimeData()->data("MyText");
        QDataStream ds(&md,QIODevice::ReadOnly);
        QString s;
        ds>>s;
        qDebug()<<s;
    }
}
