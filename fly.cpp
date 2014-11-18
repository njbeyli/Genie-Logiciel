#include "fly.h"

Fly::Fly()
{
    getVols();
}

void Fly::getVols(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getVolsReply(QNetworkReply*)));
    mgr->post(setNetwork("GetAllActifs.php"),setUrl("IdVol","1"));
}

void Fly::getVolsReply(QNetworkReply *rep){
    QByteArray bts=rep->readAll();
    Vol *Vo;
    QString p;
    QString a;
    QXmlStreamReader xml(bts);
    while (!xml.atEnd()) {
            xml.readNext();
            if(xml.isStartElement()){
                if(xml.qualifiedName()=="Vol"){
                    Vo=new Vol();
                }
                if(xml.qualifiedName()=="IdVol"){
                    bool ok;
                    Vo->setIdVol(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdEquipe"){
                    bool ok;
                    Vo->setIdEquipe(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdEq"){
                    bool ok;
                    Vo->setIdEq(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdProg"){
                    bool ok;
                    Vo->setIdProg(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdAvion"){
                    bool ok;
                    Vo->setIdAvion(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="DatPreVol"){
                    Vo->setDatPreVol(QDate::fromString(xml.readElementText(),"yyyy-MM-dd"));
                }
                if(xml.qualifiedName()=="HeurPreVol"){
                    Vo->setHeurPreVol(QTime::fromString(xml.readElementText(),"hh:mm:ss"));
                }
                if(xml.qualifiedName()=="DatReVol"){
                    Vo->setDatReVol(QDate::fromString(xml.readElementText(),"yyyy-MM-dd"));
                }
                if(xml.qualifiedName()=="HeurReVol"){
                    Vo->setHeurReVol(QTime::fromString(xml.readElementText(),"hh:mm:ss"));
                }
                if(xml.qualifiedName()=="EtatVol"){
                    Vo->setEtatVol(xml.readElementText());
                }
                if(xml.qualifiedName()=="Code"){
                    p=xml.readElementText();
                }
                if(xml.qualifiedName()=="NomAero"){
                    a=xml.readElementText();
                }
            }
            if(xml.isEndElement()){
                if(xml.qualifiedName()=="Vol"){
            //        qDebug()<< Vo->getIdVol() <<";" << p << ";" << a ;
                    V << Vo;
                    InfoProg << p;
                    InfoAero << a;
                }
            }
      }
      if (xml.hasError()) {
        qDebug() << "xml error1";
        }
    emit doneVol();
}

void Fly::OnFinish(QNetworkReply *rep){
    QByteArray bts=rep->readAll();
    if(!bts.isEmpty()){
    QXmlStreamReader xml(bts);
    while (!xml.atEnd()) {
            xml.readNext();
            if(xml.isStartElement()){
                if(xml.qualifiedName()=="erreure"){
                    qDebug()<< xml.readElementText();
                }
            }
      }
      if (xml.hasError()) {
        qDebug() << "xml error";
      }
    }
}

void Fly::selectVol(QString i){
    bool ok;
    int s=i.toInt(&ok,10);
    for(int k=0;k<V.length();++k){
        if(V.at(k)->getIdVol()==s){
            Vc=V.at(k);
            break;
        }
    }
}

void Fly::takeOff(){
    qDebug()<< Vc->getIdVol();
    Vc->setDatReVol(QDate::currentDate());
    Vc->setHeurReVol(QTime::currentTime());
    Vc->setEtatVol("Ferme");
    connect(Vc,SIGNAL(doneAdding()),this,SLOT(checkOut()));
    Vc->update();
}

void Fly::checkOut(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(OnFinish(QNetworkReply*)));
    mgr->post(setNetwork("CheckOut.php"),setUrl(setUrl("IdVol",QString::number(Vc->getIdVol())),"IdProg",QString::number(Vc->getIdProg())));
}



