#ifndef EDM_H
#define EDM_H
#include "item.h"

class EDM : public Item
{
    Q_OBJECT

private:
    int IdEquipe;
public:
    EDM();
    void getEDM(QString i);
    void add();

    void setIdEquipe(int i);

    int getIdEquipe();

private slots:
    void parse(QNetworkReply* rep);


signals:
    void doneEDM();
};

#endif // EDM_H
