#include "interfacesprincipale.h"
#include "ui_interfacesprincipale.h"

#include <QTimeZone>
#include <QString>
#include <QStringList>

InterfacesPrincipale::InterfacesPrincipale(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InterfacesPrincipale)
    , configGPS(lePort)
{
    ui->setupUi(this);
    ui->labelEtatPort->setText("port fermé");
    ui->statusbar->addPermanentWidget(ui->labelEtatPort);
    ui->statusbar->show();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

InterfacesPrincipale::~InterfacesPrincipale()
{
    delete ui;
}

void InterfacesPrincipale::decodageNMEA(const QString &_trameNMEA)
{
    QStringList champsNMEA = _trameNMEA.split(',');
    if (champsNMEA.size() >= 12 && champsNMEA.at(0) == "$GPRMC") {
        // Extraction de l'heure
        QString heureStr = champsNMEA.at(1);
        QTime heure(heureStr.mid(0, 2).toInt(),
                    heureStr.mid(2, 2).toInt(),
                    heureStr.mid(4, 2).toInt());
        // Extraction de la date (Exemple pour le champ date, en
        // supposant que le champ date est au format DDMMYY)
        QString dateStr = champsNMEA.at(9);
        QDate date(2000 + dateStr.mid(4, 2).toInt(),
                   dateStr.mid(2, 2).toInt(),
                   dateStr.mid(0, 2).toInt());
        // Création d'un horodatage
        QDateTime horodatage(date, heure, QTimeZone("Europe/Paris"));
        // Conversion locale si nécessaire
        horodatage = horodatage.toLocalTime();
        // Mise à jour de l'interface
        int ligneCourante = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(ligneCourante);
        ui->tableWidget->setItem(ligneCourante, 0,
                                     new QTableWidgetItem(horodatage.toString(Qt::TextDate)));
        // À compléter pour les autres champs,
        // comme la latitude, la longitude, etc.
        // Extraction de la latitude
        QString latitudeStr = champsNMEA.at(3);
        double latitudeDeg = latitudeStr.left(2).toDouble();  // Degré de latitude
        double latitudeMin = latitudeStr.mid(2, 2).toDouble();  // Minutes de latitude
        double latitude = latitudeDeg + latitudeMin / 60.0;
        if (champsNMEA.at(4) == "S") {  // Si 'S', c'est au sud
            latitude = -latitude;
        }

        // Extraction de la longitude (
        QString longitudeStr = champsNMEA.at(5);
        double longitudeDeg = longitudeStr.left(3).toDouble();  // Degré de longitude
        double longitudeMin = longitudeStr.mid(3, 2).toDouble();  // Minutes de longitude
        double longitude = longitudeDeg + longitudeMin / 60.0;
        if (champsNMEA.at(6) == "W") {  // Si 'W', c'est à l'ouest
            longitude = -longitude;
        }

        // Remplir la table avec la latitude et la longitude
        ui->tableWidget->setItem(ligneCourante, 1, new QTableWidgetItem(QString::number(latitude, 'f', 6)));
        ui->tableWidget->setItem(ligneCourante, 2, new QTableWidgetItem(QString::number(longitude, 'f', 6)));

    }
}

void InterfacesPrincipale::on_actionConfigurer_triggered()
{
    if (configGPS.exec() == QDialog::Accepted)
    {
        if (lePort.open(QIODevice::ReadWrite)) {
            // Port ouvert avec succès
            qDebug() << "ouverture reussi";
            connect(&lePort, &QSerialPort::readyRead,
                    this, &InterfacesPrincipale::onQSerialPort_readyRead);
        } else {
            qDebug() << "erreur d'ouverture";
        }
    }
}

void InterfacesPrincipale::onQSerialPort_readyRead()
{
    QByteArray data = lePort.readAll();
    ui->textEditTrameRecu->append(data);

    trameCourante.append(data);
    while (trameCourante.contains('\n')) {
        // Trouver la position du premier '\n' dans la trame
        // i correspond aux '\n' dans la trame
        int i = trameCourante.indexOf('\n');

        // Extraire la partie de la trame jusqu'au '\n'
        QByteArray frame = trameCourante.left(i);

        // Afficher cette partie dans le textEdit
        ui->textEditTrameRecu->append(frame);

        // Supprimer la partie extraite (jusqu'au '\n') de la trame courante
        trameCourante.remove(0, i + 1);
    }
}



