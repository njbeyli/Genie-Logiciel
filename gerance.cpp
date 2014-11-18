#include "gerance.h"


Gerance::Gerance()
{
    global="http://localhost:8888/";

}

QNetworkRequest Gerance::setNetwork(QString path){
    QNetworkRequest req(QUrl(global+path));
    req.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    return req;
}

QByteArray Gerance::setUrl(QString key, QString value){
    QByteArray postData;
    postData.append(key).append("=").append(value).append("&");
    return postData;
}
QByteArray Gerance::setUrl(QByteArray postData, QString key, QString value){
    postData.append(key).append("=").append(value).append("&");
    return postData;
}

QByteArray Gerance::setUrl(QString key1, QString value1, QString key2, QString value2, QString key3, QString value3){
    QByteArray postData;
    postData.append(key1).append("=").append(value1).append("&").append(key2).append("=").append(value2).append("&").append(key3).append("=").append(value3).append("&");
    //qDebug()<< postData;
    return postData;
}
