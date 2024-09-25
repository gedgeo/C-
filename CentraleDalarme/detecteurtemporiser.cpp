#include "detecteurtemporiser.h"
#include "ui_detecteurtemporiser.h"
#include <QMessageBox>

DetecteurTemporiser::DetecteurTemporiser(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DetecteurTemporiser)
{
    ui->setupUi(this);
    connect(&timerTempo,&QTimer::timeout,this,&DetecteurTemporiser::onTimerTempo_timeout);
}

DetecteurTemporiser::~DetecteurTemporiser()
{
    delete ui;
    //timerTempo.stop();
}

void DetecteurTemporiser::on_pushButtonPresence_clicked()
{
    //timerTempo.start(3000);
}

void DetecteurTemporiser::onTimerTempo_timeout()
{
    //timerTempo.stop();
}

