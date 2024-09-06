#ifndef CATALOGUE_H
#define CATALOGUE_H
#include "barre.h"

class Catalogue
{
public:
    Catalogue(const int _nbBarres);
    ~Catalogue();
    bool AjouterBarre(Barre *ptrBarre);
    void AfficherCatalogue();

private:
    Barre **lesBarres; // pour la création d’un tableau de pointeurs de barre
    int index; // index de la prochaine case libre du tableau
    const int nbBarres; // nombre maxi de barres dans le tableau
};

#endif // CATALOGUE_H
