#include "widget.h"
#include "ui_widget.h"

#include <QSerialPortInfo>
#include <QList>
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->comboBox->clear();
    QSerialPort portPtr=new QSerialPort("ttyS0");
    for (const auto &info : QSerialPortInfo::availablePorts()) {
        qDebug() << info.portName();
        ui->comboBox->addItem(info.portName());
    }

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
    portPtr.setBaudRate(QSerialPort::Baud9600);
    if (portPtr.open(QIODevice::ReadWrite)) {
        // Port ouvert avec succès
        qDebug() << "successfully";
    } else {
        qDebug() << "Failed";

    }
}



void Widget::on_pushButton_clicked()
{

}


