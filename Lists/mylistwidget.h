#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H

#include <QListView>
#include "Drops/showcreators.h"

class MyListWidget : public QListView
{
    Q_OBJECT
    ShowCreators * _sh;
public:
    explicit MyListWidget(QWidget *parent = 0);
    void set_sh(ShowCreators *sh);
    ShowCreators * sh()const;
    void sendSignalToParent(int i)const;
    ~MyListWidget();
protected:

signals:
    void fetFiyyiEsm(int i)const;
public slots:

};

#endif // MYLISTWIDGET_H
