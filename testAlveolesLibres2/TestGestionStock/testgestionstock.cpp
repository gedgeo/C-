#include "testgestionstock.h"
#include "ui_testgestionstock.h"

TestGestionStock::TestGestionStock(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestGestionStock)
{
    ui->setupUi(this);
}

TestGestionStock::~TestGestionStock()
{
    delete ui;
}

void TestGestionStock::on_pushButtonNouveau_clicked()
{
    int diametre = ui->lineEditDiametre->text().toInt();
    QString reference = ui->lineEditReference->text();
    leStock.AjouterRouleau(Rouleau(reference, diametre));
    QStringList stock = leStock.ObtenirContenuDuStock();
    ui->listWidgetStock->clear();
    ui->listWidgetStock->addItems(stock);
}


void TestGestionStock::on_pushButtonRetrait_clicked()
{
    int diametre = ui->lineEditDiametre->text().toInt();
    QString reference = ui->lineEditReference->text();
    nbRouleau = leStock.RechercherSerie(debut);
    auto memo = debut;

    ui->listWidgetRouleauxRetenus->clear();
    for (int var = 0; var < nbRouleau; ++var) {
        QString texte = QString("Référence : %1, Diamètre : %2 ")
                            .arg(memo.value().getReference())
                            .arg(memo.value().getDiametre());
        ui->listWidgetRouleauxRetenus->addItem(texte);
        memo++;
    }
}


void TestGestionStock::on_pushButtonSuppression_clicked()
{
    ui->listWidgetRouleauxRetenus->clear();
    for (int var = 0; var < nbRouleau; ++var) {
        auto memo = debut;
        memo++;
        leStock.RetirerRouleauDuStock(debut);
        debut = memo;
    }
    QStringList stock = leStock.ObtenirContenuDuStock();

    ui->listWidgetStock->clear();
    ui->listWidgetStock->addItems(stock);

}

