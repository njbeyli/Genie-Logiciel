#include "modele.h"

Modele::Modele()
{
    IdModele=0;
}

void Modele::setReservoire(float i){
    Reservoire=i;
}

void Modele::setDistMax(float i){
    DistMax=i;
}

void Modele::setNomModele(QString i){
    NomModele=i;
}

void Modele::setIdModele(int i){
    IdModele=i;
}

void Modele::setVitCrois(float i){
    VitCrois=i;
}

int Modele::getIdModele(){
    return IdModele;
}

QString Modele::getNomModele(){
    return NomModele;
}

float Modele::getDistMax(){
    return DistMax;
}

float Modele::getReservoire(){
    return Reservoire;
}

float Modele::getVitCrois(){
    return VitCrois;
}

void Modele::parse(QNetworkReply *rep){
    QByteArray bts=rep->readAll();
    QXmlStreamReader xml(bts);
    while (!xml.atEnd()) {
            xml.readNext();
            if(xml.isStartElement()){
                if(xml.qualifiedName()=="IdModele"){
                    bool ok;
                    setIdModele(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="VitCrois"){
                    bool ok;
                    setVitCrois(xml.readElementText().toFloat(&ok));
                }
                if(xml.qualifiedName()=="DistMax"){
                    bool ok;
                    setDistMax(xml.readElementText().toFloat(&ok));
                }
                if(xml.qualifiedName()=="Reservoire"){
                    bool ok;
                    setReservoire(xml.readElementText().toFloat(&ok));
                }
                if(xml.qualifiedName()=="NomModel"){
                    setNomModele(xml.readElementText());
                }
            }
      }
      if (xml.hasError()) {
        qDebug() << "xml error";
      }
      emit doneModele();
}

void Modele::getModele(QString i){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(parse(QNetworkReply*)));
    mgr->post(setNetwork("GetModele.php"),setUrl("IdModele",i));
}
// arranger php pour enlever les classes !!!!!! premiere busness econ !!
void Modele::add(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));
    mgr->post(setNetwork("AddMod.php"),setUrl(setUrl(setUrl("IdModele",QString::number(getIdModele()),"Reservoire",QString::number(getReservoire()),"DistMax",QString::number(getDistMax())),"VitCrois",QString::number(getVitCrois())),"NomModel",getNomModele()));
}
