#ifndef UPDATE_H
#define UPDATE_H
#include "gerance.h"
#include "commonparser.h"

class Update : public Gerance
{
    Q_OBJECT

public:
    QList <Item*> Av;
    QList <Item*> PersM;
    QList <Item*> Op;
    QList <Item*> Prog;
    QList <Vol*> Vo;
    QList <Item*> E;
    QList <QString> InfoProg;
    QList <QString> InfoAero;

    Item * I;
    CommonParser *Co;
public:
    Update();
    Item* getI();

    void getAv();
    void getPersM();
    void getOp();
    void getProg();
    void getVo();
    void getEDM();

    void setIPDM(QString i);
    void setIAvion(QString i);
    void setIProgramme(QString i);
    void setIVol(QString i);
    void setIOperation(QString i);

    void updateAv(QString Gare);
    void updatePersM(QString Nom,QString Prenom);
    void updateOp(QString DescOp, QString DA);
    void updateProg(QString IdAvion,QString IdEquipe,QDate DateFin);
    void updateVo(QString idEquipe,QString IdAvion,QDate DatPreVol,QTime HeurPreVol);

    void dischargePersM();

public slots:
    void onFinish(QNetworkReply* rep);
    void getAvReply(QNetworkReply* rep);
    void getPersMReply(QNetworkReply* rep);
    void getOpReply(QNetworkReply* rep);
    void getProgReply(QNetworkReply* rep);
    void getVoReply(QNetworkReply* rep);
    void getEDMReply(QNetworkReply* rep);

signals:
    void doneVol();
    void doneAvion();
    void doneProg();
    void doneEDM();
    void donePersM();
    void doneOp();
};

#endif // UPDATE_H
