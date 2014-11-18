#ifndef OBCounter_H
#define OBCounter_H
#include "gerance.h"


class OBCounter : public Gerance
{
    Q_OBJECT

public slots:
   void getPass();

public:

    QList<Passager*> Passagers;
    Vol *V;
    QList<Vol*> Vols;
    QList<QString> Prog;

public:
    OBCounter();
    void getVolsActifs();
    void setVolSel(QString i);
    void check(QString i);
    ~OBCounter();


private slots:

    void onFinish(QNetworkReply* rep);
    void getActifs(QNetworkReply* rep);

signals:
    void launch();
    void done();
    void donePassager();
};

#endif // OBCounter_H
