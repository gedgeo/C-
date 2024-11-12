#ifndef DIALOGCONFIGUERLIAISONGPS_H
#define DIALOGCONFIGUERLIAISONGPS_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QPushButton>
namespace Ui {
class DialogConfiguerLiaisonGPS;
}

class DialogConfiguerLiaisonGPS : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConfiguerLiaisonGPS(QSerialPort &_lePort,QWidget *parent = nullptr);
    ~DialogConfiguerLiaisonGPS();

private slots:
    void on_comboBoxPort_currentTextChanged(const QString &arg1);

    void on_radioButtonPaire_clicked(bool checked);

    void on_radioButtonImpaire_clicked(bool checked);

    void on_radioButtonRien_clicked(bool checked);

    void on_comboBoxVitesse_currentIndexChanged(int index);

private:
    Ui::DialogConfiguerLiaisonGPS *ui;
    QSerialPort &lePort;
};

#endif // DIALOGCONFIGUERLIAISONGPS_H
