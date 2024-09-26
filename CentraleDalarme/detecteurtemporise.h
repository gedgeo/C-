#ifndef DETECTEURTEMPORISE_H
#define DETECTEURTEMPORISE_H
#include "detecteur.h"
#include <QWidget>
#include <QString>
#include <QTimer>

/**
 *@file detecteurtemporise.h
 *@brief Déclaration de la classe detecteur temporiser
 *@version 1.0
 *@author Benjamin Bandou
 *@date 26/09/2024
 */


/** @brief The DetecteurTemporise class */
class DetecteurTemporise : public Detecteur
{
public:
    DetecteurTemporise();
    ~DetecteurTemporise();

private slots:
    void on_pushButtonIntrus_clicked();
    void onTimerTempo_timeout();

private:
    /** @brief timerTempo */
    QTimer timerTempo;

};

#endif // DETECTEURTEMPORISE_H
