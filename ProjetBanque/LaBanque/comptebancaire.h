#ifndef COMPTEBANCAIRE_H
#define COMPTEBANCAIRE_H

class CompteBancaire
{
public:
    CompteBancaire(const int _solde=0);
    void Deposer(const float _montant=0);
    bool Retirer(const int _montant=0);
    float ConsulterSolde();



protected:
    float solde;
};

#endif // COMPTEBANCAIRE_H
