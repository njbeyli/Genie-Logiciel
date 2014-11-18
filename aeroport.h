#ifndef AEROPORT_H
#define AEROPORT_H
#include "item.h"

class Aeroport : public Item
{
    Q_OBJECT

private:

    int NumAero;
    QString NomAero;
    QString Ville;
public:
    Aeroport();
    void getAero(QString Aero);

    int getNumAero();
    QString getNomAero();
    QString getVille();

    void setNumAero(int i);
    void setNomAero(QString i);
    void setVille(QString i);
    void add();
private slots:
    void parse(QNetworkReply *rep);
signals:
    void doneAero();
};

#endif // AEROPORT_H
