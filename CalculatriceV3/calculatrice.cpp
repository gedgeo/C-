#include "calculatrice.h"
#include "ui_calculatrice.h"
#include <QJSEngine>
#include <QMessageBox>

calculatrice::calculatrice(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calculatrice)
{
    /** Initialiser les widgets **/

    ui->setupUi(this);

    const int NB_TOUCHES = 16;
    const QString tableDesSymboles[] = {"7", "8", "9", "+",
                                        "4", "5", "6", "-",
                                        "1", "2", "3", "*",
                                        "C", "0", "=", "/"};

    /** Créer le layout de la grille **/

    grille = new QGridLayout;
    afficheur = new QLineEdit;
    afficheur->setMinimumHeight(50);
    afficheur->setStyleSheet("background-color: rgb(143, 240, 164);");
    afficheur->setReadOnly(true);

    /** Empêche la modification directe de l'affichage **/

    grille->addWidget(afficheur, 0, 0, 1, 4);

    /** Créer les boutons et les ajouter au layout **/

    touches = new QPushButton*[NB_TOUCHES];
    for (int i = 0; i < NB_TOUCHES; ++i) {
        touches[i] = new QPushButton(tableDesSymboles[i]);
        grille->addWidget(touches[i], (i / 4) + 1, i % 4);
        /**  (i / 4) + 1 pour commencer à la ligne 1 **/
    }

    /** Créer un widget central pour la fenêtre principale **/

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(grille);
    setCentralWidget(centralWidget);

    /** Configurer la fenêtre principale **/

    setWindowTitle("Calculatrice Dynamique");
    resize(300, 300);

    /**
    ui->setupUi(this);
    const int NB_TOUCHES = 16;

    const QString tableDesSymboles[ ] = {"7", "8", "9", "+" ,"4", "5", "6", "-", "1", "2", "3", "*",
                                        "C", "0", "=", "/"};
    grille = new QGridLayout;
    afficheur = new QLineEdit;
    afficheur->setMinimumHeight(50);
    afficheur->setStyleSheet("background-color: rgb(143, 240, 164);");
    touches = new QPushButton*[16];
    grille->addWidget(afficheur,0,0,1,4);
    this->setLayout(grille);
**/
}

calculatrice::~calculatrice()
{
    delete ui;
    delete[] touches;
}

void calculatrice::onQPushButtonClicked()
{
    QPushButton *touche;
    touche=qobject_cast<QPushButton*>(sender());
    QString expression = ui->lineEdit->text();
    ui->lineEdit->setText(expression + touche->text());
}


void calculatrice::on_pushButtonEgal_clicked()
{
    QJSEngine myEngine;
    QJSValue three = myEngine.evaluate(ui->lineEdit->text());
    ui->lineEdit->setText(three.toString());
}


void calculatrice::on_pushButtonEffacer_clicked()
{
    ui->lineEdit->clear();
}

