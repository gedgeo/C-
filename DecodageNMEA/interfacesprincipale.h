#ifndef INTERFACESPRINCIPALE_H
#define INTERFACESPRINCIPALE_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QLabel>
#include <QByteArray>

#include "dialogconfiguerliaisongps.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class InterfacesPrincipale;
}
QT_END_NAMESPACE

class InterfacesPrincipale : public QMainWindow
{
    Q_OBJECT

public:
    InterfacesPrincipale(QWidget *parent = nullptr);
    ~InterfacesPrincipale();

    void decodageNMEA(const QString &_trameNMEA);


private slots:
    void on_actionConfigurer_triggered();
    void onQSerialPort_readyRead();


private:
    Ui::InterfacesPrincipale *ui;
    DialogConfiguerLiaisonGPS configGPS;
    QSerialPort lePort;
    QByteArray trameCourante;

};
#endif // INTERFACESPRINCIPALE_H
