#ifndef COMPTECLIENT_H
#define COMPTECLIENT_H
#include <string>
#include "comptebancaire.h"
#include "compteepargne.h"

class CompteClient : public CompteBancaire
{
public:
    CompteClient(char _nom, int numero);

    void OuvrirCompteEpargne();
    void GererCompteBancaire();
    void GererCompteEpargne();

private:
    char nom;
    int numero;
    float solde;
};

#endif // COMPTECLIENT_H
