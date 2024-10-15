#include "alveoleslibres.h"

AlveolesLibres::AlveolesLibres(const int _nbRangees, const int _nbColonnes):
    nbColonnes(_nbColonnes),
    nbRangees(_nbRangees)
{

    reserve(nbColonnes*nbRangees);
    for (int i = 1 ; i <= nbColonnes*nbRangees; ++i) {
        push(i);

    }
    qDebug() << "Dans le constructeur : "<< *this;
}

void AlveolesLibres::Liberer(const int _rangee, const int _colonne)
{
    int numAlveole = _colonne + nbColonnes*(_rangee - 1);
    push(numAlveole);
    qDebug() << "Dans la fonction Libérer() : "<< *this;
}

bool AlveolesLibres::Reserver(int &_rangee, int &_colonne)
{

    bool retour =  false;
    int numAlveole = 0;
    if (!isEmpty()) {
        numAlveole = pop();
        _rangee = (numAlveole - 1)/nbColonnes + 1;
        _colonne= (numAlveole - 1)%nbColonnes + 1;
        retour = true;
    }
    qDebug() << "Dans la fonction Réserver() : "<< *this;
    return retour;


}
