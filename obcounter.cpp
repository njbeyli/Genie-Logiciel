#include "OBCounter.h"


OBCounter::OBCounter()
{
    V=new Vol();
    connect(this,SIGNAL(launch()),this,SLOT(getPass()));
    getVolsActifs();

}

void OBCounter::getVolsActifs(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getActifs(QNetworkReply*)));
    mgr->post(setNetwork("GetActifsPassifs.php"),setUrl("IdVol","1"));
}

void OBCounter::check(QString i){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getPass()));
    mgr->post(setNetwork("OnBoard.php"),setUrl("IdPass",i));
}

void OBCounter::setVolSel(QString i){
    bool ok;
    int s=i.toInt(&ok,10);
    for(int k=0;k<Vols.length();++k){
        if(Vols.at(k)->getIdVol()==s){
            V=Vols.at(k);
            break;
        }
    }
    emit launch();
}

void OBCounter::getPass(){
    Passagers.clear();
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(onFinish(QNetworkReply*)));
    mgr->post(setNetwork("GetP.php"),setUrl("IdVol",QString::number(V->getIdVol())));
}

void OBCounter::onFinish(QNetworkReply* rep){
    QByteArray bts=rep->readAll();
    Passager* p;
    QXmlStreamReader xml(bts);
    while (!xml.atEnd()) {
            xml.readNext();
            if(xml.isStartElement()){
                if(xml.qualifiedName()=="Passager"){
                     p=new Passager();
                }
                if(xml.qualifiedName()=="IdPass"){
                    bool ok;
                    p->setIdPass(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdVol"){
                    bool ok;
                    p->setIdVol(xml.readElementText().toInt(&ok,10));
              }
                if(xml.qualifiedName()=="NomPass"){
                    p->setNomPass(xml.readElementText());
                }
                if(xml.qualifiedName()=="PrenomPass"){
                    p->setPrenomPass(xml.readElementText());
                }
                if(xml.qualifiedName()=="NumPass"){
                    p->setNumPass(xml.readElementText());
                }
                if(xml.qualifiedName()=="CheckIn"){
                    bool ok;
                    int i=xml.readElementText().toInt(&ok,10);
                    p->setCheckIn(i==1);
                }
                if(xml.qualifiedName()=="CheckOut"){
                    bool ok;
                    int i=xml.readElementText().toInt(&ok,10);
                    p->setCheckOut(i==1);
                }
                if(xml.qualifiedName()=="OnBoard"){
                    bool ok;
                    int i=xml.readElementText().toInt(&ok,10);
                    p->setOnBoard(i==1);
                }
            }
            if(xml.isEndElement()){
                if(xml.qualifiedName()=="Passager"){
                    Passagers << p;
                }
            }
      }
      if (xml.hasError()) {
        qDebug() << "xml error";
      }
      emit donePassager();
}

void OBCounter::getActifs(QNetworkReply* rep){
    QByteArray bts=rep->readAll();
    Vol *Vo;
    QString c;
    QXmlStreamReader xml(bts);
    while (!xml.atEnd()) {
            xml.readNext();
            if(xml.isStartElement()){
                if(xml.qualifiedName()=="Vol"){
                    Vo=new Vol();
                }
                if(xml.qualifiedName()=="IdVol"){
                    bool ok;
                    Vo->setIdVol(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdEquipe"){
                    bool ok;
                    Vo->setIdEquipe(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdEq"){
                    bool ok;
                    Vo->setIdEq(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdProg"){
                    bool ok;
                    Vo->setIdProg(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdAvion"){
                    bool ok;
                    Vo->setIdAvion(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="DatPreVol"){
                    Vo->setDatPreVol(QDate::fromString(xml.readElementText(),"yyyy-MM-dd"));
                }
                if(xml.qualifiedName()=="HeurPreVol"){
                    Vo->setHeurPreVol(QTime::fromString(xml.readElementText(),"hh:mm:ss"));
                }
                if(xml.qualifiedName()=="DatReVol"){
                    Vo->setDatReVol(QDate::fromString(xml.readElementText(),"yyyy-MM-dd"));
                }
                if(xml.qualifiedName()=="HeurReVol"){
                    Vo->setHeurReVol(QTime::fromString(xml.readElementText(),"hh:mm:ss"));
                }
                if(xml.qualifiedName()=="EtatVol"){
                    Vo->setEtatVol(xml.readElementText());
                }
                if(xml.qualifiedName()=="Code"){
                    c=xml.readElementText();
                }
            }
            if(xml.isEndElement()){
                if(xml.qualifiedName()=="Vol"){
                    Vols << Vo;
                    Prog<< c;
                }
            }
      }
      if (xml.hasError()) {
        qDebug() << "xml error";
    }
      //qDebug()<< Prog.at(0);
    //  qDebug()<< Prog.at(0);
      //qDebug()<< Prog.at(1);
     //qDebug()<< Prog.at(2);
      emit done();
}

OBCounter::~OBCounter(){
    delete V;
}
