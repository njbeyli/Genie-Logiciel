#ifndef TREATTHREAD_H
#define TREATTHREAD_H
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include<QtNetwork/QNetworkReply>
#include<QWidget>
#include<QXmlStreamReader>
#include <QUrl>
#include <iostream>

class TreatThread :public QObject
{
    Q_OBJECT

private:
    QString global;
public:
    TreatThread();
    QByteArray setUrl(QString key, QString value);
    QByteArray setUrl(QString key1,QString value1,QString key2,QString value2,QString key3,QString value3);
    QByteArray setUrl(QByteArray postData, QString key,QString value);
    QNetworkRequest setNetwork(QString path);

public slots:
    void tempDeVol();
    void voirTemps();
    void onfinish(QNetworkReply* rep);
};


#endif // TREATTHREAD_H
