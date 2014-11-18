#ifndef ABSTRACTFILTER_H
#define ABSTRACTFILTER_H

#include <QWidget>

class AbstractFilter : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractFilter(QWidget *parent = 0);

    //Mafrud tejeh virtual hon 3an kif
    //sabbit ce filtre
private slots:
    virtual void iShouldSend()=0;

signals:
    void filterExp(QString s);

public slots:


};

#endif // ABSTRACTFILTER_H
