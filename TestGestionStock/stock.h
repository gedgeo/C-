#ifndef STOCK_H
#define STOCK_H

#include <QMultiMap>
#include <QStringList>
#include "rouleau.h"

class Stock
{
public:
    Stock();

    void AjouterRouleau(const Rouleau _nouveau);
    int RechercherSerie(QMultiMap<int, Rouleau>::iterator,int positionDebut);
    bool RetirerRouleauDuStock(QMultiMap<int, Rouleau>::iterator positionRouleau);
    QStringList ObtenirContenuDuStock() const;

private:
    QMultiMap<int, Rouleau> lesRouleaux;
};

#endif // STOCK_H
