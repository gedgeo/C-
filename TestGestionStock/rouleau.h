#ifndef ROULEAU_H
#define ROULEAU_H

#include <QString>

class Rouleau
{
public:
    Rouleau();
    Rouleau(const Rouleau & _autre);
    Rouleau(const QString& _reference, int _diametre);
    ~Rouleau();
    QString getReference() const;
    int getDiametre() const;
    void AffecterLocalisation(int _rangee, int _colonne);
    void ObtenirLocalisation(int& _rangee, int& _colonne) const;


private:
    QString reference;
    int diametre;
    int rangee;
    int colonne;
};

#endif // ROULEAU_H
