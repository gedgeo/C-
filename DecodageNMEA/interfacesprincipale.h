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

private slots:
    void on_actionConfigurer_triggered();

private:
    Ui::InterfacesPrincipale *ui;
    DialogConfiguerLiaisonGPS configGPS;
    QSerialPort lePort;
};
#endif // INTERFACESPRINCIPALE_H
