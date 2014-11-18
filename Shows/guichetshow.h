#ifndef GUICHETSHOW_H
#define GUICHETSHOW_H

#include <QWidget>
#include "show.h"
#include "Filters/textfilter.h"
#include "Lists/mylistwidget.h"
#include "QResizeEvent"
#include "counter.h"
#include "passager.h"
#include <QSortFilterProxyModel>
#include <QMap>

namespace Ui {
class GuichetShow;
}

class GuichetShow : public Show
{
    Q_OBJECT

    TextFilter *_co, *_cn;
    MyListWidget *_lo, *_ln;

    QMap<QString, int> _isz;
    QAbstractItemModel *_mo, *_mn;
    QSortFilterProxyModel *_fmo, *_fmn;

public:
    explicit GuichetShow(QString s, QWidget *parent = 0);
    void setModels(QList<Passager*> l);
    void setModels(QList<Passager *> l,int);

    ~GuichetShow();
protected:
    void setReadOnly(bool t);

private slots:
    void insertThe(QString s);\

signals:
    void check(int);

private:
    Ui::GuichetShow *ui;
};

#endif // GUICHETSHOW_H
