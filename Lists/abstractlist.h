#ifndef ABSTRACTLIST_H
#define ABSTRACTLIST_H

#include <QWidget>
#include "Shows/show.h"
#include <QAbstractItemModel>
#include <QSortFilterProxyModel>
#include <QListView>

class AbstractList : public QWidget
{
    Q_OBJECT

protected:

    QAbstractItemModel *_model;
    QSortFilterProxyModel *_zModel;
public:
    explicit AbstractList(QWidget *parent = 0);
    QAbstractItemView *_zL;
private:


signals:

public slots:
    virtual void setModel(QAbstractItemModel *model)=0;
    virtual void setModel(QList<QString> stringList)=0;
    virtual void setModel(QList<int> ids);
};

#endif // ABSTRACTLIST_H
