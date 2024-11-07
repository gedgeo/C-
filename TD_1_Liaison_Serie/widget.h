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



private slots:
    void on_pushButton_clicked();
    void on_pushButtonEnoyer_clicked();
    void on_comboBox_currentTextChanged(const QString &arg1);
    void onQSerialPort_readyRead();

private:
    Ui::Widget *ui;
    QSerialPort *portPtr;  // Port série dynamique
};
#endif // WIDGET_H
