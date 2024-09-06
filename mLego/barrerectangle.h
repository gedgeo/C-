#ifndef BARRERECTANGLE_H
#define BARRERECTANGLE_H
#include "barre.h"
#include <iostream>
#include <string>


class BarreRectangle : public Barre
{
public:
    BarreRectangle(string _reference,string _nomAlliage, const unsigned int _longueur,const double _densite,
                   const unsigned int _diametre);

    void AfficherCaracteristique();
    double CalculerSection();
    double CalculerMasse();

protected:

};

#endif // BARRERECTANGLE_H
