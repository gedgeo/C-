#ifndef SPLITERWIDGET_H
#define SPLITERWIDGET_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class spliterWidget;
}
QT_END_NAMESPACE

class spliterWidget : public QMainWindow
{
    Q_OBJECT

public:
    spliterWidget(QWidget *parent = nullptr);
    ~spliterWidget();

private slots:
    void on_PushButtonDecoder_clicked();

private:
    Ui::spliterWidget *ui;
};
#endif // SPLITERWIDGET_H
