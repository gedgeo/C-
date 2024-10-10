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

}


void TestGestionStock::on_pushButtonRetrait_clicked()
{

}


void TestGestionStock::on_pushButtonSuppression_clicked()
{

}

