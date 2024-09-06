#include "comptebancaire.h"
#include <iostream>
#include <iomanip>
#include <string>

CompteBancaire::CompteBancaire(const int _solde) :
    solde(_solde)
{

}

void CompteBancaire::Deposer(const float _montant)
{
    solde += _montant;
}

bool CompteBancaire::Retirer(const int _montant)
{
    bool retour = false;
    if(solde >= _montant)
    {
        solde -= _montant;
        retour= true;
    }

}

float CompteBancaire::ConsulterSolde()
{
    return solde;
}




