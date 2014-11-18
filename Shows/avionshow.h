#ifndef AVIONSHOW_H
#define AVIONSHOW_H

#include <QWidget>
#include "show.h"
#include "Lists/mylistwidget.h"

namespace Ui {
class AvionShow;
}

class AvionShow : public Show
{
    Q_OBJECT

    MyListWidget *_idc,*_idm;

public:
    explicit AvionShow(QString s,bool type,QWidget *parent = 0);
    ~AvionShow();
    void setg(Gerance *g);
protected:
    void setReadOnly(bool t);

protected slots:
    void addAvion();
    void maktir3ambetfidbascava();

private:
    Ui::AvionShow *ui;
};

#endif // AVIONSHOW_H
