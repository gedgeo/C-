/********************************************************************************
** Form generated from reading UI file 'testalveoleslibres.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTALVEOLESLIBRES_H
#define UI_TESTALVEOLESLIBRES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestAlveolesLibres
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonReserver;
    QPushButton *pushButtonLiberer;
    QLineEdit *lineEditEmplacement;
    QPushButton *pushButtonQuitter;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QListWidget *listWidget;

    void setupUi(QWidget *TestAlveolesLibres)
    {
        if (TestAlveolesLibres->objectName().isEmpty())
            TestAlveolesLibres->setObjectName("TestAlveolesLibres");
        TestAlveolesLibres->resize(429, 226);
        QFont font;
        font.setPointSize(15);
        TestAlveolesLibres->setFont(font);
        layoutWidget = new QWidget(TestAlveolesLibres);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 421, 217));
        QFont font1;
        font1.setPointSize(12);
        layoutWidget->setFont(font1);
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pushButtonReserver = new QPushButton(layoutWidget);
        pushButtonReserver->setObjectName("pushButtonReserver");
        pushButtonReserver->setFont(font1);

        verticalLayout->addWidget(pushButtonReserver);

        pushButtonLiberer = new QPushButton(layoutWidget);
        pushButtonLiberer->setObjectName("pushButtonLiberer");
        pushButtonLiberer->setFont(font1);

        verticalLayout->addWidget(pushButtonLiberer);

        lineEditEmplacement = new QLineEdit(layoutWidget);
        lineEditEmplacement->setObjectName("lineEditEmplacement");
        lineEditEmplacement->setFont(font1);
        lineEditEmplacement->setReadOnly(true);

        verticalLayout->addWidget(lineEditEmplacement);

        pushButtonQuitter = new QPushButton(layoutWidget);
        pushButtonQuitter->setObjectName("pushButtonQuitter");
        pushButtonQuitter->setFont(font1);

        verticalLayout->addWidget(pushButtonQuitter);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(80, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setFont(font1);

        verticalLayout_2->addWidget(label);

        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setFont(font1);

        verticalLayout_2->addWidget(listWidget);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(TestAlveolesLibres);
        QObject::connect(pushButtonQuitter, &QPushButton::clicked, TestAlveolesLibres, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(TestAlveolesLibres);
    } // setupUi

    void retranslateUi(QWidget *TestAlveolesLibres)
    {
        TestAlveolesLibres->setWindowTitle(QCoreApplication::translate("TestAlveolesLibres", "Test des alveoles libres ", nullptr));
        pushButtonReserver->setText(QCoreApplication::translate("TestAlveolesLibres", "R\303\251server", nullptr));
        pushButtonLiberer->setText(QCoreApplication::translate("TestAlveolesLibres", "Lib\303\251rer", nullptr));
        pushButtonQuitter->setText(QCoreApplication::translate("TestAlveolesLibres", "Quitter", nullptr));
        label->setText(QCoreApplication::translate("TestAlveolesLibres", "Liste des alv\303\251oles occup\303\251es :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestAlveolesLibres: public Ui_TestAlveolesLibres {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTALVEOLESLIBRES_H
