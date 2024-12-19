#include "gpw.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GPW w;
    w.show();
    return a.exec();
}
