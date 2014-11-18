#include "item.h"

Item::Item(){
    global="http://localhost:8888/";
    message="";
}

QNetworkRequest Item::setNetwork(QString path){
    QNetworkRequest req(QUrl(global+path));
    req.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    return req;
}

QByteArray Item::setUrl(QString key, QString value){
    QByteArray postData;
    postData.append(key).append("=").append(value).append("&");
    return postData;
}

void Item::reply(QNetworkReply *rep){

QByteArray bts=rep->readAll();
/*
if(!bts.isEmpty()){
QXmlStreamReader xml(bts);
while (!xml.atEnd()) {
        xml.readNext();
        if(xml.isStartElement()){
            if(xml.qualifiedName()=="erreure"){
                qDebug()<< xml.readElementText();
            }
            if(xml.qualifiedName()=="Conflict"){
                message=xml.readElementText();
            }
        }
  }
  if (xml.hasError()) {
    qDebug() << "xml error";
  }
}

    //qDebug()<< bts;
    */
//qDebug()<< bts;
emit doneAdding();
}

QByteArray Item::setUrl(QByteArray postData, QString key, QString value){
    postData.append(key).append("=").append(value).append("&");
    return postData;
}

QByteArray Item::setUrl(QString key1, QString value1, QString key2, QString value2, QString key3, QString value3){
    QByteArray postData;
    postData.append(key1).append("=").append(value1).append("&").append(key2).append("=").append(value2).append("&").append(key3).append("=").append(value3).append("&");
    //qDebug()<< postData;
    return postData;
}

QString Item::getMessage(){
    return message;
}
