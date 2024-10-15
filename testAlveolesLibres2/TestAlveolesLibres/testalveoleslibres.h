#ifndef TESTALVEOLESLIBRES_H
#define TESTALVEOLESLIBRES_H
#include<QMessageBox>
#include <QWidget>
#include <alveoleslibres.h>
#include <QString>
#include <QStringList>
QT_BEGIN_NAMESPACE
namespace Ui {
class TestAlveolesLibres;
}
QT_END_NAMESPACE

class TestAlveolesLibres : public QWidget
{
    Q_OBJECT

public:
    TestAlveolesLibres(QWidget *parent = nullptr);
    ~TestAlveolesLibres();

public slots:
    void on_pushButtonLiberer_clicked();

    void on_pushButtonReserver_clicked();

private:
    Ui::TestAlveolesLibres *ui;
    AlveolesLibres *lesAlveoles;
};
#endif // TESTALVEOLESLIBRES_H
