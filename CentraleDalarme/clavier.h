#ifndef CLAVIER_H
#define CLAVIER_H

#include <QWidget>
#include <QString>
#include <QTimer>

#include "detecteur.h"
#include "detecteurtemporise.h"

/**
 *@file clavier.h
 *@brief Déclaration de la classe clavier
 *@version 1.0
 *@author Benjamin Bandou
 *@date 26/09/2024
 */

QT_BEGIN_NAMESPACE
namespace Ui {
class Clavier;
}
QT_END_NAMESPACE

/**
 * @brief The Clavier class
 */

class Clavier : public QWidget
{
    Q_OBJECT

public:
    Clavier(QWidget *parent = nullptr);
    ~Clavier();


private slots:
    void on_pushButton_Marche_clicked();
    void TraiterChiffre();
    void onTimerLed_timeout();

    void on_pushButton_Arret_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    /** @brief ui */
    Ui::Clavier *ui;
    /** @brief timerLed */
    QTimer timerLed;
    /** @brief leDetecteur */
    Detecteur *leDetecteur;
    /** @brief leDetecteurTemporiser */
    DetecteurTemporise *leDetecteurTemporiser;
};
#endif // CLAVIER_H
