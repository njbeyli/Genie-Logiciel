#ifndef MYTESTSTRINGMODEL_H
#define MYTESTSTRINGMODEL_H

#include <QStringListModel>
#include "Drops/showcreators.h"

class MyTestStringModel : public QStringListModel
{
    Q_OBJECT
    QList<int> _ids;
public:
    explicit MyTestStringModel(QObject *parent = 0);
    void set_ids(QList<int> i);

protected:
    QStringList mimeTypes()const;
    QMimeData *mimeData(QModelIndexList &indexes) const;

signals:

public slots:

};

#endif // MYTESTSTRINGMODEL_H
