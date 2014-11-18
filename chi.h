#ifndef CHI_H
#define CHI_H
#include "gerance.h"
#include "commonparser.h"

class CHI : public Gerance
{
    Q_OBJECT


public:
    QList<Vol*> Vols;
    QList<QString> InfoProg;
    QList<QString> InfoAero;

    QList<QList<Item*> > Personnels;
    QList<QList<Item*> > Rapportss;
    QList<QList<Item*> > Operationss;

    QList<Vol*> V;
    QList<Avion*> Avions;
    QList<Aeroport*> Aeroports;
    QList<EDM*> Equipes;
    QList<Programme*> Programmes;
    QList<Modele*> Modeles;
    QList<Compagnie*>Compagnies;
private:

    CommonParser *Co;

    Vol *Vo;
    Avion *Av;
    Aeroport *Aero;
    EDM *Equipe;
    Programme *Prog;
    Modele *Mod;
    Compagnie *Comp;

private:
    int counter;
    int rapref;
    int rapcounter;


public slots:
    void getVolSel(QString i);
    void getProgInfo();
    void getAvInfo();
    void getAeroInfo();
    void getModeleInfo();
    void getCompInfo();

public:
    CHI();
    void getAllVols();
    void closeVol(QString i);
    void RapportsSelected(QString i, QString volref);
    int getCounter()const;
    int getRapref()const;
    int getRapCounter()const;
    ~CHI();

private slots:
    void getAll(QNetworkReply* rep);
    void getRapport(QNetworkReply* rep);
    void getPersonnel(QNetworkReply* rep);
    void getOps(QNetworkReply* rep);

signals:
    void doneVol();
    void doneLoad();
    void doneLoadProg();
    void doneOperation();
};

#endif // CHI_H

