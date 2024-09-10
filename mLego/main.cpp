#include <iostream>
#include <string>
#include "barre.h"
#include "barreronde.h"
#include "barrecarree.h"
#include "barrerectangle.h"
#include "catalogue.h"

using namespace std;

int main()
{
    Catalogue lesBarres(7);
    lesBarres.AfficherCatalogue();



    /**
    Barre uneBarre("B154","laiton",73,8.73);
    BarreRonde uneBarreRonde("BR205","laiton",5,8.7,45);
    BarreCarree uneBarreCarre("BT451","laiton",73,87);
    BarreRectangle uneBarreRectangulaire("BR891","laiton",54,87,12);
    uneBarre.AfficherCaracteristique();
    uneBarreRonde.AfficherCaracteristique();
    uneBarreCarre.AfficherCaracteristique();
    uneBarreRectangulaire.AfficherCaracteristique();
**/
    return 0;
}
