#ifndef DETECTEURTEMPORISER_H
#define DETECTEURTEMPORISER_H

#include <QDialog>
#include <QTimer>
#include "detecteur.h"

namespace Ui {
class DetecteurTemporiser;
}

class DetecteurTemporiser : public QDialog
{
    Q_OBJECT

public:
    explicit DetecteurTemporiser(QWidget *parent = nullptr);
    ~DetecteurTemporiser();

private slots:
    void on_pushButtonPresence_clicked();
    void onTimerTempo_timeout();

private:
    Ui::DetecteurTemporiser *ui;
    QTimer timerTempo;
};

#endif // DETECTEURTEMPORISER_H
