#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>

#define NB_Touches

QT_BEGIN_NAMESPACE
namespace Ui {
class calculatrice;
}
QT_END_NAMESPACE

class calculatrice : public QMainWindow
{
    Q_OBJECT

public:
    calculatrice(QWidget *parent = nullptr);
    ~calculatrice();

private slots:
    void onQPushButtonClicked();

    void on_pushButtonEgal_clicked();

    void on_pushButtonEffacer_clicked();

private:
    Ui::calculatrice *ui;
    static const int NB_TOUCHES = 16; // Nombre de boutons
    QPushButton **touches;
    QLineEdit *afficheur;
    QGridLayout *grille;
};
#endif // CALCULATRICE_H
