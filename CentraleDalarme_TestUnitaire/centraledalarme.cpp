#include <QDebug>
#include "centraledalarme.h"
#include "clavier.h"

CentraleDalarme::CentraleDalarme(const int _tailleCode, QObject *parent) :
    QObject(parent),
    tailleCode(_tailleCode),
    indiceCourant(0)
{
    combinaison = new quint8[tailleCode];
    for(int indice = 0 ; indice < tailleCode; indice++)
        combinaison[indice] = 0;

    leClavier = new Clavier(this);
    leClavier->show();
}

CentraleDalarme::~CentraleDalarme()
{
    delete[] combinaison;
    delete leClavier;
}

void CentraleDalarme::FabriquerCode(const quint8 _chiffre)
{
    // Code à compléter
    if (indiceCourant < tailleCode)
        combinaison [indiceCourant++] = _chiffre;
    else
    {
        for (int i=0; i < tailleCode-1; i++)
            combinaison[i]=combinaison[i+1] ;
        combinaison[tailleCode - 1] = _chiffre ;
    }
}

QDebug operator<<(QDebug _debug, const CentraleDalarme &_centrale)
{
    QString tampon = "Combinaison = ";
    for(int i = 0 ; i < _centrale.tailleCode; i++)
        tampon += QString::number(_centrale.combinaison[i]);
    _debug.noquote() << tampon ;
    return _debug.quote();
}
