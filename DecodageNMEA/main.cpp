#include "interfacesprincipale.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InterfacesPrincipale w;
    w.show();
    return a.exec();
}
