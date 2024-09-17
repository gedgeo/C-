#include "spliterwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    spliterWidget w;
    w.show();
    return a.exec();
}
