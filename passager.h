#ifndef PASSAGER_H
#define PASSAGER_H
#include "item.h"

class Passager : public Item
{
    Q_OBJECT

private slots:

        void parse(QNetworkReply *rep);

private:

    int IdPass;
    int IdVol;
    bool CheckIn;
    bool CheckOut;
    bool OnBoard;
    QString NomPass;
    QString PrenomPass;
    QString NumPass;

public:
    Passager();
    void add();

    int getIdPass();
    int getIdVol();
    bool getCheckIn();
    bool getCheckOut();
    bool getOnBoard();
    QString getNomPass();
    QString getPrenomPass();
    QString getNumPass();

    void setIdPass(int i);
    void setIdVol(int i);
    void setCheckOut(bool i);
    void setCheckIn(bool i);
    void setOnBoard(bool i);
    void setNomPass(QString i);
    void setPrenomPass(QString i);
    void setNumPass(QString i);
};

#endif // PASSAGER_H
