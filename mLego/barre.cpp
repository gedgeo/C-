#include "barre.h"
#include <iostream>
#include <string>
#include <math.h>


Barre::Barre(const string _reference, const string _nomAlliage,const int _longueur, const float _densite):
    reference (_reference),
    nomAlliage (_nomAlliage),
    longueur (_longueur),
    densite (_densite)
{

}

void Barre::AfficherCaracteristique()
{
    cout << "reference de la barre : " << reference << endl;
    cout << "nom de l'alliage : " << nomAlliage << "densiter de l'alliage : "<<densite << endl;
    cout << "longueur de la barre : "<< longueur << endl;
    cout << "-------------" << endl;

}

double Barre::CalculerMasse()
{

}
