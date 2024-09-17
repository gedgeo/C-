#include "calculatrice.h"
#include "ui_calculatrice.h"
#include <QJSEngine>

calculatrice::calculatrice(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::calculatrice)
{
    ui->setupUi(this);
}

calculatrice::~calculatrice()
{
    delete ui;
}

void calculatrice::on_pushButton0_clicked()
{
    QString texte = ui->pushButton0->text();
    QString expression = ui->lineEdit->text() + texte;
    ui->lineEdit->setText(expression);
}



void calculatrice::on_pushButton1_clicked()
{
    QString texte = ui->pushButton1->text();
    QString expression = ui->lineEdit->text() + texte;
    ui->lineEdit->setText(expression);
}


void calculatrice::on_pushButton2_clicked()
{
    QString texte = ui->pushButton2->text();
    QString expression = ui->lineEdit->text() + texte;
    ui->lineEdit->setText(expression);
}


void calculatrice::on_pushButton3_clicked()
{
    QString texte = ui->pushButton3->text();
    QString expression = ui->lineEdit->text() + texte;
    ui->lineEdit->setText(expression);
}


void calculatrice::on_pushButton4_clicked()
{
    QString texte = ui->pushButton4->text();
    QString expression = ui->lineEdit->text() + texte;
    ui->lineEdit->setText(expression);
}


void calculatrice::on_pushButton5_clicked()
{
    QString texte = ui->pushButton5->text();
    QString expression = ui->lineEdit->text() + texte;
    ui->lineEdit->setText(expression);
}


void calculatrice::on_pushButton6_clicked()
{
    QString texte = ui->pushButton6->text();
    QString expression = ui->lineEdit->text() + texte;
    ui->lineEdit->setText(expression);
}


void calculatrice::on_pushButton7_clicked()
{
    QString texte = ui->pushButton7->text();
    QString expression = ui->lineEdit->text() + texte;
    ui->lineEdit->setText(expression);
}


void calculatrice::on_pushButton8_clicked()
{
    QString texte = ui->pushButton8->text();
    QString expression = ui->lineEdit->text() + texte;
    ui->lineEdit->setText(expression);
}


void calculatrice::on_pushButton9_clicked()
{
    QString texte = ui->pushButton9->text();
    QString expression = ui->lineEdit->text() + texte;
    ui->lineEdit->setText(expression);
}


void calculatrice::on_pushButtonAdditionner_clicked()
{
    QString texte = ui->pushButtonAdditionner->text();
    QString expression = ui->lineEdit->text() + texte;
    ui->lineEdit->setText(expression);
}


void calculatrice::on_pushButtonSoustraire_clicked()
{
    QString texte = ui->pushButtonSoustraire->text();
    QString expression = ui->lineEdit->text() + texte;
    ui->lineEdit->setText(expression);
}


void calculatrice::on_pushButtonMultiplier_clicked()
{
    QString texte = ui->pushButtonMultiplier->text();
    QString expression = ui->lineEdit->text() + texte;
    ui->lineEdit->setText(expression);
}


void calculatrice::on_pushButtonDiviser_clicked()
{
    QString texte = ui->pushButtonDiviser->text();
    QString expression = ui->lineEdit->text() + texte;
    ui->lineEdit->setText(expression);
}


void calculatrice::on_pushButtonEgal_clicked()
{
    QJSEngine myEngine;
    QJSValue three = myEngine.evaluate(ui->lineEdit->text());
    ui->lineEdit->setText(three.toString());
}



void calculatrice::on_pushButtonEffacer_clicked()
{
    ui->lineEdit->clear();
}

