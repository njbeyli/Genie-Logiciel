#ifndef AVION_H
#define AVION_H
#include "item.h"

class Avion : public Item
{
    Q_OBJECT

private:
    int IdAvion;
    int IdModele;
    int IdComp;
    QString IdAvCom;
    int Gare;
public:
    Avion();
    void getAvion(QString i);
    void add();
    void update();

    int getIdAvion();
    int getIdModele();
    int getIdComp();
    QString getIdAvCom();
    int getGare();

    void setIdAvion(int i);
    void setIdModele(int i);
    void setIdComp(int i);
    void setGare(int i);
    void setIdAvCom(QString i);
    
private slots:
    void parse(QNetworkReply *rep);    

signals:
    void doneAvi();
};

#endif // AVION_H
