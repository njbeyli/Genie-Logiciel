#ifndef EQUIPA_H
#define EQUIPA_H
#include "item.h"

class EquipA : public Item
{
    Q_OBJECT

private:
    int IdEq;
public:
    EquipA();
    void getEquipA(QString i);
    void add();

    void setIdEq(int i);

    int getIdEq();

private slots:
    void parse(QNetworkReply* rep);


signals:
    void doneEquipA();
};
#endif // EQUIPA_H
