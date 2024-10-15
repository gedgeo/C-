#ifndef ROULEAU_H
#define ROULEAU_H

#include <QString>

class Rouleau
{
public:
    Rouleau();
    Rouleau(const Rouleau &_autre);
    Rouleau(const QString _reference, const int _diametre);
    Rouleau &operator=(const Rouleau &_autre);
    ~Rouleau();
    void AffecterLocalisation(const int _rangee, const int _colonne);
    void ObtenirLocalisation(int &_rangee, int &_colonne);
    QString getReference() const;
    int getDiametre() const;


private:
    QString reference;
    int diametre;
    int rangee;
    int colonne;
};

#endif // ROULEAU_H
