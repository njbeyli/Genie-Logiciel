#ifndef EMPLOYESHOW_H
#define EMPLOYESHOW_H

//Cet class peut vous tromper elle designe aeroportshow et non employe

#include <QWidget>
#include "show.h"

namespace Ui {
class EmployeShow;
}

class EmployeShow : public Show
{
    Q_OBJECT
    int id;
public:
    explicit EmployeShow(QString s, bool type, QWidget *parent = 0);
    ~EmployeShow();
    void setg(Gerance *g);
protected:
    void setReadOnly(bool t);

protected slots:
    void addAero();
    void shuMeshi();

private:
    Ui::EmployeShow *ui;
};

#endif // EMPLOYESHOW_H
