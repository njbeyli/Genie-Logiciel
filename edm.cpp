#include "edm.h"

EDM::EDM()
{
    IdEquipe=0;
}

void EDM::setIdEquipe(int i){
    IdEquipe=i;
}

int EDM::getIdEquipe(){
    return IdEquipe;
}

void EDM::getEDM(QString i){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(parse(QNetworkReply*)));
    mgr->post(setNetwork("GetEDM.php"),setUrl("IdEquipe",i));
}

void EDM::parse(QNetworkReply *rep){
    QByteArray bts=rep->readAll();
    QXmlStreamReader xml(bts);
    while (!xml.atEnd()) {
            xml.readNext();
            if(xml.isStartElement()){
                if(xml.qualifiedName()=="IdEquipe"){
                    bool ok;
                    setIdEquipe(xml.readElementText().toInt(&ok,10));
                }
            }
      }
      if (xml.hasError()) {
        qDebug() << "xml error";
      }
      emit doneEDM();
}
// arranger le php pour enlever on duty !!!!!!!!!!!
void EDM::add(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));
    mgr->post(setNetwork("AddEquipeM.php"),setUrl("IdEquipe",QString::number(getIdEquipe())));
}
