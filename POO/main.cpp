#include "emballage.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
    Emballage colis("XS",1,270,190);
    Emballage *pColis;
    Emballage *tabColis[8];

    string format;
    int resistance;
    int largeur;
    int longueur;
    int hauteur;

    for(int var = 0; var < 2; ++var){
        cout << "nom du format : ";
        getline(cin ,format);
        cout << "largeur : ";
        cin >>largeur;
        cout << "longueur : ";
        cin >>longueur;
        cout << "hauteur : ";
        cin >>hauteur;
        cout << "resistance Max : ";
        cin >>resistance;

        cin.ignore(numeric_limits<streamsize>:: max(),'\n' );
        tabColis[var] = new Emballage(format,resistance,largeur,longueur,hauteur);
    }

    for(int indice = 0; indice <2; ++indice ){
        tabColis[indice]->Visualiser();
    }

    if(*tabColis[0] < *tabColis[1])
        cout <<"tabColis[0] est plus petit que tabCollis[1]" <<endl;
    else
        cout <<"tabColis[1] est plus petit que tabCollis[0]" <<endl;

    return 0;
}

