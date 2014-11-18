#ifndef COMPAGNIE_H
#define COMPAGNIE_H
#include "item.h"

class Compagnie : public Item
{
    Q_OBJECT

private:
    int IdComp;
    QString NomComp;
    QString Origine;
public:
    Compagnie();
    void getCompagnie(QString i);
    void add();

    void setIdComp(int i);
    void setNomComp(QString i);
    void setOrigine(QString i);

    int getIdComp();
    QString getNomComp();
    QString getOrigine();

private slots:
    void parse(QNetworkReply* rep);


signals:
    void doneCompagnie();

};

#endif // COMPAGNIE_H
