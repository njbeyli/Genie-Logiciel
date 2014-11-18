#ifndef PROGRAMELIST_H
#define PROGRAMELIST_H

#include "abstractlist.h"
#include "Filters/abstractfilter.h"
#include "Lists/mylistwidget.h"

class ProgrameList : public AbstractList
{
    Q_OBJECT
    AbstractFilter *_tf;
    MyListWidget *_ml;
public:
    explicit ProgrameList(QWidget *parent = 0);

signals:

public slots:
    void setModel(QList<QString> s);
    void setModel(QAbstractItemModel *im);

};

#endif // PROGRAMELIST_H
