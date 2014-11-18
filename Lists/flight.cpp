#include "flight.h"
#include "ui_flight.h"
#include <QListWidget>
#include <QMimeData>
#include <QDebug>

#include "Shows/volshow.h"
#include "Lists/mylistwidget.h"
#include "Drops/programecreator.h"
#include "Drops/volcreator.h"

#include <QStringListModel>

#include <QDragEnterEvent>

Flight::Flight(QWidget *parent) :
    AbstractList(parent),
    ui(new Ui::Flight)
{
    ui->setupUi(this);

    _ProgView=new MyListWidget(this);
    //static_cast<MyListWidget*>(_ProgView)->set_sh(new VolCreator);
    _CompView=new QListWidget(this);
    _CompView->setSelectionMode(QAbstractItemView::MultiSelection);
   // _ProgView->setDragEnabled(true);
    _Comp.append("ME");
    _Comp.append("MH");
    _Comp.append("Luftanza");

    //Code a Changer

    _Prog =new QList<QString> * [_Comp.length()];
    for(int i=0;i<_Comp.length();++i)
    {
        _Prog[i]=new QList<QString>[2];
    }
    _Prog[0][0].append("ME 255");
    _Prog[0][0].append("ME 300");
    _Prog[0][0].append("ME 100");
    _Prog[0][1].append("ME 255");
    _Prog[0][0].append("ME 310");
    _Prog[0][0].append("ME 110");

    _Prog[0][0].append("MH 255");
    _Prog[0][0].append("MH 370");
    _Prog[0][0].append("MH 100");
    _Prog[1][1].append("MH 255");
    _Prog[1][0].append("MH 300");
    _Prog[1][1].append("MH 100");
    _Prog[1][0].append("MH 400");
    _Prog[1][1].append("MH 070");

    _Prog[2][1].append("LU 100");
    _Prog[2][0].append("LU 300");
    _Prog[2][1].append("LU 110");

    ui->CompContainer->layout()->addWidget(_CompView);
    ui->ProgContainer->layout()->addWidget(_ProgView);

    QStringListModel *m=new QStringListModel;
    ShowCreators* vc=new ProgrameCreator;
    //qDebug()<<"model "<<vc;
    static_cast<MyListWidget *>(_ProgView)->set_sh(vc);
    //qDebug()<<"model "<<vc->debuging();
    m->setStringList(_Prog[0][0]);
    _ProgView->setModel(m);

    //Jusqu'a ici

    _CompView->addItems(QStringList(_Comp));
    connect(_CompView,SIGNAL(itemSelectionChanged()),this,SLOT(setProgContent()));
    connect(ui->checkBox,SIGNAL(clicked(bool)),this,SLOT(check(bool)));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(setProgContent()));
}


void Flight::check(bool checked)
{
    if(checked)
        _CompView->selectAll();
    else
        _CompView->clearSelection();
}

void Flight::setProgContent()
{
    //_ProgView->clear();
    //QStringList ls;




//    int n=_CompView->selectedItems().length();
//    if(n!=_Comp.length())
//    {
//        ui->checkBox->setChecked(false);
//        if(ui->comboBox->currentText()=="*")
//        {
//            for(int i=0;i<n;++i){
//                for(int k=0;k<2;++k)
//                    ls+=_Prog[_Comp.indexOf(_CompView->selectedItems()[i]->text())][k];
//            }
//        }
//        else if(ui->comboBox->currentText()=="Depart")
//        {
//            for(int i=0;i<n;++i){
//                ls+=_Prog[_Comp.indexOf(_CompView->selectedItems()[i]->text())][0];
//            }
//        }
//        else if(ui->comboBox->currentText()=="Arrivee")
//        {
//            for(int i=0;i<n;++i){
//                ls+=_Prog[_Comp.indexOf(_CompView->selectedItems()[i]->text())][1];
//            }
//        }
//    }
//    else
//    {
//        ui->checkBox->setChecked(true);
//        if(ui->comboBox->currentText()=="*")
//        {
//            for(int i=0;i<n;++i)
//                for(int k=0;k<2;++k)
//                    ls+=_Prog[i][k];
//        }
//        else if(ui->comboBox->currentText()=="Depart")
//        {
//            for(int i=0;i<n;++i)
//                ls+=_Prog[i][0];
//        }
//        else if(ui->comboBox->currentText()=="Arrivee")
//        {
//            for(int i=0;i<n;++i)
//                ls+=_Prog[i][1];

//        }
//    }
//    _ProgView->addItems(ls);
}

//Show* Flight::createShow(QString s)
//{
//    return (new VolShow(s));
//}


//void Flight::dragEnterEvent(QDragEnterEvent *e)
//{
//    QByteArray itemData;
//    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
//    dataStream<<this;
//b    //qDebug()<<"hi";
//}

void Flight::setModel(QAbstractItemModel *i)
{
}
void Flight::setModel(QList<QString> l)
{}


Flight::~Flight()
{
    delete ui;
}


