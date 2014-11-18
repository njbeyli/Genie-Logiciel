#ifndef Counter_H
#define Counter_H
#include "gerance.h"


class Counter : public Gerance
{
    Q_OBJECT

public slots:
   void getPass();

public:

    QList<Passager*> Passagers;
    Vol *V;
    QList<QString> Prog;
    QList<Vol*> Vols;

public:
    Counter();
    void getVolsActifs();
    void setVolSel(QString i);
    void check(QString i);
    ~Counter();

private slots:

    void onFinish(QNetworkReply* rep);
    void getActifs(QNetworkReply* rep);

signals:
    void launch();
    void done();
    void donePassager();
};

#endif // Counter_H
