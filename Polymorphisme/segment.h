#ifndef SEGMENT_H
#define SEGMENT_H
#include "element.h"
#include <iostream>
#include <iomanip>

using namespace std;

class Segment : public Element
{
public:
    Segment(const double _longueur,const double _angle );
    virtual void Afficher();

protected:
    double longueur;
    double angle;

};

#endif // SEGMENT_H
