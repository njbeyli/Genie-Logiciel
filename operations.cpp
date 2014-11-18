#include "operations.h"

Operations::Operations()
{
    IdOp=0;
}

int Operations::getIdOp(){
    return IdOp;
}

QString Operations::getDA(){
    return DA;
}

QString Operations::getDescOp(){
    return DescOp;
}

QString Operations::getRemarque(){
    return Remarque;
}

int Operations::getGravite(){
    return Gravite;
}

void Operations::setDA(QString i){
    DA=i;
}

void Operations::setDescOp(QString i){
    DescOp=i;
}

void Operations::setIdOp(int i){
    IdOp=i;
}

void Operations::setGravite(int i){
    Gravite=i;
}

void Operations::setRemarque(QString i){
    Remarque=i;
}

void Operations::parse(QNetworkReply *rep){
    QByteArray bts=rep->readAll();
    QXmlStreamReader xml(bts);
    while (!xml.atEnd()) {
            xml.readNext();
            if(xml.isStartElement()){
                if(xml.qualifiedName()=="IdOperations"){
                    bool ok;
                    setIdOp(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="DescOp"){
                    setDescOp(xml.readElementText());
                }
                if(xml.qualifiedName()=="DA"){
                    setDA(xml.readElementText());
                }
                if(xml.qualifiedName()=="Remarque"){
                    setRemarque(xml.readElementText());
                }
                if(xml.qualifiedName()=="Gravite"){
                    bool ok;
                    setGravite(xml.readElementText().toInt(&ok,10));
                }
            }
      }
      if (xml.hasError()) {
        qDebug() << "xml error";
      }
      emit doneOperations();
}

void Operations::add(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));
    mgr->post(setNetwork("AddOp.php"),setUrl("IdOp",QString::number(getIdOp()), "DescOp",getDescOp(),"DA",getDA()));
}

void Operations::update(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));
    mgr->post(setNetwork("UpdateOp.php"),setUrl("IdOp",QString::number(getIdOp()), "DescOp",getDescOp(),"DA",getDA()));
}

Operations::Operations(Operations &Op){
    IdOp=Op.getIdOp();
    DescOp=Op.getDescOp();
    DA=Op.getDA();
    Gravite=Op.getGravite();
    Remarque=Op.getRemarque();
}

Operations* Operations::operator =(Operations &Op){
    IdOp=Op.getIdOp();
    DescOp=Op.getDescOp();
    DA=Op.getDA();
    Gravite=Op.getGravite();
    Remarque=Op.getRemarque();
    return this;
}
