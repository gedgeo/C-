#ifndef COMPTEEPARGNE_H
#define COMPTEEPARGNE_H
#include <comptebancaire.h>

class CompteEpargne : public CompteBancaire
{
public:
    CompteEpargne(const float _tauxInterets,const float _solde=0);
    void CalculerInterets();
    void ModifierTaux(const float _nouveauTaux);



protected:
    float tauxInterets;

};

#endif // COMPTEEPARGNE_H
