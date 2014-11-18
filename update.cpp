#include "update.h"

Update::Update()
{
    getAv();
    getOp();
    getProg();
    getVo();
    getEDM();
    getPersM();
}

void Update::setIAvion(QString i){
     bool ok;
     int indice=i.toInt(&ok,10);
     for(int k=0;k<Av.length();++k){
         if(dynamic_cast<Avion*>(Av.at(k))->getIdAvion()==indice){
             I=dynamic_cast<Avion*>(Av.at(k));
             break;
         }
     }
}

void Update::setIOperation(QString i){
    bool ok;
    int indice=i.toInt(&ok,10);
    for(int k=0;k<Av.length();++k){
        if(dynamic_cast<Operations*>(Op.at(k))->getIdOp()==indice){
            I=dynamic_cast<Operations*>(Op.at(k));
            break;
        }
    }
}

void Update::setIPDM(QString i){
    bool ok;
    int indice=i.toInt(&ok,10);
    for(int k=0;k<PersM.length();++k){
        if(dynamic_cast<PDM*>(PersM.at(k))->getIdPDM()==indice){
            I=dynamic_cast<PDM*>(PersM.at(k));
            break;
        }
    }
}

void Update::setIProgramme(QString i){
    bool ok;
    int indice=i.toInt(&ok,10);
    for(int k=0;k<Prog.length();++k){
        if(dynamic_cast<Programme*>(Prog.at(k))->getIdProg()==indice){
            I=dynamic_cast<Programme*>(Prog.at(k));
            break;
        }
    }
}

void Update::setIVol(QString i){
    bool ok;
    int indice=i.toInt(&ok,10);
    for(int k=0;k<Vo.length();++k){
        if(dynamic_cast<Vol*>(Vo.at(k))->getIdVol()==indice){
            I=dynamic_cast<Vol*>(Vo.at(k));
            break;
        }
    }
}

Item* Update::getI(){
    return I;
}

void Update::getAv(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getAvReply(QNetworkReply*)));
    mgr->post(setNetwork("GetAv.php"),setUrl("Id","1"));
}

void Update::getAvReply(QNetworkReply *rep){
    Co=new CommonParser();
    QByteArray bts=rep->readAll();
    Av=Co->parse(bts);
    emit doneAvion();
}

void Update::getOp(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getOpReply(QNetworkReply*)));
    mgr->post(setNetwork("GetAllOps.php"),setUrl("Id","1"));
}

void Update::getOpReply(QNetworkReply *rep){
    Co=new CommonParser();
    QByteArray bts=rep->readAll();
    Op=Co->parse(bts);
    emit doneOp();
}

void Update::getEDM(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getEDMReply(QNetworkReply*)));
    mgr->post(setNetwork("GetEQM.php"),setUrl("Id","1"));
}

void Update::getEDMReply(QNetworkReply *rep){
    Co=new CommonParser();
    QByteArray bts=rep->readAll();
    E=Co->parse(bts);
    emit doneEDM();
}

void Update::getPersM(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getPersMReply(QNetworkReply*)));
    mgr->post(setNetwork("GetAllPDM.php"),setUrl("Id","1"));
}

void Update::getPersMReply(QNetworkReply *rep){
    Co=new CommonParser();
    QByteArray bts=rep->readAll();
    PersM=Co->parse(bts);
    emit donePersM();
}

void Update::getProg(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getProgReply(QNetworkReply*)));
    mgr->post(setNetwork("GetAllProg.php"),setUrl("Id","1"));
}

void Update::getProgReply(QNetworkReply *rep){
    qDebug()<<"dans prog reply";
    Co=new CommonParser();
    QByteArray bts=rep->readAll();
    Prog=Co->parse(bts);
    emit doneProg();
}

void Update::getVo(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getVoReply(QNetworkReply*)));
    mgr->post(setNetwork("GetAllVols.php"),setUrl("IdVol","1"));
}

