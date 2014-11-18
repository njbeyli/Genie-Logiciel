#ifndef DIRECTION_H
#define DIRECTION_H
#include "gerance.h"
#include "commonparser.h"

class Direction : public Gerance
{
    Q_OBJECT

private:

    CommonParser * Co;
    Semaine *S;
   // Programme * P;
public:
    Item *I;
    QList<Item*> Mod;
    QList<Item*> Comp;

    QList<Item*> EqM;
    QList<Item*> EqA;
    QList<QList<Item*> > PersM;
    QList<Item*> ToutPersM;
    QList<QList<Item*> > PersA;
    QList<Item*> Av;
    QList<Item*> Aero;

    QList<Semaine*> Se;



public:
    Direction();
    void addPersonnel(QString nom, QString Prenom);
    void addEDM();
    void addAero(QString NomAero, QString Ville);
    void addCompagnie(QString NomComp, QString Origine);
    void addModele(QString Res, QString Dist, QString VitCrois, QString NomM);
    void addAvion(QString IdMod, QString IdComp, QString IdAvCom, QString Gare);
    void addProgramme(QString IdAv,QString IdEquipe,QString NumAero,QString IdEq,QString Code,QString Direction,QDate DateDebut,QDate DateFin,QString Duree);
    void addJour(QString J,QTime H, QString P);
    void getCompagnie();
    void getModele();
    void getEqM();
    void getEqA();
    void getPDM(QString idEq);
    void getPDL(QString idEq);
    void getAv();
    void getAero();
    void getAllPDM();
    void tester();
    
    void connectPDMEDM(QString IdEquipe, QString IdPDM);
    void setIAero();
    void setIPDM();
    void setIEDM();
    void setIModele();
    void setIAvion();
    void setICompagnie();
    void setIProgramme();


    Item* getI();
public slots:
    void onFinish(QNetworkReply* rep);
    void getCompagnieReply(QNetworkReply* rep);
    void getModeleReply(QNetworkReply* rep);
    //void getCompagnieReply(QNetworkReply* rep);
    //void getModeleReply(QNetworkReply* rep);
    void getEqMReply(QNetworkReply* rep);
    void getEqAReply(QNetworkReply* rep);
    void getPDMReply(QNetworkReply* rep);
    void getPDLReply(QNetworkReply* rep);
    void getAvReply(QNetworkReply* rep);
    void getAeroReply(QNetworkReply* rep);
    void getAllPDMReply(QNetworkReply* rep);
    void addSemaine();

signals:
    void doneAero();
    void doneAvion();
    void doneModele();
    void doneCompagnie();
    void doneEqM();
    void doneEqA();
    void donePDM();
    void doneZPDM();
    void doneAddingEDm();
    void doneAddingPDm();
    void doneAddingModel();
    void doneAddingAvion();
    void doneAddingComp();
    void doneAddingAero();
};

#endif // DIRECTION_H
