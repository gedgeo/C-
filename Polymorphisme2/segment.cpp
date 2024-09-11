#include "segment.h"

Segment::Segment(const double _longueur, const double _angle):
    longueur(_longueur),
    angle(_angle)
{

}

void Segment::afficher()
{
    cout << " SEGMENT l =" << longueur<< "  |  "<<"A = "<< angle <<endl;
}
