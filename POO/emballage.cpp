#include "emballage.h"
#include <iostream>
#include <iomanip>
#include <string>

Emballage::Emballage(const string _format,const int _resistance,const int _largeur,const int _longueur,const int _hauteur) {
        format = _format;
        resistance = _resistance;
        largeur = _largeur;
        longueur = _longueur;
        hauteur = _hauteur;

        //cout <<"constructeur : Emballage / "<< format << endl;
        //cout <<"constructeur : Emballage / "<< format << endl;
}

Emballage::~Emballage()
{
cout <<"desstructeur : Emballage detruit "<< endl;
}

void Emballage::Visualiser(){
    cout << "|" ;
    cout << setw (15) << left << format;
    cout << "|";
    cout << left << resistance << "kg" << setw(9);
    cout << right << "|";
    cout << setw(3) << longueur << "X" <<setw(3) << largeur;
    if (hauteur > 0)
        cout << "X" << setw(3) << hauteur;
    else cout << setw(6) << "";
    cout << "|" << endl;
}

bool Emballage::operator <(const Emballage &autre)
{
    return(longueur == autre.longueur && largeur == autre.largeur &&
            hauteur == autre.hauteur && resistance == autre.resistance);
}


double Emballage::CalculerVolume()
{
    int volume = largeur * longueur;
    if(hauteur>0)
        volume *= hauteur;

    double volumeCm3 = volume / 1000.0 ;

    return volumeCm3;
}

Emballage::operator float()
{
    return 0;
}



