#include <iostream>
#include "element.h"
#include "trajectoire.h"
#include "segment.h"

using namespace std;

int main()
{
    Trajectoire laTrajectoire(2);

    laTrajectoire.Ajouter(new Segment(9, 0));
    laTrajectoire.Ajouter(new Segment(5, 0.927295));

    laTrajectoire.Afficher();

    return 0;
}
