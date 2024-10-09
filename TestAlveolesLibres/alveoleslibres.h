#ifndef ALVEOLESLIBRES_H
#define ALVEOLESLIBRES_H
#include <QStack>
#include <QDebug>

class AlveolesLibres:public QStack<int>
{
public:
    AlveolesLibres(const int _nbRangees,const int _nbColonnes);
    bool Reserver(int& rangee,int& colonne);
    void Liberer(int rangee,int colonne);

    int  positionA(int rangee,int colonne);
    void aPosition(int i,int& rangee,int& colonne);

private:
    int nbRangees;
    int nbColonnes;
    QStack<int>alveoles;


} ;

#endif // ALVEOLESLIBRES_H
