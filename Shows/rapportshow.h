#ifndef RAPPORTSHOW_H
#define RAPPORTSHOW_H

#include "show.h"
#include "operationshow.h"
#include "Lists/mylistwidget.h"

namespace Ui {
class RapportShow;
}

class RapportShow : public Show
{
    Q_OBJECT
    QList<OperationShow *> _l;
    MyListWidget * ml;
    bool t;
public:
    explicit RapportShow(QString s, bool type, QWidget *parent = 0);
    ~RapportShow();
    void setg(Gerance *g);
    void addOperation(OperationShow *op);

public slots:
    void setList();
    void addOp(QString s);
    void addLeRapport();
protected:
    void setReadOnly(bool t);

private:
    Ui::RapportShow *ui;
};

#endif // RAPPORTSHOW_H
