#ifndef ALVEOLESLIBRES_H
#define ALVEOLESLIBRES_H

#include <QStack>
#include <QDebug>
class AlveolesLibres : public QStack<int>
{
public:
    AlveolesLibres(const int _nbRangees, const int _nbColonnes);
    void Liberer(const int _rangee, const int _colonne);
    bool Reserver(int &_rangee, int &_colonne);


private:
    int nbColonnes;
    int nbRangees;
    QStack<int> pile;

};

#endif // ALVEOLESLIBRES_H
