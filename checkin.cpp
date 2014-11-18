#include "checkin.h"
#include "ui_checkin.h"

using namespace std;

CheckIn::CheckIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckIn)
{
    ui->setupUi(this);
    //C=new OBCounter();
    //T=new CHI();
    //D=new Direction();
    MW=new MainWindow();
    //M=new Maintenance();
    U=new Update();
    F=new Fly();
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(selected()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(checked()));
}

void CheckIn::selected(){
    //T->getVolSel(ui->textEdit->toPlainText());
    //D->addPersonnel("fadi","helou");
    //D->addEDM();
   // D->setIAvion();
    //D->connectPDMEDM("6","6");
    //D->setIProgramme();
    //M->selectVol("1");
   // M->selectEDM("1");
   // M->selectOp("1");
    //M->addRemGrav("1","2343","2");
    //D->tester();
   // U->setIAvion("1");
    F->selectVol("3");
    //MW->tempDeVol();
}

void CheckIn::checked(){
    //T->closeVol("0");
     //D->addAero("4","yyy");
   // T->RapportsSelected("1");
  //  D->addAvion("1","1","3","4");
   // D->addProgramme("1","1","1","1","1","dd",QDate::currentDate(),QDate::currentDate(),"1");
    //qDebug()<<"tester";
   // M->tester();
   // M->addRapport();
    //U->updateAv("4");
    F->takeOff();
}

CheckIn::~CheckIn()
{
    delete ui;
}


