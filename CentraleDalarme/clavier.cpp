#include "clavier.h"
#include "ui_clavier.h"
#include <QMessageBox>

/**
 * @brief Clavier::Clavier
 * @param parent
 * @author Benjamin Bandou
 */


Clavier::Clavier(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Clavier)
    ,leDetecteur(nullptr)
    ,leDetecteurTemporiser(nullptr)
{
    ui->setupUi(this);

    connect(&timerLed, &QTimer::timeout, this, &Clavier::onTimerLed_timeout);
    connect(ui->pushButton_0,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton_1,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    //connect(ui->pushButton_2,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    //connect(ui->pushButton_3,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    //connect(ui->pushButton_4,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    //connect(ui->pushButton_5,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton_6,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton_7,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton_8,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton_9,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
}

Clavier::~Clavier()
{
    delete ui;
}

void Clavier::on_pushButton_Marche_clicked()
{
    QString texteBouton = ui->pushButton_Marche->text();
    QMessageBox messageMarche;
    messageMarche.setText("j'ai appuyé sur la touche " + texteBouton);
    messageMarche.exec();
    timerLed.start(500);
}


void Clavier::TraiterChiffre()
{
    QPushButton *pbouton = static_cast<QPushButton *>(sender());
    QString texteBouton = pbouton->text();
    QMessageBox messageChiffre;
    messageChiffre.setText("j'ai appuyé sur la touche " + texteBouton);
    messageChiffre.exec();
}

void Clavier::onTimerLed_timeout()
{

    if(ui->checkBoxLedRouge->checkState() == Qt::Checked)
        ui->checkBoxLedRouge->setCheckState(Qt::Unchecked);
    else
        ui->checkBoxLedRouge->setCheckState(Qt::Checked);
}


void Clavier::on_pushButton_Arret_clicked()
{
    ui->checkBoxLedRouge->setCheckState(Qt::Unchecked);
    timerLed.stop();
}


void Clavier::on_pushButton_2_clicked()
{
    if(leDetecteur==nullptr)
        leDetecteur = new Detecteur;
    leDetecteur->show();
}


void Clavier::on_pushButton_3_clicked()
{
    if(leDetecteur){
        leDetecteur->hide();
    }
}


void Clavier::on_pushButton_4_clicked()
{
    if(leDetecteurTemporiser==nullptr)
        leDetecteurTemporiser = new DetecteurTemporise;
    leDetecteurTemporiser->show();

}


void Clavier::on_pushButton_5_clicked()
{
    if(leDetecteurTemporiser){
        leDetecteurTemporiser->hide();
    }
}