void Update::getVoReply(QNetworkReply *rep){
        QByteArray bts=rep->readAll();
        Vol *VoS;
        QString p;
        QString a;
        QXmlStreamReader xml(bts);
        while (!xml.atEnd()) {
                xml.readNext();
                if(xml.isStartElement()){
                    if(xml.qualifiedName()=="Vol"){
                        VoS=new Vol();
                    }
                    if(xml.qualifiedName()=="IdVol"){
                        bool ok;
                        VoS->setIdVol(xml.readElementText().toInt(&ok,10));
                    }
                    if(xml.qualifiedName()=="IdEquipe"){
                        bool ok;
                        VoS->setIdEquipe(xml.readElementText().toInt(&ok,10));
                    }
                    if(xml.qualifiedName()=="IdEq"){
                        bool ok;
                        VoS->setIdEq(xml.readElementText().toInt(&ok,10));
                    }
                    if(xml.qualifiedName()=="IdProg"){
                        bool ok;
                        VoS->setIdProg(xml.readElementText().toInt(&ok,10));
                    }
                    if(xml.qualifiedName()=="IdAvion"){
                        bool ok;
                        VoS->setIdAvion(xml.readElementText().toInt(&ok,10));
                    }
                    if(xml.qualifiedName()=="DatPreVol"){
                        VoS->setDatPreVol(QDate::fromString(xml.readElementText(),"yyyy-MM-dd"));
                    }
                    if(xml.qualifiedName()=="HeurPreVol"){
                        VoS->setHeurPreVol(QTime::fromString(xml.readElementText(),"hh:mm:ss"));
                    }
                    if(xml.qualifiedName()=="DatReVol"){
                        VoS->setDatReVol(QDate::fromString(xml.readElementText(),"yyyy-MM-dd"));
                    }
                    if(xml.qualifiedName()=="HeurReVol"){
                        VoS->setHeurReVol(QTime::fromString(xml.readElementText(),"hh:mm:ss"));
                    }
                    if(xml.qualifiedName()=="EtatVol"){
                        VoS->setEtatVol(xml.readElementText());
                    }
                    if(xml.qualifiedName()=="Code"){
                        p=xml.readElementText();
                    }
                    if(xml.qualifiedName()=="NomAero"){
                        a=xml.readElementText();
                    }
                }
                if(xml.isEndElement()){
                    if(xml.qualifiedName()=="Vol"){
                //        qDebug()<< Vo->getIdVol() <<";" << p << ";" << a ;
                        Vo << VoS;
                        InfoProg << p;
                        InfoAero << a;
                    }
                }
          }
          if (xml.hasError()) {
            qDebug() << "xml error1";
            }
    /*
          qDebug()<< Vols.at(0)->getIdVol() << InfoProg.at(0) <<InfoAero.at(0);
          qDebug()<< Vols.at(1)->getIdVol() << InfoProg.at(1) <<InfoAero.at(1);
          qDebug()<< Vols.at(2)->getIdVol() << InfoProg.at(2) <<InfoAero.at(2);
          qDebug()<< Vols.at(3)->getIdVol() << InfoProg.at(3) <<InfoAero.at(3);


        qDebug()<< dynamic_cast<Vol*>(Vols.at(0))->getIdVol()<< InfoProg.at(0);
        qDebug()<< dynamic_cast<Vol*>(Vols.at(1))->getIdVol();
        qDebug()<< dynamic_cast<Vol*>(Vols.at(2))->getIdVol();
        qDebug()<< dynamic_cast<Vol*>(Vols.at(3))->getIdVol();
        qDebug()<< dynamic_cast<Vol*>(Vols.at(4))->getIdVol();
    */
          emit doneVol();
    }



void Update::onFinish(QNetworkReply *rep){
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

void Update::updateAv(QString Gare){
    if(dynamic_cast<Avion*>(I)){
        bool ok;
        dynamic_cast<Avion*>(I)->setGare(Gare.toInt(&ok,10));
        dynamic_cast<Avion*>(I)->update();
    }
}

void Update::updateOp(QString DescOp, QString DA){
    if(dynamic_cast<Operations*>(I)){
        dynamic_cast<Operations*>(I)->setDA(DA);
        dynamic_cast<Operations*>(I)->setDescOp(DescOp);
        dynamic_cast<Operations*>(I)->update();
    }
}

void Update::updatePersM(QString Nom, QString Prenom){
    if(dynamic_cast<PDM*>(I)){
        dynamic_cast<PDM*>(I)->setNomPDM(Nom);
        dynamic_cast<PDM*>(I)->setPrenomPDM(Prenom);
        dynamic_cast<PDM*>(I)->update();
    }
}

void Update::updateProg(QString IdAvion, QString IdEquipe, QDate DateFin){
    if(dynamic_cast<Programme*>(I)){
        bool ok;
        dynamic_cast<Programme*>(I)->setIdAvion(IdAvion.toInt(&ok,10));
        dynamic_cast<Programme*>(I)->setIdEquipe(IdEquipe.toInt(&ok,10));
        dynamic_cast<Programme*>(I)->setDateFin(DateFin);
        dynamic_cast<Programme*>(I)->update();
    }
}

void Update::updateVo(QString idEquipe, QString IdAvion, QDate DatPreVol, QTime HeurPreVol){
    if(dynamic_cast<Vol*>(I)){
        bool ok;
        dynamic_cast<Vol*>(I)->setIdEquipe(idEquipe.toInt(&ok,10));
        dynamic_cast<Vol*>(I)->setIdAvion(IdAvion.toInt(&ok,10));
        dynamic_cast<Vol*>(I)->setDatPreVol(DatPreVol);
        dynamic_cast<Vol*>(I)->setHeurPreVol(HeurPreVol);
        dynamic_cast<Vol*>(I)->update();
    }
}


// //////////////////
// ///////////////////////////////////////////////
// /////////////////////////////////////////////////// THIS FUNCTION CALLS THE CONSTRUCTOR OF UPDATE /////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Update::dischargePersM(){
    if(dynamic_cast<PDM*>(I)){
    dynamic_cast<PDM*>(I)->remove();
    }
    Update();
}
