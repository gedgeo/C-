#include "interfacesprincipale.h"
#include "ui_interfacesprincipale.h"

InterfacesPrincipale::InterfacesPrincipale(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InterfacesPrincipale)
    , configGPS(lePort)
{
    ui->setupUi(this);
}

InterfacesPrincipale::~InterfacesPrincipale()
{
    delete ui;
}

void InterfacesPrincipale::on_actionConfigurer_triggered()
{
    configGPS.exec();
}

