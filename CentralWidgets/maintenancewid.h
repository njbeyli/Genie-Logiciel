#ifndef MAINTENANCEWID_H
#define MAINTENANCEWID_H

#include "abstractcentwid.h"
#include "Shows/oneatimeshowcollection.h"
#include "maintenance.h"

class MaintenanceWid : public AbstractCentWid
{
    Q_OBJECT
    Maintenance * _maint;
    ListCollection *lc;
    OneATimeShowCollection *sc;
public:
    explicit MaintenanceWid(QWidget *parent = 0);

signals:

protected slots:
    void setIndModel(int i);
    void setVol();
    void setOpD();
    void setOpA();
    void setEq();
public slots:
    void setModel();
};

#endif // MAINTENANCEWID_H
