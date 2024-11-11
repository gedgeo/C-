#include <iostream>
#include "element.h"
#include "trajectoier.h"
#include "segment.h"

using namespace std;

int main()
{
    Trajectoire laTrajecctoire(2);
    laTrajecctoire.ajouter(new Segment(9,0));
    laTrajecctoire.ajouter(new Segment(5, 0.927295));

    laTrajecctoire.Afficher();

    return 0;
}
