#include "maintenance.h"

Maintenance::Maintenance()
{
    getEDM();
    getOpDep();
    getOpAr();
    getVol();
}

void Maintenance::tester(){
    /*qDebug()<< dynamic_cast<Operations*>(OpAr.at(0))->getIdOp();
    qDebug()<< dynamic_cast<Operations*>(OpDep.at(0))->getIdOp();
    qDebug()<< dynamic_cast<Vol*>(Vo.at(0))->getIdVol();
    qDebug()<< dynamic_cast<EDM*>(EqM.at(0))->getIdEquipe();
*/
//qDebug()<<dynamic_cast<Operations*>(OpEf.at(0))->getIdOp();
}

void Maintenance::getOpAr(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getOpArReply(QNetworkReply*)));
    mgr->post(setNetwork("GetOpAr.php"),setUrl("Id","1"));
}

void Maintenance::getOpArReply(QNetworkReply *rep){
    Co=new CommonParser();
    QByteArray bts=rep->readAll();
    OpAr=Co->parse(bts);
    emit doneOpArr();
}

void Maintenance::getOpDep(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getOpDepReply(QNetworkReply*)));
    mgr->post(setNetwork("GetOpDep.php"),setUrl("Id","1"));
}

void Maintenance::getOpDepReply(QNetworkReply *rep){
    Co=new CommonParser();
    QByteArray bts=rep->readAll();
    OpDep=Co->parse(bts);
    emit doneOpDep();
}

void Maintenance::addRemGrav(QString IdOp, QString Rem, QString Gra){
    bool ok;
    int indice=IdOp.toInt(&ok,10);
   // qDebug()<<dynamic_cast<Operations*>(OpEf.at(0))->getIdOp();

    for(int k=0; k<OpEf.length();++k){
        if(dynamic_cast<Operations*>(OpEf.at(k))->getIdOp()==indice){
            dynamic_cast<Operations*>(OpEf.at(k))->setGravite(Gra.toInt(&ok,10));
            dynamic_cast<Operations*>(OpEf.at(k))->setRemarque(Rem);
            break;
        }
    }
}

void Maintenance::getVol(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getVolReply(QNetworkReply*)));
    mgr->post(setNetwork("GetAllVols.php"),setUrl("IdVol","1"));
}

void Maintenance::getVolReply(QNetworkReply *rep){
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



void Maintenance::getEDM(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getEDMReply(QNetworkReply*)));
    mgr->post(setNetwork("GetEQM.php"),setUrl("Id","1"));
}

void Maintenance::getEDMReply(QNetworkReply *rep){
    Co=new CommonParser();
    QByteArray bts=rep->readAll();
    EqM=Co->parse(bts);
    emit doneEDM();
}

void Maintenance::selectOp(QString i){
    bool test=true;
    bool ok;
    int indice=i.toInt(&ok,10);
    for(int k=0; k<OpDep.length();++k){
        if(dynamic_cast<Operations*>(OpDep.at(k))->getIdOp()==indice){
            OpEf<<dynamic_cast<Operations*>(OpDep.at(k));
            qDebug()<<"Depart";
            qDebug()<<OpEf.length();
            test=false;
            break;
        }
    }
    if(test){
        for(int k=0; k<OpAr.length();++k){
            if(dynamic_cast<Operations*>(OpAr.at(k))->getIdOp()==indice){
                OpEf<<dynamic_cast<Operations*>(OpAr.at(k));
                qDebug()<<"arrivee";
                break;
            }
        }
    }
    //qDebug()<<dynamic_cast<Operations*>(OpEf.at(0))->getIdOp();
}

void Maintenance::selectVol(QString i){
    //OpEf.clear();
    bool ok;
    int indice=i.toInt(&ok,10);
    for(int k=0; k<Vo.length();++k){
        if(dynamic_cast<Vol*>(Vo.at(k))->getIdVol()==indice){
            V=dynamic_cast<Vol*>(Vo.at(k));
            break;
        }
    }
}

void Maintenance::selectEDM(QString i){
   // OpEf.clear();
    bool ok;
    int indice=i.toInt(&ok,10);
    for(int k=0; k<EqM.length();++k){
        if(dynamic_cast<EDM*>(EqM.at(k))->getIdEquipe()==indice){
            E=dynamic_cast<EDM*>(EqM.at(k));
            break;
        }
    }
}

void Maintenance::addRapport(){
    qDebug()<<"debut add rapport";
    qDebug()<<OpEf.length();

    Rapports *Ra=new Rapports();
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(onFinish(QNetworkReply*)));
    Ra->setDateRap(QDateTime::currentDateTime());
    Ra->setIdAvion(V->getIdAvion());
    Ra->setIdVol(V->getIdVol());
    Ra->setIdEquipe(E->getIdEquipe());
    connect(Ra,SIGNAL(doneAdding()),this,SLOT(addContient()));
    qDebug()<<"add rapport";
    qDebug()<<OpEf.length();

    Ra->add();
}

void Maintenance::onFinish(QNetworkReply *rep){
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

void Maintenance::addContient(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    qDebug()<<"add contient";

    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(onFinish(QNetworkReply*)));
    qDebug()<<OpEf.length();

    for(int i=0;i<OpEf.length();++i){
        qDebug()<<"id operations : " << dynamic_cast<Operations*>(OpEf.at(i))->getIdOp();

        qDebug()<< dynamic_cast<Operations*>(OpEf.at(i))->getGravite();
    mgr->post(setNetwork("AddContient.php"),setUrl("IdOp",QString::number(dynamic_cast<Operations*>(OpEf.at(i))->getIdOp()),"Remarque",dynamic_cast<Operations*>(OpEf.at(i))->getRemarque(),"Gravite",QString::number(dynamic_cast<Operations*>(OpEf.at(i))->getGravite())));
    }
}
