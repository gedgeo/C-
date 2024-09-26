#ifndef DETECTEUR_H
#define DETECTEUR_H

#include <QDialog>

/**
 *@file detecteur.h
 *@brief Déclaration de la classe detecteur
 *@version 1.0
 *@author Benjamin Bandou
 *@date 26/09/2024
 */



namespace Ui {
class Detecteur;
}

/** @brief The Detecteur class */

class Detecteur : public QDialog
{
    Q_OBJECT

public:
    explicit Detecteur(QWidget *parent = nullptr);
    ~Detecteur();

private slots:

    virtual void on_pushButtonIntrus_clicked();


private:
    /** @brief ui */
    Ui::Detecteur *ui;

};

#endif // DETECTEUR_H
