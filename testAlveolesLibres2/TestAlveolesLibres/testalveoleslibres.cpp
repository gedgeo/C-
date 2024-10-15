#include "testalveoleslibres.h"
#include "ui_testalveoleslibres.h"

TestAlveolesLibres::TestAlveolesLibres(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestAlveolesLibres)
{
    ui->setupUi(this);
    lesAlveoles = new AlveolesLibres(2,3);
}

TestAlveolesLibres::~TestAlveolesLibres()
{
    delete ui;
}

void TestAlveolesLibres::on_pushButtonLiberer_clicked()
{
    QListWidgetItem *currentItem = ui->listWidget->currentItem();
    if (currentItem) {
        QString txt = currentItem->text();
        QStringList parti= txt.split(":");
        if (parti.size() == 2) {
            QStringList position = parti[1].split(",");
            if (position.size()==2) {
                int rangee = position[0].toInt();
                int colonne = position[1].toInt();
                lesAlveoles->Liberer(rangee,colonne);
            }
        }
        delete ui->listWidget->takeItem(ui->listWidget->row(currentItem));
        ui->lineEditEmplacement->setText("libre en :" + parti[1]);
    }




}


void TestAlveolesLibres::on_pushButtonReserver_clicked()
{
    int colonne, rangee;
    if (lesAlveoles->Reserver(rangee,colonne)) {
        QString message = QString("Alvéoles libres en: %1, %2").arg(rangee).arg(colonne);
        ui->listWidget->addItem(message);
        ui->lineEditEmplacement->clear();
    }else{
        QMessageBox plein;
        plein.setText("Il n'y as plus d'avéole libre");
        plein.exec();
    }
}

