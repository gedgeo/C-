#ifndef CODE_H
#define CODE_H
#include "centraledalarme.h"

class Code : public CentraleDalarme
{
public:
    Code(int _tailleCode);
    bool verifierCode(const quint8 _unCode);
    void memoriserCode(const quint8 _unCode);

private:
    quint8 codeUsine;
    quint8 codeUtilisateur;
    int tailleCode;
};

#endif // CODE_H
