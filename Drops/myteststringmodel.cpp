#include "myteststringmodel.h"
#include <QMimeData>
#include <QDebug>


MyTestStringModel::MyTestStringModel(QObject *parent) :
    QStringListModel(parent)
{
}

QStringList MyTestStringModel::mimeTypes()const
{

    QStringList sl;
    sl.append("MyText");
    sl.append("MyId");
    return sl;
}

void MyTestStringModel::set_ids(QList<int> i)
{
    _ids=i;
}

QMimeData *MyTestStringModel::mimeData(QModelIndexList &indexes) const
{
    QMimeData *mydata=new QMimeData;
    QByteArray textData;
 //   QByteArray idData;
    QDataStream stream(&textData, QIODevice::WriteOnly);
  //  QDataStream streamid(&idData, QIODevice::WriteOnly);

    foreach (const QModelIndex &index, indexes) {
        if (index.isValid()) {
            QString text = index.data().toString();
            stream << text;
        }
    }
//    foreach (const QModelIndex &index, indexes) {
//        if (index.isValid()) {
//            streamid<<_ids[index.row()];
//        }
//    }

    mydata->setData("MyText",textData);
   // mydata->setData("MyId",idData);

    return mydata;
}
