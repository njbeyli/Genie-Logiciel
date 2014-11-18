#include "aeroport.h"

Aeroport::Aeroport()
{
    NumAero=0;
}

void Aeroport::setNomAero(QString i){
    NomAero=i;
}

void Aeroport::setNumAero(int i){
    NumAero=i;
}

void Aeroport::setVille(QString i){
    Ville=i;
}

int Aeroport::getNumAero(){
    return NumAero;
}

QString Aeroport::getNomAero(){
    return NomAero;
}

QString Aeroport::getVille(){
    return Ville;
}

void Aeroport::parse(QNetworkReply *rep){
    QByteArray bts=rep->readAll();
    QXmlStreamReader xml(bts);
    while (!xml.atEnd()) {
            xml.readNext();
            if(xml.isStartElement()){
                if(xml.qualifiedName()=="NumAero"){
                    bool ok;
                    setNumAero(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="NomAero"){
                    setNomAero(xml.readElementText());
                }
                if(xml.qualifiedName()=="Ville"){
                    setVille(xml.readElementText());
                }
            }
      }
      if (xml.hasError()) {
        qDebug() << "xml error";
      }
      emit doneAero();
}

void Aeroport::getAero(QString Aero){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(parse(QNetworkReply*)));
    mgr->post(setNetwork("GetAero.php"),setUrl("NumAero",Aero));
}

void Aeroport::add(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));
    mgr->post(setNetwork("AddAero.php"),setUrl("NumAero",QString::number(getNumAero()),"NomAero",getNomAero(),"Ville",getVille()));
}
