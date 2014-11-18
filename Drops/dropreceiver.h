#ifndef DROPRECEIVER_H
#define DROPRECEIVER_H

#include <QLabel>
#include "Shows/showcollection.h"

class DropReceiver : public QLabel
{
    Q_OBJECT
    QPixmap _o;
    QPixmap _i;


    bool _type;
public:
    explicit DropReceiver(ShowCollection * receiver, bool type=false,QWidget *parent = 0);

protected:
    ShowCollection *_recever;
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void dragEnterEvent(QDragEnterEvent *);
    void dragLeaveEvent(QDragLeaveEvent *);
    void dragMoveEvent(QDragMoveEvent *);
    void dropEvent(QDropEvent *);
signals:
    void fetFiyyiEsm(int );
public slots:

};

#endif // DROPRECEIVER_H
