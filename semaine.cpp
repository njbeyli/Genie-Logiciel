#include "semaine.h"

Semaine::Semaine()
{
    IdProg=0;
}

void Semaine::setCompte(int i){
    Compte=i;
}

void Semaine::setHeure(QTime i){
    Heure=i;
}

void Semaine::setIdProg(int i){
    IdProg=i;
}

void Semaine::setJour(int i){
    Jour=i;
}

void Semaine::setPeriodicite(int i){
    Periodicite=i;
}

int Semaine::getCompte(){
    return Compte;
}

QTime Semaine::getHeure(){
    return Heure;
}

int Semaine::getIdProg(){
    return IdProg;
}

int Semaine::getJour(){
    return Jour;
}

int Semaine::getPeriodicite(){
    return Periodicite;
}

void Semaine::add(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));
    mgr->post(setNetwork("AddSemaine.php"),setUrl(setUrl("IdProg",QString::number(getIdProg()),"Jour",QString::number(getJour()),"Heure",getHeure().toString("hh:mm:ss")),"Periodicite",QString::number(getPeriodicite())));
}

void Semaine::parse(QNetworkReply *rep){
    QByteArray bts=rep->readAll();
    QXmlStreamReader xml(bts);
    while (!xml.atEnd()) {
            xml.readNext();
            if(xml.isStartElement()){
                if(xml.qualifiedName()=="Jour"){
                    bool ok;
                    setJour(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="Periodicite"){
                    bool ok;
                    setPeriodicite(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="Compte"){
                    bool ok;
                    setCompte(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdProg"){
                    bool ok;
                    setIdProg(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="Heure"){
                    setHeure(QTime::fromString(xml.readElementText(),"hh:mm:ss"));
                }
            }
      }
      if (xml.hasError()) {
        qDebug() << "xml error";
      }
}

