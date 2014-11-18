#include "compagnie.h"

Compagnie::Compagnie()
{
    IdComp=0;
}

int Compagnie::getIdComp(){
    return IdComp;
}

QString Compagnie::getNomComp(){
    return NomComp;
}

QString Compagnie::getOrigine(){
    return Origine;
}

void Compagnie::setIdComp(int i){
    IdComp=i;
}

void Compagnie::setNomComp(QString i){
    NomComp=i;
}

void Compagnie::setOrigine(QString i){
    Origine=i;
}

void Compagnie::parse(QNetworkReply *rep){
    QByteArray bts=rep->readAll();
    QXmlStreamReader xml(bts);
    while (!xml.atEnd()) {
            xml.readNext();
            if(xml.isStartElement()){
                if(xml.qualifiedName()=="IdComp"){
                    bool ok;
                    setIdComp(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="NomComp"){
                    setNomComp(xml.readElementText());
                }
                if(xml.qualifiedName()=="Origine"){
                    setOrigine(xml.readElementText());
                }
            }
      }
      if (xml.hasError()) {
        qDebug() << "xml error";
      }
      emit doneCompagnie();
}

void Compagnie::getCompagnie(QString i){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(parse(QNetworkReply*)));
    mgr->post(setNetwork("GetComp.php"),setUrl("IdComp",i));
}

void Compagnie::add(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));
    mgr->post(setNetwork("AddCom.php"),setUrl(setUrl("NomComp",getNomComp()),"Origine",getOrigine()));
}


