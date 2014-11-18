#ifndef MYTABLEWIDGET_H
#define MYTABLEWIDGET_H

#include <QTableView>
#include "Drops/showcreators.h"

class MyTableWidget : public QTableView
{
    Q_OBJECT
    ShowCreators *_sh;
public:
    explicit MyTableWidget(QWidget *parent = 0);
    void set_sh(ShowCreators *sh);
    ShowCreators *sh()const;
    void sendSignalToParent(int i)const;
    ~MyTableWidget();
signals:
    void fetFiyyiEsm(int i)const;
public slots:


};

#endif // MYTABLEWIDGET_H
