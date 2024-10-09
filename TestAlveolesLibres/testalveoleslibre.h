#ifndef TESTALVEOLESLIBRE_H
#define TESTALVEOLESLIBRE_H

#include <QWidget>
#include "alveoleslibres.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class TestAlveolesLibre;
}
QT_END_NAMESPACE

class TestAlveolesLibre : public QWidget
{
    Q_OBJECT

public:
    TestAlveolesLibre(QWidget *parent = nullptr);
    ~TestAlveolesLibre();

private slots:
    void on_pushButtonLiberer_clicked();

    void on_pushButtonReserver_clicked();

private:
    Ui::TestAlveolesLibre *ui;
    AlveolesLibres* lesAlveoles;
};
#endif // TESTALVEOLESLIBRE_H
