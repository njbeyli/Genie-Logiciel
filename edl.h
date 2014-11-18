#ifndef EDL_H
#define EDL_H
#include "item.h"

class EDL : public Item
{
    Q_OBJECT

private:
    int IdEDL;
    int IdComp;
    QString NomEDL;
    QString PrenomEDL;
    QString Poste;
public:
    EDL();
    void getEDL(QString i);
    void add();

    int getIdEDL();
    QString getNomEDL();
    QString getPrenomEDL();
    int getIdComp();
    QString getPoste();

    void setIdEDL(int i);
    void setNomEDL(QString i);
    void setPrenomEDL(QString i);
    void setIdComp(int i);
    void setPoste(QString i);

public slots:
    void parse(QNetworkReply *rep);

};

#endif // EDL_H
