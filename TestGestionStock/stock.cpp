#include "stock.h"
#include <QString>
#include <math.h>

Stock::Stock() {}

void Stock::AjouterRouleau(const Rouleau _nouveau)
{
    lesRouleaux.insert(_nouveau.getDiametre(), _nouveau);
}

QList<QMultiMap<int, Rouleau>::iterator> Stock::RechercherSerie()
{
    QList<QMultiMap<int, Rouleau>::iterator> result;

    const int rouleauxRequis = 6;
    int nbRouleauxDisponibles = lesRouleaux.size();

    if (nbRouleauxDisponibles == 0)
        return result;

    QList<QMultiMap<int, Rouleau>::iterator> iterators;
    for (auto it = lesRouleaux.begin(); it != lesRouleaux.end(); ++it)
    {
        iterators.append(it);
    }

    int N = iterators.size();
    int minDifference = std::numeric_limits<int>::max();
    int bestStartIndex = -1;
    int seriesLength = qMin(rouleauxRequis, N);

    for (int i = 0; i <= N - seriesLength; ++i)
    {
        int minDiameter = iterators[i].key();
        int maxDiameter = iterators[i + seriesLength - 1].key();

        int difference = maxDiameter - minDiameter;

        if (difference < minDifference)
        {
            minDifference = difference;
            bestStartIndex = i;
        }
    }

    if (bestStartIndex != -1)
    {
        for (int i = bestStartIndex; i < bestStartIndex + seriesLength; ++i)
        {
            result.append(iterators[i]);
        }
    }
    else
    {
        for (int i = 0; i < seriesLength; ++i)
        {
            result.append(iterators[i]);
        }
    }

    return result;
}

bool Stock::RetirerRouleauDuStock(QMultiMap<int, Rouleau>::iterator position)
{
    if(position != lesRouleaux.end()){
        lesRouleaux.erase(position);
        return true;
    }
    return false;
}

QStringList Stock::ObtenirContenuDuStock() const
{
    QStringList contenu;
    for (auto it = lesRouleaux.begin(); it != lesRouleaux.end(); it++)
    {
        contenu << QString("Rouleau: %1, Diamètre: %2").arg(it.value().getReference()).arg(it.key());

    }
    return contenu;
}
