#include "rouleau.h"

Rouleau::Rouleau(const QString& _reference, const int _diametre)
{

}

Rouleau::~Rouleau()
{

}

QString Rouleau::getReference() const
{
    return reference;
}

int Rouleau::getDiametre() const
{
    return diametre;
}

void Rouleau::AffecterLocalisation(const int _rangee, const int _colonne)
{
    rangee = _rangee;
    colonne = _colonne;
}

void Rouleau::ObtenirLocalisation(int &_rangee, int &_colonne)
{
    _rangee = rangee;
    _colonne = colonne;
}

