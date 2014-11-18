#ifndef PROGRAMESHOW_H
#define PROGRAMESHOW_H

#include <QWidget>
#include "show.h"
#include "Lists/mylistwidget.h"
#include <QAbstractItemModel>
#include <QVBoxLayout>

namespace Ui {
class ProgrameShow;
}

class ProgrameShow : public Show
{
    Q_OBJECT
    MyListWidget *_av,*_ae,*_eqm,*_eqa;
    QAbstractItemModel *_mav,*_mae,*_meqm,*_meqa;
    QList<QVBoxLayout*> js;
public:
    explicit ProgrameShow(QString s,bool t,QWidget *parent = 0);
    ~ProgrameShow();
    void setg(Gerance *g);

protected slots:
    void saveProg();

protected:

    void setReadOnly(bool t);

private:
    Ui::ProgrameShow *ui;
};

#endif // PROGRAMESHOW_H
