#ifndef TRAJECTOIRE_H
#define TRAJECTOIRE_H
#include "element.h"
#include <iostream>
#include <string>
#include <iomanip>


using namespace std;


class Trajectoire
{
public:
    Trajectoire(const int _nbEtapesMaxi);
    ~Trajectoire();
    bool ajouter(Element *_pElement);
    void Afficher();



protected:
    Element **parcours;
    int nbEtapesMax;
    int prochaineEtape;
};

#endif // TRAJECTOIRE_H
