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
    int RechercherSerie(QMultiMap<int,Rouleau>::iterator &_positionDebut);
    bool RetirerRouleauDuStock(const QMultiMap<int,Rouleau>::iterator &_positionRouleau);
    QStringList ObtenirContenuDuStock();

private:
    QMultiMap<int,Rouleau> lesRouleaux;

};

#endif // STOCK_H
