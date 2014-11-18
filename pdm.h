#ifndef PDM_H
#define PDM_H
#include "item.h"

class PDM : public Item
{
    Q_OBJECT

private:
    int IdPDM;
    QString NomPDM;
    QString PrenomPDM;
public:
    PDM();
    void getPDM(QString i);
    void add();
    void update();
    void remove();

    int getIdPDM();
    QString getNomPDM();
    QString getPrenomPDM();

    void setIdPDM(int i);
    void setNomPDM(QString i);
    void setPrenomPDM(QString i);

public slots:
    void parse(QNetworkReply *rep);

};

#endif // PDM_H
