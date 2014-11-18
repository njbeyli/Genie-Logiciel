#include "pdm.h"

PDM::PDM()
{
    IdPDM=0;
}

int PDM::getIdPDM(){
    return IdPDM;
}

QString PDM::getNomPDM(){
    return NomPDM;
}

QString PDM::getPrenomPDM(){
    return PrenomPDM;
}

void PDM::setIdPDM(int i){
    IdPDM=i;
}

void PDM::setNomPDM(QString i){
    NomPDM=i;
}

void PDM::setPrenomPDM(QString i){
    PrenomPDM=i;
}

void PDM::parse(QNetworkReply *rep){
    QByteArray bts=rep->readAll();
    QXmlStreamReader xml(bts);
    while (!xml.atEnd()) {
            xml.readNext();
            if(xml.isStartElement()){
                if(xml.qualifiedName()=="IdPDM"){
                    bool ok;
                    setIdPDM(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="NomPDM"){
                    setNomPDM(xml.readElementText());
                }
                if(xml.qualifiedName()=="PrenomPDM"){
                    setPrenomPDM(xml.readElementText());
                }
            }
      }
      if (xml.hasError()) {
        qDebug() << "xml error";
      }
}

void PDM::getPDM(QString i){
        QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
        connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(parse(QNetworkReply*)));
        mgr->post(setNetwork("GetPDM.php"),setUrl("IdPDM",i));
}

void PDM::add(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));
    mgr->post(setNetwork("AddPDM.php"),setUrl("IdPDM",QString::number(getIdPDM()), "NomPDM",getNomPDM(),"PrenomPDM",getPrenomPDM()));
}

void PDM::update(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));
    mgr->post(setNetwork("UpdatePDM.php"),setUrl("IdPDM",QString::number(getIdPDM()), "NomPDM",getNomPDM(),"PrenomPDM",getPrenomPDM()));
}

void PDM::remove(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));
    mgr->post(setNetwork("RemovePDM.php"),setUrl("IdPDM",QString::number(getIdPDM())));

}
