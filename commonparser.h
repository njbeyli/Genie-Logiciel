#ifndef COMMONPARSER_H
#define COMMONPARSER_H
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
#include "equipa.h"
#include "edl.h"


class CommonParser
{
private:
    Item * I;
    QList<Item*> l;

    void parseVol(QXmlStreamReader &xml);
    void parseRapport(QXmlStreamReader &xml);
    void parsePersonnelM(QXmlStreamReader &xml);
    void parseOperation(QXmlStreamReader &xml);
    void parseModele(QXmlStreamReader &xml);
    void parseCompagnie(QXmlStreamReader &xml);
    void parseEQM(QXmlStreamReader &xml);
    void parseEQA(QXmlStreamReader &xml);
    void parsePersonnelA(QXmlStreamReader &xml);
    void parseAv(QXmlStreamReader &xml);
    void parseProg(QXmlStreamReader &xml);

    void parseAero(QXmlStreamReader &xml);


public:
    CommonParser();
    QList<Item*> parse(QByteArray bts);
};

#endif // COMMONPARSER_H
