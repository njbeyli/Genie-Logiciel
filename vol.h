#ifndef VOL_H
#define VOL_H
#include "item.h"

class Vol : public Item
{
    Q_OBJECT

private slots:

        void parse(QNetworkReply *rep);


public:

    Vol();
    Vol(Vol &v);
    void getVol(QString Vol);
    void getVolProg(QString Prog);
    void add();
    void update();

    void setIdVol(int i);
    void setIdEquipe(int i);
    void setIdEq(int i);
    void setIdProg(int i);
    void setIdAvion(int i);
    void setDatPreVol(QDate i);
    void setDatReVol(QDate i);
    void setHeurPreVol(QTime i);
    void setHeurReVol(QTime i);
    void setEtatVol(QString i);

    int getIdVol();
    int getIdEquipe();
    int getIdEq();
    int getIdProg();
    int getIdAvion();
    QDate getDatPreVol();
    QDate getDatReVol();
    QTime getHeurPreVol();
    QTime getHeurReVol();
    QString getEtatVol();
    Vol* operator =(Vol &v);

private :
    int IdVol;
    int IdEquipe;
    int IdEq;
    int IdProg;
    int IdAvion;
    QDate DatPreVol;
    QTime HeurPreVol;
    QDate DatReVol;
    QTime HeurReVol;
    QString EtatVol;


};

#endif // VOL_H
