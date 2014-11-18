#ifndef GERANCE_H
#define GERANCE_H
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include<QtNetwork/QNetworkReply>
#include<QWidget>
#include<QXmlStreamReader>
#include <QUrl>
#include <iostream>

#include "pdm.h"
#include "edm.h"
#include "aeroport.h"
#include "avion.h"
#include "compagnie.h"
#include "item.h"
#include "modele.h"
#include "operations.h"
#include "passager.h"
#include "programme.h"
#include "rapports.h"
#include "semaine.h"
#include "vol.h"

class Gerance : public QObject
{
    Q_OBJECT

public:
    Gerance();
    QByteArray setUrl(QString key, QString value);
    QByteArray setUrl(QString key1,QString value1,QString key2,QString value2,QString key3,QString value3);
    QByteArray setUrl(QByteArray postData, QString key,QString value);
    QNetworkRequest setNetwork(QString path);

protected:
    QString global;
};

#endif // GERANCE_H
