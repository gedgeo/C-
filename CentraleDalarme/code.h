#ifndef CODE_H
#define CODE_H
#include "centraledalarme.h"

#include <QObject>

#define TAILLE_CODE 4

class Code
{
public:
    Code(const int _tailleCode);
    ~Code();
    bool VerifierCode(quint8 *unCode);
    void MemoriserCode(quint8 *nouveauCode);

private:
    quint8 codeUsine[TAILLE_CODE];
    quint8 codeUtilisateur[TAILLE_CODE];
};

#endif // CODE_H
