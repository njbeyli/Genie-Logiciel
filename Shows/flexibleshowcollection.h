#ifndef FLEXIBLESHOWCOLLECTION_H
#define FLEXIBLESHOWCOLLECTION_H

#include "showcollection.h"

class FlexibleShowCollection : public ShowCollection
{
    Q_OBJECT
    QHBoxLayout *_mqvb;
    QVBoxLayout *_mqhb[2];
    int _ind[2];
public:
    explicit FlexibleShowCollection(Gerance *g,QWidget *parent = 0);

    void addShow(Show *s);
    Show* _zLast;

private:
    void addingLayout();

signals:

public slots:
    void elimin(QObject *o);
};

#endif // FLEXIBLESHOWCOLLECTION_H
