#include "equipa.h"

EquipA::EquipA()
{
    IdEq=0;
}

void EquipA::setIdEq(int i){
    IdEq=i;
}

int EquipA::getIdEq(){
    return IdEq;
}

void EquipA::getEquipA(QString i){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(parse(QNetworkReply*)));
    mgr->post(setNetwork("GetEquipA.php"),setUrl("IdEq",i));
}

void EquipA::parse(QNetworkReply *rep){
    QByteArray bts=rep->readAll();
    QXmlStreamReader xml(bts);
    while (!xml.atEnd()) {
            xml.readNext();
            if(xml.isStartElement()){
                if(xml.qualifiedName()=="IdEq"){
                    bool ok;
                    setIdEq(xml.readElementText().toInt(&ok,10));
                }
            }
      }
      if (xml.hasError()) {
        qDebug() << "xml error";
      }
      emit doneEquipA();
}
// arranger le php pour enlever on duty !!!!!!!!!!!
void EquipA::add(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));
    mgr->post(setNetwork("AddEquipeM.php"),setUrl("IdEq",QString::number(getIdEq())));
}
