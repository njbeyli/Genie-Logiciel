#include "guichet.h"
#include "ui_guichet.h"

#include <QSplitter>

#include "Lists/voldaujourd.h"
#include "Lists/listcollection.h"
#include "Drops/dropreceiver.h"
#include "Shows/flexibleshowcollection.h"


Guichet::Guichet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Guichet)
{
    ui->setupUi(this);
    setObjectName("Guichet");

    QVBoxLayout *hbl=new QVBoxLayout;
    hbl->setMargin(0);hbl->setSpacing(0);

    QSplitter *s=new QSplitter;
    s->setOrientation(Qt::Horizontal);




    ListCollection *lc=new ListCollection;
    lc->append(new CommonList("Vol d'Aujourd'hui",new VolDaujourd));
    hbl->addWidget(lc);
    hbl->addStretch();

    QHBoxLayout *hb=new QHBoxLayout;
    hb->setMargin(0);hb->setSpacing(0);

    QWidget *n=new QWidget;
    n->setLayout(hbl);
    s->addWidget(n);

    QWidget *c=new QWidget;
    QVBoxLayout *vbox=new QVBoxLayout;
    ShowCollection *shc=new FlexibleShowCollection(0);
    vbox->addWidget(new DropReceiver(shc));
    vbox->addWidget(shc);
    c->setLayout(vbox);

    s->addWidget(c);

    hb->addWidget(s);

    //hb->addStretch();

    setLayout(hb);
}

Guichet::~Guichet()
{
    delete ui;
}
