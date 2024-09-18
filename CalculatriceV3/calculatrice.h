#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <QMainWindow>

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

private:
    Ui::calculatrice *ui;
};
#endif // CALCULATRICE_H
