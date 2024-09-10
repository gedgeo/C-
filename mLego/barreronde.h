#ifndef BARRERONDE_H
#define BARRERONDE_H
#include "barre.h"
#include <iostream>
#include <string>


class BarreRonde : public Barre
{
public:
    BarreRonde(string _reference,string _nomAlliage,
               const unsigned int _longueur,
               const double _densite,
               const unsigned int _diametre);

    void AfficherCaracteristique();
    double CalculerSection();
    double CalculerMasse();

protected:
    int longueur;
    double densite;
    string reference;
    string nomAlliage;
    int diametre;
};

#endif // BARRERONDE_H
