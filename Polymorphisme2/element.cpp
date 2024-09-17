#include "element.h"
#include <iostream>
#include <string>



Element::Element(const int _vitesse)
{

}

Element::~Element()
{

}

double Element::getNumero() const
{
    return numero;
}

void Element::setNumero(const double _numero)
{
    numero = _numero;
}
