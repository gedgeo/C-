#include "compteepargne.h"
#include <iostream>
#include <iomanip>
#include <string>


CompteEpargne::CompteEpargne(const float _tauxInterets, const float _solde) :
    CompteBancaire(_solde),
    tauxInterets(_tauxInterets)
{

}

void CompteEpargne::CalculerInterets()
{
    float interets = solde * tauxInterets /100.0 ;
    solde += interets;

}


void CompteEpargne::ModifierTaux(const float _nouveauTaux)
{

}
