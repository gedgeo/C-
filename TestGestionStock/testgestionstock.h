#ifndef TESTGESTIONSTOCK_H
#define TESTGESTIONSTOCK_H

#include <QWidget>
#include "alveoleslibres.h"
#include "stock.h"
#include "chariot.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class TestGestionStock;
}
QT_END_NAMESPACE

class TestGestionStock : public QWidget
{
    Q_OBJECT

public:
    TestGestionStock(QWidget *parent = nullptr);
    ~TestGestionStock();


private slots:
    void on_pushButtonNouveau_clicked();
    void on_pushButtonRetrait_clicked();
    void on_pushButtonSuppression_clicked();

private:
    Ui::TestGestionStock *ui;
    Stock stock;
    Alveoleslibres alveolesLibres;
    Chariot chariot;
    QList<Rouleau> rouleauxEnceinte;

    void afficherStock();
    void afficherRouleauEnceinte();
};
#endif // TESTGESTIONSTOCK_H
