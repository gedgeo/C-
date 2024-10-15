#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void ApplicationSerie();
    virtual bool OpenPort();
    virtual void closePort();
    void sendData(const QByteArray &data);


private slots:
    void on_pushButton_clicked();
    void handleError(QSerialPort::SerialPortError);
    void readData();

private:
    Ui::Widget *ui;
    QSerialPort *portPtr;  // Port série dynamique
};
#endif // WIDGET_H
