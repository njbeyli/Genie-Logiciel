#ifndef TOUSVOL_H
#define TOUSVOL_H


#include "abstractlist.h"
#include "Filters/abstractfilter.h"
#include "mytablewidget.h"

class TousVol : public AbstractList
{
    Q_OBJECT

    QList<AbstractFilter *> _l;
protected:
    MyTableWidget *_ml;
public:
    explicit TousVol(QWidget *parent = 0);

signals:

public slots:
    void setModel(QList<QString> s);
    void setModel(QAbstractItemModel *im);

};

#endif // TOUSVOL_H
