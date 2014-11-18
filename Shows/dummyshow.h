#ifndef DUMMYSHOW_H
#define DUMMYSHOW_H

#include "show.h"

class DummyShow : public Show
{
    Q_OBJECT
public:
    explicit DummyShow(QWidget *parent = 0);

protected:
    void setReadOnly(bool t);

signals:

public slots:

};

#endif // DUMMYSHOW_H
