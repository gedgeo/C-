#ifndef BARRERECTANGLE_H
#define BARRERECTANGLE_H
#include "barre.h"
#include <iostream>
#include <string>


class BarreRectangle : public Barre
{
public:
    BarreRectangle(string _reference,string _nomAlliage,
                   const unsigned int _longueur,const unsigned int _largeur,const double _densite);

    void AfficherCaracteristique();
    double CalculerMasse();

protected:
    int longueur;
    int largeur;
    double densite;
    string reference;
    string nomAlliage;
};

#endif // BARRERECTANGLE_H
