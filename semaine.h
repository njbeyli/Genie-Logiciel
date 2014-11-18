#ifndef SEMAINE_H
#define SEMAINE_H
#include "item.h"

class Semaine : public Item
{
    Q_OBJECT

private:
    int IdProg;
    int Jour;
    QTime Heure;
    int Periodicite;
    int Compte;
public:
    Semaine();
    void add();

    int getIdProg();
    int getJour();
    QTime getHeure();
    int getPeriodicite();
    int getCompte();

    void setIdProg(int i);
    void setJour(int i);
    void setHeure(QTime i);
    void setPeriodicite(int i);
    void setCompte(int i);

private slots:
    void parse(QNetworkReply* rep);
};

#endif // SEMAINE_H
