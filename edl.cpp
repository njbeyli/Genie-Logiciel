#include "edl.h"

EDL::EDL()
{
    IdEDL=0;
}

int EDL::getIdEDL(){
    return IdEDL;
}

QString EDL::getNomEDL(){
    return NomEDL;
}

QString EDL::getPrenomEDL(){
    return PrenomEDL;
}

QString EDL::getPoste(){
    return Poste;
}

int EDL::getIdComp(){
    return IdComp;
}

void EDL::setIdEDL(int i){
    IdEDL=i;
}

void EDL::setNomEDL(QString i){
    NomEDL=i;
}

void EDL::setPrenomEDL(QString i){
    PrenomEDL=i;
}

void EDL::setIdComp(int i){
    IdComp=i;
}

void EDL::setPoste(QString i){
    Poste=i;
}

void EDL::parse(QNetworkReply *rep){
    QByteArray bts=rep->readAll();
    QXmlStreamReader xml(bts);
    while (!xml.atEnd()) {
            xml.readNext();
            if(xml.isStartElement()){
                if(xml.qualifiedName()=="IdEDL"){
                    bool ok;
                    setIdEDL(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdComp"){
                    bool ok;
                    setIdComp(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="NomEDL"){
                    setNomEDL(xml.readElementText());
                }
                if(xml.qualifiedName()=="Poste"){
                    setPoste(xml.readElementText());
                }
                if(xml.qualifiedName()=="PrenomEDL"){
                    setPrenomEDL(xml.readElementText());
                }
            }
      }
      if (xml.hasError()) {
        qDebug() << "xml error";
      }
}

void EDL::getEDL(QString i){
        QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
        connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(parse(QNetworkReply*)));
        mgr->post(setNetwork("GetEDL.php"),setUrl("IdEDL",i));
}

void EDL::add(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));
    mgr->post(setNetwork("AddEDL.php"),setUrl(setUrl(setUrl("IdEDL",QString::number(getIdEDL()), "NomEDL",getNomEDL(),"PrenomEDL",getPrenomEDL()),"IdComp",QString::number(getIdComp())),"Poste",getPoste()));

}
