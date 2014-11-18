#include "treatthread.h"

TreatThread::TreatThread()
{
    global="http://localhost:8888/";

}

QNetworkRequest TreatThread::setNetwork(QString path){
    QNetworkRequest req(QUrl(global+path));
    req.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    return req;
}

QByteArray TreatThread::setUrl(QString key, QString value){
    QByteArray postData;
    postData.append(key).append("=").append(value).append("&");
    return postData;
}
QByteArray TreatThread::setUrl(QByteArray postData, QString key, QString value){
    postData.append(key).append("=").append(value).append("&");
    return postData;
}

QByteArray TreatThread::setUrl(QString key1, QString value1, QString key2, QString value2, QString key3, QString value3){
    QByteArray postData;
    postData.append(key1).append("=").append(value1).append("&").append(key2).append("=").append(value2).append("&").append(key3).append("=").append(value3).append("&");
    //qDebug()<< postData;
    return postData;
}

void TreatThread::tempDeVol(){

    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(onfinish(QNetworkReply*)));
    mgr->post(setNetwork("GetInfo.php"),setUrl(setUrl("Jour",QString::number(QDate::currentDate().addDays(2).dayOfWeek())),"DatPreVol",QDate::currentDate().addDays(2).toString("yyyy-MM-dd")));

}

void TreatThread::voirTemps(){
    //qDebug()<<"dans voir temps";

    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(onfinish(QNetworkReply*)));
    mgr->post(setNetwork("VoirTemps.php"),setUrl(setUrl("DatePreVol",QDate::currentDate().toString("yyyy-MM-dd"),"HeurePreVol",QTime::currentTime().addSecs(3*3600).toString("hh:mm:ss"),"HeureReVol",QTime::currentTime().addSecs(5*60).toString("hh:mm:ss")),"HeureActuelle",QTime::currentTime().toString("hh:mm:ss")));

}

void TreatThread::onfinish(QNetworkReply *rep){
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
