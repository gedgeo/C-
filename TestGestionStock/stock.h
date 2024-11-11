#ifndef STOCK_H
#define STOCK_H

#include <QList>
#include <QMultiMap>
#include <QStringList>
#include "rouleau.h"

class Stock
{
public:
    Stock();
    void AjouterRouleau(const Rouleau _nouveau);

    QList<QMultiMap<int,Rouleau>::iterator> RechercherSerie();

    bool RetirerRouleauDuStock(QMultiMap<int, Rouleau>::iterator position);

    QStringList ObtenirContenuDuStock() const;

private:
    QMultiMap<int, Rouleau> lesRouleaux;
};

#endif // STOCK_H
