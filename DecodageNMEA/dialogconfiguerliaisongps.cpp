#include "dialogconfiguerliaisongps.h"
#include "ui_dialogconfiguerliaisongps.h"

#include <QSettings>
#include <QDir>
#include <QSize>
#include <QPoint>
#include <QDebug>

DialogConfiguerLiaisonGPS::DialogConfiguerLiaisonGPS(QSerialPort &_lePort, QWidget *parent):
    QDialog(parent),
    ui(new Ui::DialogConfiguerLiaisonGPS),
    lePort(_lePort)

{
    ui->setupUi(this);


    for(const auto &info : QSerialPortInfo::availablePorts() ) // foreach
    {
        qDebug() << info.portName();
        ui->comboBoxPort->addItem(info.portName());

    }
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

}

DialogConfiguerLiaisonGPS::~DialogConfiguerLiaisonGPS()
{
    delete ui;
}

void DialogConfiguerLiaisonGPS::on_comboBoxPort_currentTextChanged(const QString &arg1)
{
    lePort.setPortName(arg1);
    qDebug() << "le port est fixer sur"<< arg1;
    if(arg1 != "Choisissez un port"){
       ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }else{
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    }
}


void DialogConfiguerLiaisonGPS::on_radioButtonPaire_clicked(bool checked)
{
    if(checked){
        lePort.setParity(QSerialPort::EvenParity);
    }
}


void DialogConfiguerLiaisonGPS::on_radioButtonImpaire_clicked(bool checked)
{
    if(checked){
        lePort.setParity(QSerialPort::OddParity);
    }
}


void DialogConfiguerLiaisonGPS::on_radioButtonRien_clicked(bool checked)
{
    if(checked){
        lePort.setParity(QSerialPort::NoParity);
    }
}


void DialogConfiguerLiaisonGPS::on_comboBoxVitesse_currentIndexChanged(int index)
{
    QString baudRateSelectionner = ui->comboBoxVitesse->itemText(index);
    int baudRate = baudRateSelectionner.toInt();
    lePort.setBaudRate(baudRate);
}

