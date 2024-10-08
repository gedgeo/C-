#include "testalveoleslibre.h"
#include "ui_testalveoleslibre.h"

TestAlveolesLibre::TestAlveolesLibre(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestAlveolesLibre)
{
    ui->setupUi(this);
}

TestAlveolesLibre::~TestAlveolesLibre()
{
    delete ui;
}

void TestAlveolesLibre::on_pushButtonLiberer_clicked()
{

}


void TestAlveolesLibre::on_pushButtonReserver_clicked()
{

}

