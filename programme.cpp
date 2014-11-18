#include "programme.h"

Programme::Programme()
{
    IdProg=0;
}

int Programme::getIdProg(){
    return IdProg;
}

int Programme::getIdAvion(){
    return IdAvion;
}

int Programme::getIdEquipe(){
    return IdEquipe;
}

int Programme::getIdEq(){
    return IdEq;
}

int Programme::getNumAero(){
    return NumAero;
}

QString Programme::getCode(){
    return Code;
}

QString Programme::getDirection(){
    return Direction;
}

QDate Programme::getDateDebut(){
    return DateDebut;
}

QDate Programme::getDateFin(){
    return DateFin;
}

float Programme::getDuree(){
    return Duree;
}

void Programme::setIdProg(int i){
    IdProg=i;
}

void Programme::setIdAvion(int i){
    IdAvion=i;
}

void Programme::setIdEquipe(int i){
    IdEquipe=i;
}

void Programme::setIdEq(int i){
    IdEq=i;
}

void Programme::setNumAero(int i){
    NumAero=i;
}

void Programme::setDateDebut(QDate i){
        DateDebut.setDate(i.year(),i.month(),i.day());
}

void Programme::setDateFin(QDate i){
        DateFin.setDate(i.year(),i.month(),i.day());
}

void Programme::setCode(QString i){
    Code=i;
}

void Programme::setDirection(QString i){
    Direction=i;
}

void Programme::setDuree(float i){
    Duree=i;
}

void Programme::parse(QNetworkReply *rep){
    QByteArray bts=rep->readAll();
    QXmlStreamReader xml(bts);
    while (!xml.atEnd()) {
            xml.readNext();
            if(xml.isStartElement()){
                if(xml.qualifiedName()=="IdProg"){
                    bool ok;
                    setIdProg(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdEquipe"){
                    bool ok;
                    setIdEquipe(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdEq"){
                    bool ok;
                    setIdEq(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="NumAero"){
                    bool ok;
                    setNumAero(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdAvion"){
                    bool ok;
                    setIdAvion(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="DateDebut"){
                    setDateDebut(QDate::fromString(xml.readElementText(),"yyyy-MM-dd"));
                }
                if(xml.qualifiedName()=="Code"){
                    setCode(xml.readElementText());
                }
                if(xml.qualifiedName()=="DateFin"){
                    setDateFin(QDate::fromString(xml.readElementText(),"yyyy-MM-dd"));
                }
                if(xml.qualifiedName()=="Direction"){
                    setDirection(xml.readElementText());
                }
                if(xml.qualifiedName()=="Duree"){
                    bool ok;
                    setDuree(xml.readElementText().toFloat(&ok));
                }
            }
      }
      if (xml.hasError()) {
        qDebug() << "xml error";
      }
      emit doneProg();
}

void Programme::getProg(QString Prog){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(parse(QNetworkReply*)));
    mgr->post(setNetwork("GetProg.php"),setUrl("IdProg",Prog));
}

void Programme::add(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));
    mgr->post(setNetwork("AddProgramme.php"),setUrl(setUrl(setUrl(setUrl(setUrl(setUrl(setUrl(setUrl("IdProg",QString::number(getIdProg()),"IdAvion",QString::number(getIdAvion()),"IdEquipe",QString::number(getIdEquipe())),"NumAero",QString::number(getNumAero())),"IdEq",QString::number(getIdEq())),"Code",getCode()),"Direction",getDirection()),"DateDebut",getDateDebut().toString("yyyy-MM-dd")),"DateFin",getDateFin().toString("yyyy-MM-dd")),"Duree",QString::number(getDuree())));
}

void Programme::update(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));
    mgr->post(setNetwork("UpdateProgramme.php"),setUrl(setUrl(setUrl(setUrl(setUrl(setUrl(setUrl(setUrl("IdProg",QString::number(getIdProg()),"IdAvion",QString::number(getIdAvion()),"IdEquipe",QString::number(getIdEquipe())),"NumAero",QString::number(getNumAero())),"IdEq",QString::number(getIdEq())),"Code",getCode()),"Direction",getDirection()),"DateDebut",getDateDebut().toString("yyyy-MM-dd")),"DateFin",getDateFin().toString("yyyy-MM-dd")),"Duree",QString::number(getDuree())));
}
