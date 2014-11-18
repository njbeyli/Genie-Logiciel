#ifndef RAPPORTS_H
#define RAPPORTS_H
#include "item.h"

class Rapports : public Item
{
    Q_OBJECT

private:
    int IdRapport;
    int IdEquipe;
    int IdAvion;
    int IdVol;
    QDateTime DateRap;
public:
    Rapports();
    void getRapport(QString i);
    void add();

    int getIdRapport();
    int getIdEquipe();
    int getIdAvion();
    int getIdVol();
    QDateTime getDateRap();

    void setIdRapport(int i);
    void setIdEquipe(int i);
    void setIdAvion(int i);
    void setIdVol(int i);
    void setDateRap(QDateTime i);

private slots:
    void parse(QNetworkReply* rep);

};

#endif // RAPPORTS_H
