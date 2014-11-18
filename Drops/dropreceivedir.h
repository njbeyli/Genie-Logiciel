#ifndef DROPRECEIVEDIR_H
#define DROPRECEIVEDIR_H

#include "dropreceiver.h"

class DropReceiveDir : public DropReceiver
{
    Q_OBJECT
public:
    explicit DropReceiveDir(ShowCollection * s,QWidget *parent = 0);

signals:
protected:
    void dropEvent(QDropEvent *);

public slots:

};

#endif // DROPRECEIVEDIR_H
