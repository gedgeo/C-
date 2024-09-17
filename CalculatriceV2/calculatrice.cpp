#include "calculatrice.h"
#include "ui_calculatrice.h"
#include <QJSEngine>
#include <QMessageBox>


Calculatrice::Calculatrice(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculatrice)
{
    ui->setupUi(this);
}

Calculatrice::~Calculatrice()
{
    delete ui;
}

void Calculatrice::onQPushButtonClicked()
{
    QObject *senderObject = sender();
    QPushButton *touche = qobject_cast<QPushButton*>(senderObject);
    if (touche) {
        QString buttonText = touche->text();
        QLineEdit->setText(QLineEdit->text() + buttonText);
    } else {
        QLineEdit->setText("Erreur");
    }
}


void Calculatrice::on_pushButtonEgal_clicked()
{
    QJSEngine myEngine;
    QJSValue three = myEngine.evaluate(ui->lineEdit->text());
    ui->lineEdit->setText(three.toString());
}


void Calculatrice::on_pushButtonEffacer_clicked()
{
    ui->lineEdit->clear();
}

