#ifndef FLIGHT_H
#define FLIGHT_H

#include <QWidget>

#include <QListWidget>
#include "abstractlist.h"

namespace Ui {
class Flight;
}

class Flight : public AbstractList
{
    Q_OBJECT

    QListView * _ProgView;
    QListWidget * _CompView;
    QList<QString> **_Prog;
    QList<QString> _Comp;

public:
    explicit Flight(QWidget *parent = 0);
    ~Flight();

 //   Show* createShow(QString s);

protected:
    //void dragEnterEvent(QDragEnterEvent *);

public slots:
    void setModel(QAbstractItemModel *i);
    void setModel(QList<QString> l);

private slots:
    void check(bool checked);
    void setProgContent();



private:
    Ui::Flight *ui;
};

#endif // FLIGHT_H
