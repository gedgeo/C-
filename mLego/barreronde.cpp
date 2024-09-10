#include "barreronde.h"
#include <iostream>
#include <string>
#include <math.h>


BarreRonde::BarreRonde(string _reference, string _nomAlliage,
                       const unsigned int _longueur,
                       const double _densite,
                       const unsigned int _diametre):
    Barre (_reference,_nomAlliage,_longueur,_densite),
    diametre (_diametre)
{

}

void BarreRonde::AfficherCaracteristique()
{
    Barre::AfficherCaracteristique();
    cout << "diametre : " << diametre << endl;
    cout << "poid de la barre : " <<CalculerMasse() /1000.0 << "Kg" <<endl;
    cout << "-------------------" <<endl;
}

double BarreRonde::CalculerSection()
{
    return (M_PI * (diametre * diametre)/4);
}

double BarreRonde::CalculerMasse()
{
    return CalculerSection()* longueur * densite;
}
