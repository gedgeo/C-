#include "chariot.h"
#include <QDebug>
#include <QMessageBox>

Chariot::Chariot() {}


void Chariot::DeplacerVers(const int rangee, const int colonne, const bool sens)
{
    QString sensText = sens ? "ENTREE" : "SORTIE";
    QString message = QString("Chariot se déplace vers l'alvéole (%1, %2) pour une %3")
                          .arg(rangee)
                          .arg(colonne)
                          .arg(sensText);
    QMessageBox::information(nullptr, "Information", message);
}
