#ifndef MODELE_H
#define MODELE_H
#include "item.h"

class Modele : public Item
{
    Q_OBJECT

private:
    int IdModele;
    float Reservoire;
    float DistMax;
    float VitCrois;
    QString NomModele;
public:
    Modele();
    void getModele(QString i);
    void add();

    int getIdModele();
    float getReservoire();
    float getDistMax();
    float getVitCrois();
    QString getNomModele();

    void setIdModele(int i);
    void setReservoire(float i);
    void setDistMax(float i);
    void setVitCrois(float i);
    void setNomModele(QString i);

private slots:
    void parse(QNetworkReply *rep);


signals:
    void doneModele();

};

#endif // MODELE_H
