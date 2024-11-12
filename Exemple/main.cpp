// #include <QSettings>
// #include <QDir>
// #include <QSize>
// #include <QPoint>
// #include <QDebug>

// int main() {
//     QSettings settings("MyCompany", "MyApp");
//     // Écrire des paramètres
//     settings.setValue("window/size", QSize(1024, 768));
//     settings.setValue("window/position", QPoint(200, 150));
//     settings.setValue("user/username", "LinuxUser");
//     qDebug() << "Settings written successfully!";
//     return 0;
// }


// #include <QSettings>
// #include <QSettings>
// #include <QDir>
// #include <QSize>
// #include <QPoint>
// #include <QDebug>
// int main() {
//     QSettings settings("MyCompany", "MyApp");
//     // Lire des paramètres avec une valeur par défaut si le paramètre n'existe pas
//     QSize size = settings.value("window/size", QSize(800, 600)).toSize();
//     QPoint position = settings.value("window/position", QPoint(100, 100)).toPoint();
//     QString username = settings.value("user/username", "defaultUser").toString();

//     qDebug() << "Window position:" << position;
//     qDebug() << "bbandou:" << username;
//     return 0;
// }


#include <QSettings>
#include <QDir>
#include <QSize>
#include <QPoint>
#include <QDebug>
int main() {
    // Initialisation de QSettings avec organisation "MyCompany" et application "MyApp"
    QSettings settings("MyCompany", "MyApp");
    // Écriture de paramètres dans des groupes
    settings.beginGroup("window");
    settings.setValue("size", QSize(1024, 768));
    settings.setValue("position", QPoint(200, 150));
    settings.endGroup();
    settings.beginGroup("user");
    settings.setValue("username", "LinuxUser");
    settings.endGroup();
    // Lecture des paramètres avec vérification préalable
    settings.beginGroup("window");
    if (settings.contains("size")) {
        QSize size = settings.value("size").toSize();
        qDebug() << "Window size:" << size;
    } else {
        qDebug() << "Window size not set.";
    }
    if (settings.contains("position")) {
        QPoint position = settings.value("position").toPoint();
        qDebug() << "Window position:" << position;
    } else {
        qDebug() << "Window position not set.";
    }
    settings.endGroup();
    settings.beginGroup("user");
    if (settings.contains("username")) {
        QString username = settings.value("username").toString();
        qDebug() << "Username:" << username;
    } else {
        qDebug() << "Username not set.";
    }
    settings.endGroup();
    return 0;
}

