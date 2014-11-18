#ifndef SHOWCOLLECTION_H
#define SHOWCOLLECTION_H

#include <QWidget>
#include <QLayout>
#include "show.h"
#include "gerance.h"

class ShowCollection : public QWidget
{
    Q_OBJECT
    Gerance *_g;
public:
    explicit ShowCollection(Gerance* g,QWidget *parent = 0);
    virtual void addShow(Show *s)=0;
    Gerance *g()const;
private:



private slots:
    virtual void elimin(QObject *o)=0;
signals:

public slots:

};

#endif // SHOWCOLLECTION_H
