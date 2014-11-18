#ifndef LISTCOLLECTION_H
#define LISTCOLLECTION_H

#include <QWidget>
#include "commonlist.h"
#include <QBoxLayout>

class ListCollection : public QWidget
{
    Q_OBJECT
    QList<CommonList *> _all;
    QBoxLayout *_bl;
public:
    explicit ListCollection(QWidget *parent = 0);
    void append(CommonList *);
    CommonList * operator[](int i);
    int length()const;
signals:
public slots:
};

#endif // LISTCOLLECTION_H
