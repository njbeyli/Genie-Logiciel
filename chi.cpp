
#include "CHI.h"

CHI::CHI()
{
    getAllVols();
    counter=0;
    rapcounter=0;
    rapref=-1;
}

void CHI::getVolSel(QString i){

    counter++;
    Vo=new Vol();
    Av=new Avion();
    Aero=new Aeroport();
    Equipe=new EDM();
    Prog=new Programme();
    Mod=new Modele();
    Comp=new Compagnie();

    connect(Prog,SIGNAL(doneProg()),this,SLOT(getProgInfo()));
    connect(Av,SIGNAL(doneAvi()),this,SLOT(getAvInfo()));
    connect(Aero,SIGNAL(doneAero()),this,SLOT(getAeroInfo()));
    connect(Mod,SIGNAL(doneModele()),this,SLOT(getModeleInfo()));
    connect(Comp,SIGNAL(doneCompagnie()),this,SLOT(getCompInfo()));

    bool ok;
    int s=i.toInt(&ok,10);
    for(int k=0;k<Vols.length();++k){
        if(Vols.at(k)->getIdVol()==s){
            Vo=Vols.at(k);
            break;
        }
    }
    V<< Vo;
    Equipe->setIdEquipe(V.at(counter-1)->getIdEquipe());
    Equipes<<Equipe;
    Av->getAvion(QString::number(V.at(counter-1)->getIdAvion()));
    Prog->getProg(QString::number(V.at(counter-1)->getIdProg()));
}

void CHI::getAvInfo(){
    Avions<< Av;
    Mod->getModele(QString::number(Avions.at(counter-1)->getIdModele()));
    Comp->getCompagnie(QString::number(Avions.at(counter-1)->getIdComp()));

    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getRapport(QNetworkReply*)));
    mgr->post(setNetwork("GetRap.php"),setUrl("IdVol",QString::number(Vo->getIdVol())));
}

void CHI::getProgInfo(){
    Programmes<< Prog;
    Aero->getAero(QString::number(Prog->getNumAero()));

    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getPersonnel(QNetworkReply*)));
    mgr->post(setNetwork("GetPers.php"),setUrl("IdEquipe",QString::number(Equipe->getIdEquipe())));
    emit doneLoadProg();
}

void CHI::getAeroInfo(){
    Aeroports<< Aero;
}

void CHI::getModeleInfo(){
    Modeles<< Mod;
}

void CHI::getCompInfo(){
    Compagnies<< Comp;
}

void CHI::getAllVols(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getAll(QNetworkReply*)));
    mgr->post(setNetwork("GetAllVols.php"),setUrl("IdVol","1"));
}

void CHI::getAll(QNetworkReply* rep){
    QByteArray bts=rep->readAll();
    Vol *Vo;
    QString p;
    QString a;
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
                    p=xml.readElementText();
                }
                if(xml.qualifiedName()=="NomAero"){
                    a=xml.readElementText();
                }
            }
            if(xml.isEndElement()){
                if(xml.qualifiedName()=="Vol"){
            //        qDebug()<< Vo->getIdVol() <<";" << p << ";" << a ;
                    Vols << Vo;
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

void CHI::getRapport(QNetworkReply* rep){
    Co=new CommonParser();
    QByteArray bts=rep->readAll();
    QList<Item*> Ra;
    Ra=Co->parse(bts);
    //qDebug()<<dynamic_cast<Rapports*>(Ra.at(0))->getIdRapport();
    Rapportss<<Ra;
    //qDebug()<<"le rapport";
    //qDebug()<<Rapportss.length();
    emit doneLoad();
}

void CHI::getPersonnel(QNetworkReply* rep){
    Co=new CommonParser();
    QByteArray bts=rep->readAll();
    QList<Item*> Ps;
    Ps=Co->parse(bts);
    Personnels<< Ps;
    //qDebug()<<dynamic_cast<PDM*>(Personnels.at(0).at(0))->getNomPDM();
}

void CHI::closeVol(QString i){
    bool ok;
    int indice=i.toInt(&ok,10);
    Avions.removeAt(indice);
    Aeroports.removeAt(indice);
    V.removeAt(indice);
    Personnels.removeAt(indice);
    Equipes.removeAt(indice);
    Programmes.removeAt(indice);
    Modeles.removeAt(indice);
    Compagnies.removeAt(indice);
    Rapportss.removeAt(indice);
    counter--;
}

void CHI::RapportsSelected(QString i,QString volref){
    bool ok;
    if((volref.toInt(&ok,10))!=rapref){
        Operationss.clear();
        rapref=volref.toInt(&ok,10);
        rapcounter=0;
    }
    qDebug()<<++rapcounter;
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getOps(QNetworkReply*)));
    mgr->post(setNetwork("GetOps.php"),setUrl("IdRapport",i));
}

void CHI::getOps(QNetworkReply* rep){
    Co=new CommonParser();
    QByteArray bts=rep->readAll();
    QList<Item*> Op;
    Op=Co->parse(bts);
    Operationss<< Op;
    emit doneOperation();
    //qDebug()<<dynamic_cast<Operations*>(Operationss.at(0).at(0))->getIdOp();
}

int CHI::getCounter()const
{
   return  counter;
}

int CHI::getRapref()const
{
    return rapref;
}
int CHI::getRapCounter()const
{
    return rapcounter;
}

CHI::~CHI(){
    delete Vo;
    delete Av;
    delete Aero;
    delete Equipe;
    delete Prog;
    delete Mod;
    delete Comp;
}
