#ifndef ITEM_H
#define ITEM_H
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include<QtNetwork/QNetworkReply>
#include<QWidget>
#include<QXmlStreamReader>
#include <iostream>
#include <QUrl>

class Item : public QObject
{
        Q_OBJECT

private slots:
    virtual void parse(QNetworkReply *rep)=0;
    void reply(QNetworkReply *rep);
public:
    Item();
    QByteArray setUrl(QString key, QString value);
    QByteArray setUrl(QString key1,QString value1,QString key2,QString value2,QString key3,QString value3);
    QByteArray setUrl(QByteArray postData, QString key,QString value);
    QNetworkRequest setNetwork(QString path);
    virtual void add()=0;
    QString getMessage();
protected:
    QString global;
    QString message;

signals:
    void doneAdding();
};

#endif // ITEM_H
