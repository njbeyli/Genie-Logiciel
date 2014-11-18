#include "aerofiltre.h"
#include <QStringListModel>

AeroFiltre::AeroFiltre(QWidget *parent) :
    ListeFiltre("Aeroport :",parent)
{
    remplirMod();
}

void AeroFiltre::remplirMod()
{
    _lm=new QStringListModel;

    QStringList l;
    l<<"3asmet"<<"sa7it"<<"farju";

    static_cast<QStringListModel *>(_lm)->setStringList(l);

    _lv->setModel(_lm);

    _qvb->addWidget(_lv);
}
