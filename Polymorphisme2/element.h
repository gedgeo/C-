#ifndef ELEMENT_H
#define ELEMENT_H
#include "vecteur.h"


using namespace std;

class Element
{
public:
    Element(const int _vitesse=1);
    virtual ~Element();
    virtual void Afficher() = 0;
    virtual int ObtenirLongueur()=0;
    virtual int ObtenirDuree()=0;
    virtual Vecteur ObtenirVecteur()=0;

    double getNumero()const;
    void setNumero(const double _numero);

protected:
    int numero;
    int vitesse;
};

#endif // ELEMENT_H
