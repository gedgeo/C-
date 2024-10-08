#include "code.h"

Code::Code(const int _tailleCode) {

    for (int i = 0; i < 4; ++i) {
        codeUsine[i] = i + 1;
        codeUtilisateur[i] = (i + 1) * 2;
    }

}

Code::~Code()
{

}

bool Code::VerifierCode(quint8* unCode)
{
    bool test = true;

    for (int i = 0; i < TAILLE_CODE && test; i++) {
        if (unCode[i] != codeUtilisateur[i] && unCode[i] != codeUsine[i])
            test = false;
    }
    return test;
}

void Code::MemoriserCode(quint8* nouveauCode)
{
    for (int i = 0; i < TAILLE_CODE; i++)
        codeUtilisateur[i] = nouveauCode[i];
}
