#include "commonparser.h"

CommonParser::CommonParser()
{
}

QList<Item*> CommonParser::parse(QByteArray bts){
    QXmlStreamReader xml(bts);
  //  qDebug()<< "it is called";
    if (xml.hasError()) {
      qDebug() << "xml error";
      }
    while(!xml.atEnd()){
    xml.readNext();
    if(xml.isStartElement()){
        if(xml.qualifiedName()=="Vol"){
            parseVol(xml);
        }
        if(xml.qualifiedName()=="Rapport"){
            parseRapport(xml);
        }
        if(xml.qualifiedName()=="PDM"){
            parsePersonnelM(xml);
        }
        if(xml.qualifiedName()=="Operations"){
            parseOperation(xml);
        }
        if(xml.qualifiedName()=="Modele"){
            parseModele(xml);
        }
        if(xml.qualifiedName()=="Compagnie"){
            parseCompagnie(xml);
        }
        if(xml.qualifiedName()=="EDM"){
            parseEQM(xml);
        }
        if(xml.qualifiedName()=="EquipA"){
            parseEQA(xml);
        }
        if(xml.qualifiedName()=="EDL"){
            parsePersonnelA(xml);
        }
        if(xml.qualifiedName()=="Avion"){
            parseAv(xml);
        }
        if(xml.qualifiedName()=="Aeroport"){
            parseAero(xml);
        }
        if(xml.qualifiedName()=="Prog"){
            parseProg(xml);
        }
    }
    }
    return l;
}

void CommonParser::parseVol(QXmlStreamReader &xml){
    I=new Vol();
    qDebug()<< "in vol";
    while(!(xml.isEndElement()&&xml.qualifiedName()=="Vol")){
        xml.readNext();
        if(xml.isStartElement()){
            if(xml.qualifiedName()=="IdVol"){
                bool ok;
                dynamic_cast<Vol*>(I)->setIdVol(xml.readElementText().toInt(&ok,10));
            }
            if(xml.qualifiedName()=="IdEquipe"){
                bool ok;
                dynamic_cast<Vol*>(I)->setIdEquipe(xml.readElementText().toInt(&ok,10));
            }
            if(xml.qualifiedName()=="IdEq"){
                bool ok;
                dynamic_cast<Vol*>(I)->setIdEq(xml.readElementText().toInt(&ok,10));
            }
            if(xml.qualifiedName()=="IdProg"){
                bool ok;
                dynamic_cast<Vol*>(I)->setIdProg(xml.readElementText().toInt(&ok,10));
            }
            if(xml.qualifiedName()=="IdAvion"){
                bool ok;
                dynamic_cast<Vol*>(I)->setIdAvion(xml.readElementText().toInt(&ok,10));
            }
            if(xml.qualifiedName()=="DatPreVol"){
                dynamic_cast<Vol*>(I)->setDatPreVol(QDate::fromString(xml.readElementText(),"yyyy-MM-dd"));
            }
            if(xml.qualifiedName()=="HeurPreVol"){
                dynamic_cast<Vol*>(I)->setHeurPreVol(QTime::fromString(xml.readElementText(),"hh:mm:ss"));
            }
            if(xml.qualifiedName()=="DatReVol"){
                dynamic_cast<Vol*>(I)->setDatReVol(QDate::fromString(xml.readElementText(),"yyyy-MM-dd"));
            }
            if(xml.qualifiedName()=="HeurReVol"){
                dynamic_cast<Vol*>(I)->setHeurReVol(QTime::fromString(xml.readElementText(),"hh:mm:ss"));
            }
            if(xml.qualifiedName()=="EtatVol"){
                dynamic_cast<Vol*>(I)->setEtatVol(xml.readElementText());
            }
        }
    }
    l<<I;
}

