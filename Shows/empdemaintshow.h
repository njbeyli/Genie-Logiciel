#ifndef EMPDEMAINTSHOW_H
#define EMPDEMAINTSHOW_H

#include <QWidget>
#include "show.h"

namespace Ui {
class EmpDeMaintShow;
}

class EmpDeMaintShow : public Show
{
    Q_OBJECT

public:
    explicit EmpDeMaintShow(QWidget *parent = 0);
    ~EmpDeMaintShow();
    void setg(Gerance *g);
protected:

    void setReadOnly(bool t);

protected slots:
    void addPerson();
    void leffha();

private:
    Ui::EmpDeMaintShow *ui;
};

#endif // EMPDEMAINTSHOW_H
