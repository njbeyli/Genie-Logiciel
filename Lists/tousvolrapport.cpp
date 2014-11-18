#include "tousvolrapport.h"
#include "Drops/rapportcreator.h"
TousVolRapport::TousVolRapport(QWidget *parent) :
    TousVol(parent)
{
    _ml->set_sh(new RapportCreator);
}
