#ifndef ABSTRACTCENTWID_H
#define ABSTRACTCENTWID_H

#include <QWidget>
#include <Lists/listcollection.h>
#include <Drops/dropreceiver.h>
#include <Shows/showcollection.h>

namespace Ui {
class AbstractCentWid;
}

class AbstractCentWid : public QWidget
{
    Q_OBJECT

    ListCollection *_lc;
    QList<DropReceiver*> _dr;
    ShowCollection *_sc;

public:
    explicit AbstractCentWid(QWidget *parent = 0);
    ~AbstractCentWid();
public slots:
    virtual void setModel()=0;

protected:
    void resizeEvent(QResizeEvent *);
    void lay();

    void set_lc(ListCollection *lc);
    void add_dr(DropReceiver *dr);
    void set_sc(ShowCollection *sc);
    ShowCollection * sc()const;

protected slots:
    virtual void setIndModel(int i)=0;
private:
    Ui::AbstractCentWid *ui;
};

#endif // ABSTRACTCENTWID_H
