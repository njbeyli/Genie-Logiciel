#ifndef COMPAGNIESHOW_H
#define COMPAGNIESHOW_H


#include "show.h"


namespace Ui {
class CompagnieShow;
}

class CompagnieShow : public Show
{
    Q_OBJECT

public:
    explicit CompagnieShow(QString s,bool t,QWidget *parent = 0);
    ~CompagnieShow();
    void setg(Gerance *g);

protected:
    void setReadOnly(bool t);

protected slots:
    void addCompagnie();
    void leffha();

private:
    Ui::CompagnieShow *ui;
};

#endif // COMPAGNIESHOW_H
