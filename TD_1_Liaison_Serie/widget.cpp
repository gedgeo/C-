#include "widget.h"
#include "ui_widget.h"

#include <QSerialPortInfo>
#include <QList>
#include <QDebug>
#include <QSerialPort>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , portPtr(nullptr)
{

    ui->setupUi(this);
    ui->comboBox->clear();

    portPtr=new QSerialPort();
    ui->comboBox->addItem("Choisissez un port");
    for (const auto &info : QSerialPortInfo::availablePorts()) {
        qDebug() << info.portName();
        ui->comboBox->addItem(info.portName());
    }
    ui->pushButton->setDisabled(true);


}

Widget::~Widget()
{
    if (portPtr) {
        if (portPtr->isOpen()) {
            portPtr->close();  // Ferme le port si ouvert
        }
        delete portPtr;  // Libère la mémoire
        portPtr = nullptr;  // Bonnes pratiques : évite les pointeurs pendants
    }
    delete ui;
}

void Widget::ApplicationSerie()
{

    if (portPtr->open(QIODevice::ReadWrite)) {
        // Port ouvert avec succès
        qDebug() << "reussi";
    } else {
        qDebug() << "erreur";
    }
}



void Widget::on_pushButton_clicked()
{
    if(ui->pushButton->text()=="Ouvrir le port")
    {
        portPtr->setBaudRate(QSerialPort::Baud115200);
        portPtr->setDataBits(QSerialPort::Data8);
        portPtr->setParity(QSerialPort::NoParity);
        portPtr->setStopBits(QSerialPort::OneStop);
        portPtr->setFlowControl(QSerialPort::NoFlowControl);
        connect(portPtr, &QSerialPort::readyRead, this, &Widget::onQSerialPort_readyRead);
        ui->pushButton->setText("Fermer le port");
        if (portPtr->open(QIODevice::ReadWrite)) {
            // Port ouvert avec succès
            qDebug() << "reussi";
        } else {
            qDebug() << "erreur";
        }
    }
    else
    {
        ui->pushButton->setText("Ouvrir le port");
          portPtr->close();

    }
}



void Widget::on_pushButtonEnoyer_clicked()
{
    QString texte=ui->lineEdit_2->text();
    if(portPtr!=nullptr)
        portPtr->write(texte.toLatin1());
}


void Widget::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(portPtr!=nullptr)
        portPtr->setPortName(arg1);

    ui->pushButton->setEnabled(true);
}

void Widget::onQSerialPort_readyRead()
{
    QByteArray data = portPtr->readAll();
    ui->textEdit->append(data);
}

