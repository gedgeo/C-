#include "detecteur.h"
#include "ui_detecteur.h"
#include <QMessageBox>

Detecteur::Detecteur(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Detecteur)
{
    ui->setupUi(this);
}

Detecteur::~Detecteur()
{
    delete ui;
}

void Detecteur::on_pushButtonIntrus_clicked()
{

    QMessageBox messageMarche;
    messageMarche.setText("Présence detecté");
    messageMarche.exec();
}

