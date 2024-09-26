#include "detecteurtemporise.h"
#include "ui_detecteur.h"
#include <QMessageBox>

/**
 * @brief DetecteurTemporise::DetecteurTemporise
 * @author Benjamin Bandou
 */


DetecteurTemporise::DetecteurTemporise()
{
    setWindowTitle("Détecteur temporisé");
    connect(&timerTempo,&QTimer::timeout,this,&DetecteurTemporise::onTimerTempo_timeout);
}

DetecteurTemporise::~DetecteurTemporise()
{
    timerTempo.stop();
}

void DetecteurTemporise::on_pushButtonIntrus_clicked()
{
    timerTempo.start(3000);
}

void DetecteurTemporise::onTimerTempo_timeout()
{
    QMessageBox messageBox;
    messageBox.setText("Un intrus a été détecté");
    messageBox.exec();
    timerTempo.stop();
}
