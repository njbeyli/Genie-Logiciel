#ifndef EQDMSHOW_H
#define EQDMSHOW_H
#include "Lists/mylistwidget.h"
#include "show.h"
#include "pdm.h"
#include "Filters/textfilter.h"

namespace Ui {
class EqDMShow;
}

class EqDMShow : public Show
{
    Q_OBJECT
    MyListWidget *_ml;
public:
    explicit EqDMShow(QString s, bool t, QWidget *parent = 0);
    ~EqDMShow();
    void setModels(QList<Item *> personnel);
    void setg(Gerance *g);
protected :
    void setReadOnly(bool t);
protected slots:
    void setPersonnel();
    void addEq();
    void addpdmtoeq();
    void su();
private:
    Ui::EqDMShow *ui;
};

#endif // EQDMSHOW_H
