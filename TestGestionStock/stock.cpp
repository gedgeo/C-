#include "stock.h"

Stock::Stock() {}

void Stock::AjouterRouleau(const Rouleau _nouveau)
{
    lesRouleaux.insert()
}

int Stock::RechercherSerie(QMultiMap::iterator, int positionDebut)
{

}

bool Stock::RetirerRouleauDuStock(QMultiMap::iterator positionRouleau)
{
    bool retour =false;
    if(_positionRouleau != lesRouleaux.end())
    {
        lesRouleaux.erase()
    }
}

QStringList Stock::ObtenirContenuDuStock() const
{
    QString descriptionsStock;
    for(auto it = lesRouleaux.begin();it != lesRouleaux.end();i++)
    {
        QString reference =it.value().getReference();
        QString descriptionsStock
    }
}
