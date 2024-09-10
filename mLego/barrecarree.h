#ifndef BARRECARREE_H
#define BARRECARREE_H
#include "barre.h"
#include <iostream>
#include <string>

class BarreCarree:public Barre
{
public:
    BarreCarree(string _reference,string _nomAlliage,
                const unsigned int _longueur,const double _densite);
    void AfficherCaracteristique();
    double CalculerMasse();

protected:
    int longueur;
    double densite;
    string reference;
    string nomAlliage;


};

#endif // BARRECARREE_H
