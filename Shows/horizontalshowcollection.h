#ifndef HORIZONTALSHOWCOLLECTION_H
#define HORIZONTALSHOWCOLLECTION_H

#include "showcollection.h"

class HorizontalShowCollection : public ShowCollection
{
    Q_OBJECT

    QVBoxLayout *_vl;
    QList<QHBoxLayout *> _hll;
    QList<int> _sll;

public:
    explicit HorizontalShowCollection(Gerance *g,QWidget *parent = 0);

    void addShow(Show *s);
    Show* _zLast;
private:
    QHBoxLayout * addingLayout();
    void eli(int i);

private slots:

    void elimin(QObject *o);

signals:

public slots:

};

#endif // HORIZONTALSHOWCOLLECTION_H
