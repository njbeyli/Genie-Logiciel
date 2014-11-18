#ifndef MAINTENANCE_H
#define MAINTENANCE_H
#include "gerance.h"
#include "commonparser.h"

class Maintenance : public Gerance
{
        Q_OBJECT

public:
    QList<Item*> OpDep;
    QList<Item*> OpAr;
    QList<Vol*> Vo;
    QList<Operations*> OpEf;
    QList<Item*> EqM;
    QList<QString> InfoProg;
    QList <QString>InfoAero;

    CommonParser *Co;
    Vol *V;
    EDM *E;
public:
    Maintenance();
    void getOpDep();
    void getOpAr();
    void getVol();
    void getEDM();
    void selectOp(QString i);
    void selectVol(QString i);
    void selectEDM(QString i);
    void addRapport();
    void addRemGrav(QString IdOp, QString Rem, QString Gra);
    void tester();

public slots:
    void addContient();
    void getOpDepReply(QNetworkReply* rep);
    void getOpArReply(QNetworkReply* rep);
    void getVolReply(QNetworkReply* rep);
    void getEDMReply(QNetworkReply* rep);
    void onFinish(QNetworkReply* rep);

signals:
    void doneVol();
    void doneOpDep();
    void doneOpArr();
    void doneEDM();
};

#endif // MAINTENANCE_H
