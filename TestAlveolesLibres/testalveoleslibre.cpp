#include "testalveoleslibre.h"
#include "ui_testalveoleslibre.h"

TestAlveolesLibre::TestAlveolesLibre(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestAlveolesLibre)
    ,lesAlveoles(new AlveolesLibres(2,3))
{
    ui->setupUi(this);
}

TestAlveolesLibre::~TestAlveolesLibre()
{
    delete ui;
}

void TestAlveolesLibre::on_pushButtonLiberer_clicked()
{
    QListWidgetItem* item = ui->listWidgetAlveolesLibres->currentItem();
    if(item != nullptr){
        QString texteAlveole = item->text();
        QStringList coordonnees = texteAlveole.split(",");
        int rangee = coordonnees[0].split(":")[1].trimmed().toInt();
        int colonne = coordonnees[1].split(":")[1].trimmed().toInt();
        lesAlveoles->Liberer(rangee, colonne);
        qDebug() << "L'alvéole à la rangée " << rangee << " et colonne " << colonne << " a été libérée.";
        delete item;
    } else {
        qDebug() << "Aucune alvéole sélectionnée pour libération.";
    }

}


void TestAlveolesLibre::on_pushButtonReserver_clicked()
{
    int rangee;
    int colonne;

    if(lesAlveoles->Reserver(rangee,colonne)){
        QString coordonnees = QString("Rangée: %1, Colonne: %2").arg(rangee).arg(colonne);
        ui->listWidgetAlveolesLibres->addItem(coordonnees);
        ui->lineEditNumAlveole->setText(coordonnees);
        qDebug()<<"Alveole reserver";
    }else{
        qDebug()<<"la reservation a echoué";
    }
}

