#include <iostream>
#include <string>
#include "barre.h"
#include "barreronde.h"

using namespace std;

int main()
{
    Barre uneBarre("B154","laiton",73,8.73);
    BarreRonde uneBarreRonde("BR205","laiton",5,8.7,45);
    uneBarre.AfficherCaracteristique();
    uneBarreRonde.AfficherCaracteristique();
    return 0;
}
