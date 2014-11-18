#ifndef PROGRAMME_H
#define PROGRAMME_H
#include "item.h"

class Programme :public Item
{
    Q_OBJECT
public:
    Programme();
    void getProg(QString Prog);
    void add();
    void update();

    int getIdProg();
    int getIdAvion();
    int getIdEquipe();
    int getNumAero();
    int getIdEq();
    QString getCode();
    QString getDirection();
    QDate getDateDebut();
    QDate getDateFin();
    float getDuree();

    void setIdProg(int i);
    void setIdAvion(int i);
    void setIdEquipe(int i);
    void setIdEq(int i);
    void setNumAero(int i);
    void setCode(QString i);
    void setDirection(QString i);
    void setDateDebut(QDate i);
    void setDateFin(QDate i);
    void setDuree(float i);

private:
    int IdProg;
    int IdAvion;
    int IdEquipe;
    int NumAero;
    int IdEq;
    QString Code;
    QString Direction;
    QDate DateDebut;
    QDate DateFin;
    float Duree;

private slots:
    void parse(QNetworkReply *rep);

signals:
    void doneProg();
};

#endif // PROGRAMME_H
