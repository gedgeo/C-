#include "alveoleslibres.h"

AlveolesLibres::AlveolesLibres(const int _nbRangees, const int _nbColonnes):
    nbRangees(_nbRangees),nbColonnes(_nbColonnes)
{
    for(int r = 0;r < nbRangees;r++){
        for(int c = 0; c< nbColonnes;c++){
            alveoles.push(positionA(r, c));
        }
    }
}


bool AlveolesLibres::Reserver(int &rangee, int &colonne)
{
    if(!alveoles.isEmpty()){
        int i = alveoles.pop();
        aPosition(i,rangee,colonne);
        qDebug()<<"Alveoles reserver a ("<< rangee <<","<<colonne <<")";
        return true;
    }else{
        qDebug()<<"aucune alveole n'est reservable";
        return false;
    }
}

void AlveolesLibres::Liberer(int rangee, int colonne)
{
    int i = positionA(rangee,colonne);
    alveoles.push(i);
    qDebug()<<"alveole liberer a ("<<rangee<<","<<colonne<<")";
}

int AlveolesLibres::positionA(int rangee, int colonne)
{
    return rangee * nbColonnes + colonne;
}

void AlveolesLibres::aPosition(int i, int &rangee, int &colonne)
{
    rangee = i /nbColonnes;
    colonne =i % nbColonnes;
}
