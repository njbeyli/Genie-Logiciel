#include "avion.h"

Avion::Avion()
{
    IdAvion=0;
}

void Avion::setIdAvion(int i){
    IdAvion=i;
}

void Avion::setGare(int i){
    Gare=i;
}

void Avion::setIdAvCom(QString i){
    IdAvCom=i;
}

void Avion::setIdComp(int i){
    IdComp=i;
}

void Avion::setIdModele(int i){
    IdModele=i;
}

int Avion::getIdAvion(){
    return IdAvion;
}

int Avion::getIdComp(){
    return IdComp;
}

int Avion::getGare(){
    return Gare;
}

QString Avion::getIdAvCom(){
    return IdAvCom;
}

int Avion::getIdModele(){
    return IdModele;
}

void Avion::parse(QNetworkReply *rep){
    QByteArray bts=rep->readAll();
    QXmlStreamReader xml(bts);
    while (!xml.atEnd()) {
            xml.readNext();
            if(xml.isStartElement()){
                if(xml.qualifiedName()=="IdAvion"){
                    bool ok;
                    setIdAvion(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdComp"){
                    bool ok;
                    setIdComp(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdModele"){
                    bool ok;
                    setIdModele(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="Gare"){
                    bool ok;
                    setGare(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdAvCom"){
                    setIdAvCom(xml.readElementText());
                }
            }
      }
      if (xml.hasError()) {
        qDebug() << "xml error";
      }
      emit doneAvi();
}

void Avion::getAvion(QString i){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(parse(QNetworkReply*)));
    mgr->post(setNetwork("GetAvion.php"),setUrl("IdAvion",i));
}

void Avion::add(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));
    mgr->post(setNetwork("AddAvion.php"),setUrl(setUrl("IdModele",QString::number(getIdModele()),"IdComp",QString::number(getIdComp()),"IdAvCom",getIdAvCom()),"Gare",QString::number(getGare())));
}

void Avion::update(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));
    mgr->post(setNetwork("UpdateAvion.php"),setUrl(setUrl(setUrl("IdAvion",QString::number(getIdAvion()),"IdModele",QString::number(getIdModele()),"IdComp",QString::number(getIdComp())),"IdAvCom",getIdAvCom()),"Gare",QString::number(getGare())));
}


