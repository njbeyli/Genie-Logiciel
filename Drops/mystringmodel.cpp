#include "mystringmodel.h"
#include <QMimeData>
#include <QDebug>

MyStringModel::MyStringModel(QObject *parent,bool valid) :
    QStringListModel(parent)
{
    //connect(this,SIGNAL())
    t=valid;
}


Qt::ItemFlags MyStringModel::flags(const QModelIndex &index) const
{
    if(index.isValid()&&(!t))
        return (QStringListModel::flags(index))^(Qt::ItemIsDropEnabled);
    return (QStringListModel::flags(index));
}

bool MyStringModel::dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent)
{
    QStringListModel::dropMimeData(data,action,row,column,parent);
    QMap<int ,QVariant> ddaa;
    int i,j;
    QByteArray md=data->data("application/x-qabstractitemmodeldatalist");
    QDataStream ds(&md,QIODevice::ReadOnly);
    ds>>i>>j>>ddaa;
    emit fetFiyi(ddaa[0].toString());
}