void CommonParser::parseRapport(QXmlStreamReader &xml){
    I=new Rapports();
    qDebug()<< "in rapport";
    while (!(xml.isEndElement()&&xml.qualifiedName()=="Rapport")) {
            xml.readNext();
            if(xml.isStartElement()){
                if(xml.qualifiedName()=="IdRapport"){
                    bool ok;
                    dynamic_cast<Rapports*>(I)->setIdRapport(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdAvion"){
                    bool ok;
                    dynamic_cast<Rapports*>(I)->setIdAvion(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdEquipe"){
                    bool ok;
                    dynamic_cast<Rapports*>(I)->setIdEquipe(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdVol"){
                    bool ok;
                    dynamic_cast<Rapports*>(I)->setIdVol(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="DateRap"){
                    dynamic_cast<Rapports*>(I)->setDateRap(QDateTime::fromString(xml.readElementText(),"yyyy-MM-dd HH:mm:ss"));
                }
            }
      }
    l<<I;
}

void CommonParser::parsePersonnelM(QXmlStreamReader &xml){
    I=new PDM();
    while (!(xml.isEndElement()&&xml.qualifiedName()=="PDM")) {
            xml.readNext();
            if(xml.isStartElement()){
                if(xml.qualifiedName()=="IdPDM"){
                    bool ok;
                    dynamic_cast<PDM*>(I)->setIdPDM(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="NomPDM"){
                    dynamic_cast<PDM*>(I)->setNomPDM(xml.readElementText());
                }
                if(xml.qualifiedName()=="PrenomPDM"){
                    dynamic_cast<PDM*>(I)->setPrenomPDM(xml.readElementText());
                }
            }
      }
    l<<I;
}

void CommonParser::parseOperation(QXmlStreamReader &xml){
        I=new Operations();
        while (!(xml.isEndElement()&&xml.qualifiedName()=="Operations")) {
            xml.readNext();
            if(xml.isStartElement()){
                if(xml.qualifiedName()=="IdOperations"){
                    bool ok;
                    dynamic_cast<Operations*>(I)->setIdOp(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="DescOp"){
                    dynamic_cast<Operations*>(I)->setDescOp(xml.readElementText());
                    //Debug()<<dynamic_cast<Operations*>(I)->getDescOp();
                }
                if(xml.qualifiedName()=="DA"){
                    dynamic_cast<Operations*>(I)->setDA(xml.readElementText());
                }
                if(xml.qualifiedName()=="Remarque"){
                    dynamic_cast<Operations*>(I)->setRemarque(xml.readElementText());
                }
                if(xml.qualifiedName()=="Gravite"){
                    bool ok;
                    dynamic_cast<Operations*>(I)->setGravite(xml.readElementText().toInt(&ok,10));
                }
            }
      }
        l<<I;
}

void CommonParser::parseModele(QXmlStreamReader &xml){
    I=new Modele();
    while (!(xml.isEndElement()&&xml.qualifiedName()=="Modele")) {
        xml.readNext();
        if(xml.isStartElement()){
            if(xml.qualifiedName()=="IdModele"){
                bool ok;
                dynamic_cast<Modele*>(I)->setIdModele(xml.readElementText().toInt(&ok,10));
            }
            if(xml.qualifiedName()=="VitCrois"){
                bool ok;
                dynamic_cast<Modele*>(I)->setVitCrois(xml.readElementText().toFloat(&ok));
            }
            if(xml.qualifiedName()=="DistMax"){
                bool ok;
                dynamic_cast<Modele*>(I)->setDistMax(xml.readElementText().toFloat(&ok));
            }
            if(xml.qualifiedName()=="Reservoire"){
                bool ok;
                dynamic_cast<Modele*>(I)->setReservoire(xml.readElementText().toFloat(&ok));
            }
            if(xml.qualifiedName()=="NomModel"){
                dynamic_cast<Modele*>(I)->setNomModele(xml.readElementText());
            }
        }
    }
    l<<I;
}

void CommonParser::parseCompagnie(QXmlStreamReader &xml){
    I=new Compagnie();
    while (!(xml.isEndElement()&&xml.qualifiedName()=="Compagnie")) {
        xml.readNext();
        if(xml.isStartElement()){
            if(xml.qualifiedName()=="IdComp"){
                bool ok;
                dynamic_cast<Compagnie*>(I)->setIdComp(xml.readElementText().toInt(&ok,10));
            }
            if(xml.qualifiedName()=="NomComp"){
                dynamic_cast<Compagnie*>(I)->setNomComp(xml.readElementText());
            }
            if(xml.qualifiedName()=="Origine"){
                dynamic_cast<Compagnie*>(I)->setOrigine(xml.readElementText());
            }
        }
    }
    l<<I;
}

void CommonParser::parseEQM(QXmlStreamReader &xml){
    I=new EDM();
    while (!(xml.isEndElement()&&xml.qualifiedName()=="EDM")) {
        xml.readNext();
        if(xml.isStartElement()){
            if(xml.qualifiedName()=="IdEquipe"){
                bool ok;
                dynamic_cast<EDM*>(I)->setIdEquipe(xml.readElementText().toInt(&ok,10));
            }
        }
    }
    l<<I;
}

void CommonParser::parseEQA(QXmlStreamReader &xml){
    I=new EquipA();
    while (!(xml.isEndElement()&&xml.qualifiedName()=="EquipA")) {
        xml.readNext();
        if(xml.isStartElement()){
            if(xml.qualifiedName()=="IdEq"){
                bool ok;
                dynamic_cast<EquipA*>(I)->setIdEq(xml.readElementText().toInt(&ok,10));
            }
        }
    }
    l<<I;
}

void CommonParser::parsePersonnelA(QXmlStreamReader &xml){
    I=new EDL();
    while (!(xml.isEndElement()&&xml.qualifiedName()=="EDL")) {
        xml.readNext();
        if(xml.isStartElement()){
            if(xml.qualifiedName()=="IdEDL"){
                bool ok;
                dynamic_cast<EDL*>(I)->setIdEDL(xml.readElementText().toInt(&ok,10));
            }
            if(xml.qualifiedName()=="IdComp"){
                bool ok;
                dynamic_cast<EDL*>(I)->setIdComp(xml.readElementText().toInt(&ok,10));
            }
            if(xml.qualifiedName()=="NomEDL"){
                dynamic_cast<EDL*>(I)->setNomEDL(xml.readElementText());
            }
            if(xml.qualifiedName()=="Poste"){
                dynamic_cast<EDL*>(I)->setPoste(xml.readElementText());
            }
            if(xml.qualifiedName()=="PrenomEDL"){
                dynamic_cast<EDL*>(I)->setPrenomEDL(xml.readElementText());
            }
        }
    }
    l<<I;
}

void CommonParser::parseAv(QXmlStreamReader &xml){
    I=new Avion();
    while (!(xml.isEndElement()&&xml.qualifiedName()=="Avion")) {
        xml.readNext();
        if(xml.isStartElement()){
            if(xml.qualifiedName()=="IdAvion"){
                bool ok;
                dynamic_cast<Avion*>(I)->setIdAvion(xml.readElementText().toInt(&ok,10));
            }
            if(xml.qualifiedName()=="IdComp"){
                bool ok;
                dynamic_cast<Avion*>(I)->setIdComp(xml.readElementText().toInt(&ok,10));
            }
            if(xml.qualifiedName()=="IdModele"){
                bool ok;
                dynamic_cast<Avion*>(I)->setIdModele(xml.readElementText().toInt(&ok,10));
            }
            if(xml.qualifiedName()=="Gare"){
                bool ok;
                dynamic_cast<Avion*>(I)->setGare(xml.readElementText().toInt(&ok,10));
            }
            if(xml.qualifiedName()=="IdAvCom"){
                dynamic_cast<Avion*>(I)->setIdAvCom(xml.readElementText());
            }
        }
    }
    l<<I;

}

void CommonParser::parseAero(QXmlStreamReader &xml){
    I=new Aeroport();
    while (!(xml.isEndElement()&&xml.qualifiedName()=="Aeroport")) {
        xml.readNext();
        if(xml.isStartElement()){
            if(xml.qualifiedName()=="NumAero"){
                bool ok;
                dynamic_cast<Aeroport*>(I)->setNumAero(xml.readElementText().toInt(&ok,10));
            }
            if(xml.qualifiedName()=="NomAero"){
                dynamic_cast<Aeroport*>(I)->setNomAero(xml.readElementText());
            }
            if(xml.qualifiedName()=="Ville"){
                dynamic_cast<Aeroport*>(I)->setVille(xml.readElementText());
            }
        }
    }
    l<<I;
}

void CommonParser::parseProg(QXmlStreamReader &xml){
    I=new Programme();
    while (!(xml.isEndElement()&&xml.qualifiedName()=="Prog")) {
            xml.readNext();
            if(xml.isStartElement()){
                if(xml.qualifiedName()=="IdProg"){
                    bool ok;
                     dynamic_cast<Programme*>(I)->setIdProg(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdEquipe"){
                    bool ok;
                    dynamic_cast<Programme*>(I)->setIdEquipe(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdEq"){
                    bool ok;
                    dynamic_cast<Programme*>(I)->setIdEq(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="NumAero"){
                    bool ok;
                    dynamic_cast<Programme*>(I)->setNumAero(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="IdAvion"){
                    bool ok;
                    dynamic_cast<Programme*>(I)->setIdAvion(xml.readElementText().toInt(&ok,10));
                }
                if(xml.qualifiedName()=="DateDebut"){
                    dynamic_cast<Programme*>(I)->setDateDebut(QDate::fromString(xml.readElementText(),"yyyy-MM-dd"));
                }
                if(xml.qualifiedName()=="Code"){
                    dynamic_cast<Programme*>(I)->setCode(xml.readElementText());
                }
                if(xml.qualifiedName()=="DateFin"){
                    dynamic_cast<Programme*>(I)->setDateFin(QDate::fromString(xml.readElementText(),"yyyy-MM-dd"));
                }
                if(xml.qualifiedName()=="Direction"){
                    dynamic_cast<Programme*>(I)->setDirection(xml.readElementText());
                }
                if(xml.qualifiedName()=="Duree"){
                    bool ok;
                    dynamic_cast<Programme*>(I)->setDuree(xml.readElementText().toFloat(&ok));
                }
            }
      }
    qDebug()<<dynamic_cast<Programme*>(I)->getIdProg();
    l<<I;
}
