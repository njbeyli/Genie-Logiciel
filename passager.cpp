#include "passager.h"

Passager::Passager()
{
    IdPass=0;
}

int Passager::getIdPass(){
    return IdPass;
}

int Passager::getIdVol(){
    return IdVol;
}

bool Passager::getCheckIn(){
    return CheckIn;
}

bool Passager::getCheckOut(){
    return CheckOut;
}

bool Passager::getOnBoard(){
    return OnBoard;
}

QString Passager::getNomPass(){
    return NomPass;
}

QString Passager::getPrenomPass(){
    return PrenomPass;
}

QString Passager::getNumPass(){
    return NumPass;
}

void Passager::setIdPass(int i){
    IdPass=i;
}

void Passager::setIdVol(int i){
    IdVol=i;
}

void Passager::setCheckIn(bool i){
    CheckIn=i;
}

void Passager::setCheckOut(bool i){
    CheckOut=i;
}

void Passager::setOnBoard(bool i){
    OnBoard=i;
}

void Passager::setNomPass(QString i){
    NomPass=i;
}

void Passager::setPrenomPass(QString i){
    PrenomPass=i;
}

void Passager::setNumPass(QString i){
    NumPass=i;
}

void Passager::parse(QNetworkReply *rep){
    QByteArray bts=rep->readAll();
    QXmlStreamReader xml(bts);
    while (!xml.atEnd()) {
            xml.readNext();
            if(xml.isStartElement()){
                if(xml.qualifiedName()=="IdPass"){
                    bool ok;
                    setIdPass(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdVol"){
                    bool ok;
                    setIdVol(xml.readElementText().toInt(&ok,10));
              }
                if(xml.qualifiedName()=="NomPass"){
                    setNomPass(xml.readElementText());
                }
                if(xml.qualifiedName()=="PrenomPass"){
                    setPrenomPass(xml.readElementText());
                }
                if(xml.qualifiedName()=="NumPass"){
                    setNumPass(xml.readElementText());
                }
                if(xml.qualifiedName()=="CheckIn"){
                    bool ok;
                    int i=xml.readElementText().toInt(&ok,10);
                    setCheckIn(i==1);
                }
                if(xml.qualifiedName()=="CheckOut"){
                    bool ok;
                    int i=xml.readElementText().toInt(&ok,10);
                    setCheckOut(i==1);
                }
                if(xml.qualifiedName()=="OnBoard"){
                    bool ok;
                    int i=xml.readElementText().toInt(&ok,10);
                    setOnBoard(i==1);
                }

            }
      }
      if (xml.hasError()) {
        qDebug() << "xml error";
      }
}

void Passager::add(){
    qDebug()<< "It is the responsible of the flight agency to ad the passengers";
}
