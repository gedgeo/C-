#include "testgestionstock.h"
#include "ui_testgestionstock.h"

#include <QMessageBox>
#include <QDebug>

TestGestionStock::TestGestionStock(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestGestionStock)
    , alveolesLibres(3,3)
{
    ui->setupUi(this);
}

TestGestionStock::~TestGestionStock()
{
    delete ui;
}

void TestGestionStock::on_pushButtonNouveau_clicked()
{
    QString reference = ui->lineEditRef->text();
    int diametre = ui->lineEditDiametre->text().toInt();

    if (!reference.isEmpty() && diametre > 0) {
        Rouleau nouveauRouleau(reference, diametre);

        int rangee, colonne;
        if (alveolesLibres.Reserver(rangee, colonne)) {
            nouveauRouleau.AffecterLocalisation(rangee, colonne);
            stock.AjouterRouleau(nouveauRouleau);
            Chariot chariot;
            chariot.DeplacerVers(rangee, colonne, true);

            afficherStock();

            ui->lineEditRef->clear();
            ui->lineEditDiametre->clear();
        }
        else {
            QMessageBox::warning(this, "Erreur", "Plus d'alvéoles libres disponibles.");
        }
    }
    else {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une référence et un diamètre valides.");
    }
}

void TestGestionStock::on_pushButtonRetrait_clicked()
{
    QList<QMultiMap<int, Rouleau>::iterator> rouleauxASortir = stock.RechercherSerie();

    if (!rouleauxASortir.isEmpty())
    {
        QList<Rouleau> rouleauxToProcess;
        QList<QPair<int, int>> locations;

        for (auto it = rouleauxASortir.begin(); it != rouleauxASortir.end(); ++it)
        {
            Rouleau rouleau = it->value();
            int rangee, colonne;
            rouleau.ObtenirLocalisation(rangee, colonne);
            rouleauxToProcess.append(rouleau);
            locations.append(qMakePair(rangee, colonne));
        }

        for (const auto& it : rouleauxASortir)
        {
            stock.RetirerRouleauDuStock(it);
        }

        for (int i = 0; i < rouleauxToProcess.size(); ++i)
        {
            const Rouleau& rouleau = rouleauxToProcess[i];
            int rangee = locations[i].first;
            int colonne = locations[i].second;
            Chariot chariot;

            chariot.DeplacerVers(rangee, colonne, false);

            alveolesLibres.Liberer(rangee, colonne);

            rouleauxEnceinte.append(rouleau);
        }

        afficherStock();
        afficherRouleauEnceinte();
    }
    else
    {
        QMessageBox::information(this, "Information", "Aucun rouleau disponible pour le retraitement.");
    }
}

void TestGestionStock::on_pushButtonSuppression_clicked()
{
    if (!rouleauxEnceinte.isEmpty())
    {
        rouleauxEnceinte.clear();

        afficherRouleauEnceinte();
    }
    else
    {
        QMessageBox::information(this, "Information", "Aucun rouleau dans l'enceinte à supprimer.");
    }
}


void TestGestionStock::afficherStock()
{
    ui->listWidgetStock->clear();
    QStringList contenuStock = stock.ObtenirContenuDuStock();
    ui->listWidgetStock->addItems(contenuStock);
}

void TestGestionStock::afficherRouleauEnceinte()
{
    ui->listWidgetRetenus->clear();
    for (const Rouleau& rouleau : rouleauxEnceinte)
    {
        QString itemText = QString("Rouleau: %1, Diamètre: %2").arg(rouleau.getReference()).arg(rouleau.getDiametre());
        ui->listWidgetRetenus->addItem(itemText);
    }
}
