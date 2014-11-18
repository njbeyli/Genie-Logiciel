#ifndef VOLDAUJOURD_H
#define VOLDAUJOURD_H

#include <QWidget>
#include "abstractlist.h"
#include "Filters/abstractfilter.h"
#include "mylistwidget.h"

class VolDaujourd : public AbstractList
{
    Q_OBJECT
    QList<AbstractFilter *> _l;
    MyListWidget *_ml;

public:
    explicit VolDaujourd(QWidget *parent = 0);
private:

public slots:
    void setModel(QList<QString> s);
    void setModel(QAbstractItemModel *im);
    void setModel(QList<int> ids);
};

#endif // VOLDAUJOURD_H
