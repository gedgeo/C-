#include "calculatrice.h"
#include "ui_calculatrice.h"
#include <QJSEngine>
#include <QMessageBox>


Calculatrice::Calculatrice(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculatrice)
{
    ui->setupUi(this);

    QList<QPushButton*> allButtons = this->findChildren<QPushButton*>();
    foreach(QPushButton* button, allButtons) {
        if(button->text() != "=" && button->text() != "C") {
            connect(button, &QPushButton::clicked, this, &Calculatrice::onQPushButtonClicked);
        }
    }
}

Calculatrice::~Calculatrice()
{
    delete ui;
}

void Calculatrice::onQPushButtonClicked()
{
    QPushButton *touche;
    touche=qobject_cast<QPushButton*>(sender());
    QString expression = ui->lineEdit->text();
    ui->lineEdit->setText(expression + touche->text());
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

