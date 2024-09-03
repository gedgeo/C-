#ifndef EMBALLAGE_H
#define EMBALLAGE_H
#include <string>
using namespace std;
#include <iostream>

class Emballage
{
public:
    Emballage(const string _format, const int _resistance, const int _largeur, const int _longueur, const int _hauteur=0);
    ~Emballage();

    void Visualiser();
    bool operator < (const Emballage &autre);
    bool operator == (Emballage &autre);
    operator float();
    double CalculerVolume();


private:
    string format;
    int resistance;
    int largeur;
    int longueur;
    int hauteur;
    int stock;
};



#endif // EMBALLAGE_H
