#include "spliterwidget.h"
#include "ui_spliterwidget.h"
#include "QString"
#include "QStringList"

spliterWidget::spliterWidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::spliterWidget)
{
    ui->setupUi(this);
}

spliterWidget::~spliterWidget()
{
    delete ui;
}

void spliterWidget::on_PushButtonDecoder_clicked()
{
    QString texte=ui->lineEditDecoder->text();
    QStringList liste = texte.split(";");
    ui->lineEditNom->setText(liste.at(0));
    ui->lineEditPrenom->setText(liste.at(1));
    ui->lineEditAge->setText(liste.at(2));
    ui->lineEditTaille->setText(liste.at(3));
    ui->lineEditPoids->setText(liste.at(4));

}

