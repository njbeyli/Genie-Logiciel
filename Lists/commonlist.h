#ifndef COMMONLIST_H
#define COMMONLIST_H

#include <QWidget>
#include <QPushButton>
#include "abstractlist.h"

class CommonList : public QWidget
{
    Q_OBJECT
protected:
    QPushButton *_header;
    AbstractList *_leReste;
    QString st[2];
public:
    explicit CommonList(QString s, AbstractList *l,QWidget *parent = 0);
    AbstractList* leReste()const;
signals:
    //

private slots:
    void miniMax();
    //

public slots:

};

#endif // COMMONLIST_H
