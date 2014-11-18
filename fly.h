#ifndef FLY_H
#define FLY_H
#include"gerance.h"
#include"commonparser.h"

class Fly : public Gerance
{
    Q_OBJECT

public:
    QList<Vol*> V;
    QList<QString> InfoProg;
    QList<QString> InfoAero;
    Vol * Vc;

public:
    Fly();
    void getVols();
    void selectVol(QString i);
    void takeOff();

signals:
    void doneVol();

public slots:
    void getVolsReply(QNetworkReply* rep);
    void OnFinish(QNetworkReply* rep);
    void checkOut();
};

#endif // FLY_H
