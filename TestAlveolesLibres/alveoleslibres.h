#ifndef ALVEOLESLIBRES_H
#define ALVEOLESLIBRES_H
#include <QStack>

class AlveolesLibres:public QStack
{
public:
    AlveolesLibres(const int _nbRangees,const int _nbColonnes);
    bool Reserver();


private:
    int nbRangees;
    int nbColonnes;
};

#endif // ALVEOLESLIBRES_H
