#include "stock.h"

Stock::Stock()
{

}


void Stock::AjouterRouleau(const Rouleau _nouveau)
{
    lesRouleaux.insert(_nouveau.getDiametre(), _nouveau);
}

int Stock::RechercherSerie(QMultiMap<int,Rouleau>::iterator &_positionDebut)
{
    int nbRouleauSorti = lesRouleaux.size();
    int ecartDiametre = 40;

    if (nbRouleauSorti >= 6)
    {
        for (auto it = lesRouleaux.begin(); it != lesRouleaux.end() - 6; it++)
        {
            for (auto it2 = lesRouleaux.begin() + 6; it2 != lesRouleaux.end(); it2++)
            {
                if (ecartDiametre > it.key() - it2.key())
                {
                    _positionDebut = it;
                    ecartDiametre = it.key() - it2.key();
                }
            }
        }
    }
    else {
        for (auto it = lesRouleaux.begin(); it != lesRouleaux.end(); it++)
        {
            int cpt;
            nbRouleauSorti = cpt++;
        }
    }
    return nbRouleauSorti;
}

bool Stock::RetirerRouleauDuStock(const QMultiMap<int,Rouleau>::iterator &_positionRouleau)
{
    bool retour = false;
    if (_positionRouleau != lesRouleaux.end())
    {
        lesRouleaux.erase(_positionRouleau);
        retour = true;
    }
    return retour;
}

QStringList Stock::ObtenirContenuDuStock()
{
    QStringList descriptionStock;
    for (auto it = lesRouleaux.begin(); it != lesRouleaux.end(); it++)
    {
        // QString reference = it.value().getReference();
        // QString diametre = it.value().getDiametre();
        // QString descriptionRetenus = QString("Référence : " + reference + getDiametre()");
        // QString descriptionRouleau = QString("Référence : " + reference);
        // descriptionStock.append(descriptionRouleau);

        QString descriptionRouleau = QString("Référence : %1, Diamètre : %2 ")
                                                    .arg(it.value().getReference())
                                                    .arg(it.value().getDiametre());
        descriptionStock.append(descriptionRouleau);

    }
    return descriptionStock;
}
