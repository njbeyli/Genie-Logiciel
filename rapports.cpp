#include "rapports.h"

Rapports::Rapports()
{
    IdRapport=0;
}

int Rapports::getIdRapport(){
    return IdRapport;
}

int Rapports::getIdAvion(){
    return IdAvion;
}

int Rapports::getIdEquipe(){
    return IdEquipe;
}

int Rapports::getIdVol(){
    return IdVol;
}

QDateTime Rapports::getDateRap(){
    return DateRap;
}

void Rapports::setIdRapport(int i){
    IdRapport=i;
}

void Rapports::setIdAvion(int i){
    IdAvion=i;
}

void Rapports::setIdEquipe(int i){
    IdEquipe=i;
}

void Rapports::setIdVol(int i){
    IdVol=i;
}

void Rapports::setDateRap(QDateTime i){
    DateRap=i;
}

void Rapports::parse(QNetworkReply *rep){
    QByteArray bts=rep->readAll();
    QXmlStreamReader xml(bts);
    while (!xml.atEnd()) {
            xml.readNext();
            if(xml.isStartElement()){
                if(xml.qualifiedName()=="IdRapport"){
                    bool ok;
                    setIdRapport(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdAvion"){
                    bool ok;
                    setIdAvion(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdEquipe"){
                    bool ok;
                    setIdEquipe(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdVol"){
                    bool ok;
                    setIdVol(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="DateRap"){
                    setDateRap(QDateTime::fromString(xml.readElementText(),"yyyy-MM-dd HH.mm.ss"));
                }
            }
      }
      if (xml.hasError()) {
        qDebug() << "xml error";
      }
}

void Rapports::getRapport(QString i){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(parse(QNetworkReply*)));
    mgr->post(setNetwork("GetRapport.php"),setUrl("IdVol",i));
}
// fix php take away direction !!
void Rapports::add(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));
    mgr->post(setNetwork("AddRapport.php"),setUrl(setUrl(setUrl("IdRapport",QString::number(getIdRapport()),"IdEquipe",QString::number(getIdEquipe()),"IdAvion",QString::number(getIdAvion())),"IdVol",QString::number(getIdVol())),"DateRap",getDateRap().toString("yyyy-MM-dd")));

}
