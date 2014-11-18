#ifndef VOLSHOW_H
#define VOLSHOW_H

#include <QWidget>
#include "show.h"
#include "vol.h"
#include "rapports.h"
#include "Lists/mylistwidget.h"
#include "programme.h"

namespace Ui {
class VolShow;
}

class VolShow : public Show
{
    Q_OBJECT
    MyListWidget *_eq,*_av,*_rp,*_ae;
    int pos;
    int id;
public:
    explicit VolShow(QString s, bool type, QWidget *parent = 0);
    ~VolShow();
    void setModels(Vol *v, QList<Item *> rapport, QString s);
    void setModels(Programme *p);
    void setg(Gerance *g);
protected:
    void setReadOnly(bool t);
protected slots:
    void setLastVolAtt();
    void setLastVolAttProg();
    void setRapVolRef(int i);
    void close();
    void take();
    void updatevole();
private:
    Ui::VolShow *ui;
};

#endif // VOLSHOW_H
