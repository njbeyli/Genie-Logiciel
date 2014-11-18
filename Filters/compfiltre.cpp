#include "compfiltre.h"
#include <QStringListModel>

CompFiltre::CompFiltre(QWidget *parent) :
    ListeFiltre("Compagnie :",parent)
{
    remplirMod();

}

//Pour Tester

void CompFiltre::remplirMod()
{
    _lm=new QStringListModel;

    QStringList l;
    l<<"hi"<<"bu"<<"elie";

    static_cast<QStringListModel *>(_lm)->setStringList(l);

    _lv->setModel(_lm);

    _qvb->addWidget(_lv);
}
