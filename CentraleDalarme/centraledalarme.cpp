#include <QDebug>
#include "centraledalarme.h"
#include "clavier.h"



CentraleDalarme::CentraleDalarme(const int _tailleCode, QObject *parent):
    QObject(parent),
    tailleCode(_tailleCode),
    indiceCourant(0)
{
    // Initialisation à compléter
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

void CentraleDalarme::FabriquerCode(const quint8 chiffre)
{
    // Code à compléter
    if(indiceCourant < tailleCode){
        combinaison[indiceCourant]=chiffre;
        indiceCourant++;
    }
    if(indiceCourant == tailleCode){
        qDebug() <<"code complet: ";
        for(int i=0;i<tailleCode;i++){
            qDebug()<<combinaison[i];
        }
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
