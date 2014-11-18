#include "direction.h"

Direction::Direction()
{
    getCompagnie();
    getModele();
    getEqM();
    getEqA();
    getAv();
    getAero();
    getAllPDM();
    //connect(P,SIGNAL(doneAdding()),this,SLOT(addSemaine()));
    //S=new Semaine();

}

void Direction::addPersonnel(QString nom, QString prenom){
    PDM * personnel;
    if((personnel=dynamic_cast<PDM*>(I))){
    personnel->setNomPDM(nom);
    personnel->setPrenomPDM(prenom);
    personnel->add();
    }
    emit doneAddingPDm();
}

void Direction::addEDM(){
    EDM * Equipe;
    if((Equipe=dynamic_cast<EDM*>(I))){
    Equipe->add();
    }
    emit doneAddingEDm();
}

void Direction::tester(){
   // qDebug()<< "debut test direction";
//    qDebug()<<(dynamic_cast<Compagnie*>(Comp.at(0)))->getNomComp();
//    qDebug()<<(dynamic_cast<Modele*>(Mod.at(0)))->getNomModele();
//    qDebug()<<(dynamic_cast<EDM*>(EqM.at(0)))->getIdEquipe();
//    qDebug()<<(dynamic_cast<EquipA*>(EqA.at(0)))->getIdEq();
//    qDebug()<<(dynamic_cast<Avion*>(Av.at(0)))->getIdAvion();
//    qDebug()<<(dynamic_cast<Aeroport*>(Aero.at(0)))->getNomAero();
 //   qDebug()<< "fin test direction";
}

void Direction::connectPDMEDM(QString IdEquipe, QString IdPDM){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(onFinish(QNetworkReply*)));
    mgr->post(setNetwork("AddForme.php"),setUrl(setUrl("IdEquipe",IdEquipe),"IdPDM",IdPDM));
}

void Direction::addAero(QString NomAero, QString Ville){
    Aeroport * Aero;
    if((Aero=dynamic_cast<Aeroport*>(I))){
    Aero->setNomAero(NomAero);
    Aero->setVille(Ville);
    Aero->add();
    }
    emit doneAddingAero();
}

void Direction::addCompagnie(QString NomComp, QString Origine){
    Compagnie * C;
    if((C=dynamic_cast<Compagnie*>(I))){
    C->setNomComp(NomComp);
    C->setOrigine(Origine);
    C->add();
    }
    emit doneAddingComp();
}

void Direction::addModele(QString Res, QString Dist, QString VitCrois, QString NomM){
    Modele * M;
    if((M=dynamic_cast<Modele*>(I))){
        bool ok;
        M->setDistMax(Dist.toFloat(&ok));
        M->setNomModele(NomM);
        M->setReservoire(Res.toFloat(&ok));
        M->setVitCrois(VitCrois.toFloat(&ok));
        M->add();
    }
    emit doneAddingModel();
}

void Direction::addAvion(QString IdMod, QString IdComp, QString IdAvCom, QString Gare){
    Avion * A;
    if((A=dynamic_cast<Avion*>(I))){
        bool ok;
        A->setGare(Gare.toInt(&ok,10));
        A->setIdModele(IdMod.toInt(&ok,10));
        A->setIdComp(IdComp.toInt(&ok,10));
        A->setIdAvCom(IdAvCom);
        A->add();
    }
    emit doneAddingAvion();
}

void Direction::addProgramme(QString IdAv, QString IdEquipe, QString NumAero, QString IdEq, QString Code, QString Direction, QDate DateDebut, QDate DateFin, QString Duree){
    Programme * P;
    if((P=dynamic_cast<Programme*>(I))){
        bool ok;
        P->setCode(Code);
        P->setIdAvion(IdAv.toInt(&ok,10));
        P->setIdEquipe(IdEquipe.toInt(&ok,10));
        P->setNumAero(NumAero.toInt(&ok,10));
        P->setIdEq(IdEq.toInt(&ok,10));
        P->setDirection(Direction);
        P->setDateDebut(DateDebut);
        P->setDateFin(DateFin);
        P->setDuree(Duree.toFloat(&ok));
        connect(P,SIGNAL(doneAdding()),this,SLOT(addSemaine()));
        P->add();
    }
}

void Direction::setIAero(){
    I=new Aeroport();
}

Item* Direction::getI(){
    return I;
}

void Direction::setIPDM(){
    I=new PDM();
}

void Direction::setIEDM(){
    I=new EDM();
}

void Direction::setIModele(){
    I=new Modele();
}

void Direction::setIAvion(){
    I=new Avion();
}

void Direction::setICompagnie(){
    I=new Compagnie();
}

