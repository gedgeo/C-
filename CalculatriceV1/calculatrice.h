#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class calculatrice;
}
QT_END_NAMESPACE

class calculatrice : public QWidget
{
    Q_OBJECT

public:
    calculatrice(QWidget *parent = nullptr);
    ~calculatrice();

private slots:
    void on_pushButtonDiviser_clicked();

    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

    void on_pushButton3_clicked();

    void on_pushButton4_clicked();

    void on_pushButton5_clicked();

    void on_pushButton6_clicked();

    void on_pushButton7_clicked();

    void on_pushButton8_clicked();

    void on_pushButton9_clicked();

    void on_pushButtonAdditionner_clicked();

    void on_pushButtonSoustraire_clicked();

    void on_pushButtonMultiplier_clicked();

    void on_pushButtonEgal_clicked();

    void on_pushButton0_clicked();

    void on_pushButtonEffacer_clicked();

private:
    Ui::calculatrice *ui;
};
#endif // CALCULATRICE_H
