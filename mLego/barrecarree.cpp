#include "barrecarree.h"
#include <iostream>
#include <string>
#include <math.h>



BarreCarree::BarreCarree(string _reference, string _nomAlliage,
                         const unsigned int _longueur,
                         const double _densite):
    Barre (_reference,_nomAlliage,_longueur,_densite)
{

}

void BarreCarree::AfficherCaracteristique()
{
    Barre::AfficherCaracteristique();
    cout << "poid de la barre : " <<CalculerMasse() /1000.0 << "Kg" <<endl;
    cout << "-------------------" <<endl;
}

double BarreCarree::CalculerMasse()
{
    return ( longueur * 4 )* densite;
}