void Direction::setIProgramme(){
    I=new Programme();
    Se.clear();
}

void Direction::onFinish(QNetworkReply *rep){
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

void Direction::getCompagnie(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getCompagnieReply(QNetworkReply*)));
    mgr->post(setNetwork("GetCompagnie.php"),setUrl("Id","1"));
}

void Direction::getCompagnieReply(QNetworkReply* rep){
    Co=new CommonParser();
    QByteArray bts=rep->readAll();
    Comp=Co->parse(bts);
   // qDebug()<< dynamic_cast<Compagnie*>(Comp.at(0))->getNomComp();
    //qDebug()<< dynamic_cast<Compagnie*>(Comp.at(1))->getNomComp();
    emit doneCompagnie();
}

void Direction::getModele(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getModeleReply(QNetworkReply*)));
    mgr->post(setNetwork("GetMod.php"),setUrl("Id","1"));
}

void Direction::getModeleReply(QNetworkReply *rep){
    Co=new CommonParser();
    QByteArray bts=rep->readAll();
    Mod=Co->parse(bts);
  //  qDebug()<< dynamic_cast<Modele*>(Mod.at(0))->getNomModele();
    emit doneModele();
}

void Direction::getEqM(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getEqMReply(QNetworkReply*)));
    mgr->post(setNetwork("GetEQM.php"),setUrl("Id","1"));

}

void Direction::getEqMReply(QNetworkReply *rep){
    Co=new CommonParser();
    QByteArray bts=rep->readAll();
    EqM=Co->parse(bts);
    emit doneEqM();
}

void Direction::getAllPDM(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getAllPDMReply(QNetworkReply*)));
    mgr->post(setNetwork("GetAllPDM.php"),setUrl("Id","1"));
}

void Direction::getAllPDMReply(QNetworkReply *rep){
    Co=new CommonParser();
    QByteArray bts=rep->readAll();
    ToutPersM=Co->parse(bts);
        emit donePDM();
}

void Direction::getEqA(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getEqAReply(QNetworkReply*)));
    mgr->post(setNetwork("GetEQA.php"),setUrl("Id","1"));
}

void Direction::getEqAReply(QNetworkReply *rep){
    Co=new CommonParser();
    QByteArray bts=rep->readAll();
    EqA=Co->parse(bts);
    doneEqA();
}

void Direction::getPDM(QString idEq){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getPDMReply(QNetworkReply*)));
    mgr->post(setNetwork("GetPers.php"),setUrl("IdEquipe",idEq));
}

void Direction::getPDMReply(QNetworkReply *rep){
    Co=new CommonParser();
    QByteArray bts=rep->readAll();
    QList<Item*> Ps;
    Ps=Co->parse(bts);
    PersM<<Ps;
    emit doneZPDM();
}

void Direction::getPDL(QString idEq){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getPDLReply(QNetworkReply*)));
    mgr->post(setNetwork("GetPersA.php"),setUrl("IdEq",idEq));
}

void Direction::getPDLReply(QNetworkReply *rep){
    Co=new CommonParser();
    QByteArray bts=rep->readAll();
    QList<Item*> Ps;
    Ps=Co->parse(bts);
    PersA<<Ps;
}

void Direction::getAv(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getAvReply(QNetworkReply*)));
    mgr->post(setNetwork("GetAv.php"),setUrl("Id","1"));
}

void Direction::getAvReply(QNetworkReply *rep){
    Co=new CommonParser();
    QByteArray bts=rep->readAll();
    Av=Co->parse(bts);
    emit doneAvion();
}

void Direction::getAero(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager();
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(getAeroReply(QNetworkReply*)));
    mgr->post(setNetwork("GetArp.php"),setUrl("Id","1"));
}

void Direction::getAeroReply(QNetworkReply *rep){
    Co=new CommonParser();
    QByteArray bts=rep->readAll();
    Aero=Co->parse(bts);
    emit doneAero();
}

void Direction::addSemaine(){
    int i=0;
    while(i<Se.length()){
        Se.at(i)->add();
        ++i;
    }
}

// ///////////////////// Semaine has a function that returns to you if we were able to add the occurence or if there is a conflict
// //////////////////// This function is called getMessage(), it returns a QString.
// /////////////////// feel free to put the QList Se in a public state to be able to apply this functions to the Semaine that
// ////////////////// form this qlist. Enjoy.


void Direction::addJour(QString J, QTime H, QString P){
    bool ok;
    S=new Semaine();
    S->setJour(J.toInt(&ok,10));
    S->setHeure(H);
    S->setPeriodicite(P.toInt(&ok,10));
    Se << S;
}
