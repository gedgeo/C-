#include "barrerectangle.h"
#include <iostream>
#include <string>
#include <math.h>

BarreRectangle::BarreRectangle(string _reference,
                               string _nomAlliage,
                               const unsigned int _longueur,
                               const unsigned int _largeur,
                               const double _densite):
    Barre (_reference,_nomAlliage,_longueur,_densite),
    largeur (_largeur)
{

}

void BarreRectangle::AfficherCaracteristique()
{
    Barre::AfficherCaracteristique();
    cout << "poid de la barre : " <<CalculerMasse() /1000.0 << "Kg" <<endl;
    cout << "-------------------" <<endl;
}

double BarreRectangle::CalculerMasse()
{
    return ( longueur * largeur )* densite;
}
