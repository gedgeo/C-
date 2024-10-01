#ifndef CENTRALEDALARME_H
#define CENTRALEDALARME_H
#include <QObject>
#include <QTimer>


#include "detecteur.h"
#include "detecteurtemporise.h"


class Clavier;


class CentraleDalarme : public QObject
{
public:
    explicit CentraleDalarme(const int _tailleCode = 4,
                             QObject *parent = nullptr);
    ~CentraleDalarme();
    void FabriquerCode(const quint8 chiffre);
    friend QDebug operator<<(QDebug debug, const CentraleDalarme &_centrale);


private slots:
    void onTimerDelai_timeout();


public slots:
    void onIntrusDetecte();

private:
    const int tailleCode;
    quint8 *combinaison;
    int indiceCourant;
    Clavier *leClavier;

};

#endif // CENTRALEDALARME_H
