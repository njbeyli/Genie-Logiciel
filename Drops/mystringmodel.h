#ifndef MYSTRINGMODEL_H
#define MYSTRINGMODEL_H

#include <QStringListModel>

class MyStringModel : public QStringListModel
{
    Q_OBJECT
    bool t;
public:
    explicit MyStringModel(QObject *parent = 0, bool valid=false);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);
signals:
    void fetFiyi(QString);
public slots:

};

#endif // MYSTRINGMODEL_H
