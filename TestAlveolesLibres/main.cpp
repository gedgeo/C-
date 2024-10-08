#include "testalveoleslibre.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestAlveolesLibre w;
    w.show();
    return a.exec();
}
