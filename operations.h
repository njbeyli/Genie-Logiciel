#ifndef OPERATIONS_H
#define OPERATIONS_H
#include "item.h"

class Operations : public Item
{
    Q_OBJECT

private:
    int IdOp;
    QString DescOp;
    QString DA;

    int Gravite;
    QString Remarque;
public:
    Operations();
    Operations(Operations &Op);
    Operations* operator =(Operations &Op);

    int getIdOp();
    QString getDescOp();
    QString getDA();
    void add();
    void update();

    QString getRemarque();
    int getGravite();

    void setIdOp(int i);
    void setDescOp(QString i);
    void setDA(QString i);

    void setGravite(int i);
    void setRemarque(QString i);

private slots:
    void parse(QNetworkReply* rep);


signals:
    void doneOperations();
};

#endif // OPERATIONS_H
