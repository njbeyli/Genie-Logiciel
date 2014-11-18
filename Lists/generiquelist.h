#ifndef GENERIQUELIST_H
#define GENERIQUELIST_H

#include "abstractlist.h"
#include "Filters/textfilter.h"
#include "mylistwidget.h"
#include "Drops/showcreators.h"

class GeneriqueList : public AbstractList
{
    Q_OBJECT
    MyListWidget *_ml;
    TextFilter *_tf;
public:
    explicit GeneriqueList(QWidget *parent = 0);
    void set_sh(ShowCreators *s);
signals:

public slots:
    void setModel(QList<QString> s);
    void setModel(QAbstractItemModel *im);
};

#endif // GENERIQUELIST_H
