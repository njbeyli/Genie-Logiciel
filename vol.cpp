#include "vol.h"

Vol::Vol()
{
    IdVol=0;
}

Vol::Vol(Vol &v){
    IdVol=v.getIdVol();
    IdEquipe=v.getIdEquipe();
    IdEq=v.getIdEq();
    IdProg=v.getIdProg();
    IdAvion=v.getIdAvion();
    DatPreVol=v.getDatPreVol();
    HeurPreVol=v.getHeurPreVol();
    DatReVol=v.DatReVol;
    HeurReVol=v.HeurReVol;
    EtatVol=v.getEtatVol();
}

Vol* Vol::operator =(Vol &v){
    IdVol=v.getIdVol();
    IdEquipe=v.getIdEquipe();
    IdEq=v.getIdEq();
    IdProg=v.getIdProg();
    IdAvion=v.getIdAvion();
    DatPreVol=v.getDatPreVol();
    HeurPreVol=v.getHeurPreVol();
    DatReVol=v.DatReVol;
    HeurReVol=v.HeurReVol;
    EtatVol=v.getEtatVol();
    return this;
}

void Vol::setIdVol(int i){
    IdVol=i;
}

void Vol::setIdEquipe(int i){
    IdEquipe=i;
}

void Vol::setIdEq(int i){
    IdEq=i;
}

void Vol::setIdProg(int i){
    IdProg=i;
}

void Vol::setIdAvion(int i){
    IdAvion=i;
}

void Vol::setDatPreVol(QDate i){
    DatPreVol.setDate(i.year(),i.month(),i.day());
}

void Vol::setDatReVol(QDate i){
    DatReVol.setDate(i.year(),i.month(),i.day());
}

void Vol::setEtatVol(QString i){
    EtatVol=i;
}

void Vol::setHeurPreVol(QTime i){
    HeurPreVol.setHMS(i.hour(),i.minute(),i.second());
}

void Vol::setHeurReVol(QTime i){
    HeurReVol.setHMS(i.hour(),i.minute(),i.second());
}

int Vol::getIdVol(){
    return IdVol;
}

int Vol::getIdEquipe(){
    return IdEquipe;
}

int Vol::getIdEq(){
    return IdEq;
}

int Vol::getIdAvion(){
    return IdAvion;
}

int Vol::getIdProg(){
    return IdProg;
}

QDate Vol::getDatPreVol(){
    return DatPreVol;
}

QDate Vol::getDatReVol(){
    return DatReVol;
}

QTime Vol::getHeurPreVol(){
    return HeurPreVol;
}

QTime Vol::getHeurReVol(){
    return HeurReVol;
}

QString Vol::getEtatVol(){
    return EtatVol;
}

void Vol::parse(QNetworkReply *rep){
    QByteArray bts=rep->readAll();
    QXmlStreamReader xml(bts);
    while (!xml.atEnd()) {
            xml.readNext();
            if(xml.isStartElement()){
                if(xml.qualifiedName()=="IdVol"){
                    bool ok;
                    setIdVol(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdEquipe"){
                    bool ok;
                    setIdEquipe(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdEq"){
                    bool ok;
                    setIdEq(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdProg"){
                    bool ok;
                    setIdProg(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdAvion"){
                    bool ok;
                    setIdAvion(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="DatPreVol"){
                    setDatPreVol(QDate::fromString(xml.readElementText(),"yyyy-MM-dd"));
                }
                if(xml.qualifiedName()=="HeurPreVol"){
                    setHeurPreVol(QTime::fromString(xml.readElementText(),"hh:mm:ss"));
                }
                if(xml.qualifiedName()=="DatReVol"){
                    setDatReVol(QDate::fromString(xml.readElementText(),"yyyy-MM-dd"));
                }
                if(xml.qualifiedName()=="HeurReVol"){
                    setHeurReVol(QTime::fromString(xml.readElementText(),"hh:mm:ss"));
                }
                if(xml.qualifiedName()=="EtatVol"){
                    setEtatVol(xml.readElementText());
                }
            }
      }
      if (xml.hasError()) {
        qDebug() << "xml error";
}
}

void Vol::getVol(QString Vol){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(parse(QNetworkReply*)));
    mgr->post(setNetwork("GetVol.php"),setUrl("IdVol",Vol));
}

void Vol::getVolProg(QString Prog){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(parse(QNetworkReply*)));
    mgr->post(setNetwork("GetVolProg.php"),setUrl("IdProg",Prog));
}

void Vol::add(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));
    mgr->post(setNetwork("AddVol.php"),setUrl(setUrl(setUrl(setUrl(setUrl(setUrl(setUrl(setUrl("IdVol",QString::number(getIdVol()),"IdEquipe",QString::number(getIdEquipe()),"IdEq",QString::number(getIdEq())),"IdProg",QString::number(getIdProg())),"IdAvion",QString::number(getIdAvion())),"DatPreVol",getDatPreVol().toString("yyyy-MM-dd")),"HeurPreVol",getHeurPreVol().toString("hh:mm:ss")),"DatReVol",getDatReVol().toString("yyyy-MM-dd")),"HeurReVol",getHeurReVol().toString("hh:mm:ss")),"EtatVol",getEtatVol()));
}

void Vol::update(){
    QNetworkAccessManager *mgr=new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));
    qDebug()<<getDatReVol().toString("yyyy-MM-dd");
    qDebug()<<getHeurReVol().toString("hh:mm:ss");
    mgr->post(setNetwork("UpdateVol.php"),setUrl(setUrl(setUrl(setUrl(setUrl(setUrl(setUrl(setUrl("IdVol",QString::number(getIdVol()),"IdEquipe",QString::number(getIdEquipe()),"IdEq",QString::number(getIdEq())),"IdProg",QString::number(getIdProg())),"IdAvion",QString::number(getIdAvion())),"DatPreVol",getDatPreVol().toString("yyyy-MM-dd")),"HeurPreVol",getHeurPreVol().toString("hh:mm:ss")),"DatReVol",getDatReVol().toString("yyyy-MM-dd")),"HeurReVol",getHeurReVol().toString("hh:mm:ss")),"EtatVol",getEtatVol()));
}
