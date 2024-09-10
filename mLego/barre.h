#ifndef BARRE_H
#define BARRE_H
#include <string>
#include <iostream>
using namespace std;

class Barre
{
public:
    Barre(const string _reference,const string _nomAlliage,const int _longueur,const float _densite);
    void AfficherCaracteristique();
    double CalculerMasse();

    virtual ~Barre():
    virtual void AfficherCaracteristique();
    virtual void CalculerMasse(){return 0;};

private:
    string reference;
    string nomAlliage;
    int longueur;
    float densite;
    int diametre;
};

#endif // BARRE_H
