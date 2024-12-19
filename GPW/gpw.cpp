#include "gpw.h"
#include "ui_gpw.h"
#include <QDebug>

GPW::GPW(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GPW)
    , socketClient(nullptr)
{
    ui->setupUi(this);
    socketClient = new QTcpSocket(this);

    // Connexions pour les événements réseau
    connect(socketClient, &QTcpSocket::connected, this, &GPW::onQTcpSocketConnected);
    connect(socketClient, &QTcpSocket::disconnected, this, &GPW::onQTcpSocketDisconnected);
    connect(socketClient, &QTcpSocket::readyRead, this, &GPW::onQTcpSocketReadyRead);
    connect(socketClient, &QTcpSocket::errorOccurred, this, &GPW::onQTcpSocketErrorOccured);

    // Désactiver les boutons de jeu tant que le client n'est pas connecté
    ui->pushButtonEnvoyerScore->setEnabled(false);
    ui->pushButtonAfficherScore->setEnabled(false);
}

GPW::~GPW()
{
    if (socketClient != nullptr) {
        socketClient->close();
        delete socketClient;
    }
    delete ui;
}

void GPW::on_pushButtonConnexion_clicked()
{
    if (ui->pushButtonConnexion->text() == "Connexion") {
        socketClient->connectToHost(ui->lineEditAdresseIP->text(),
                                    ui->lineEditPort->text().toInt());
    } else {
        socketClient->disconnectFromHost();
    }
}

void GPW::on_pushButtonEnvoyerScore_clicked()
{
    QString scoreMessage = "SCORE:" + ui->lineEditNomJoueur->text() + "," + ui->lineEditScore->text();
    socketClient->write(scoreMessage.toUtf8());
    qDebug() << "Score envoyé au serveur:" << scoreMessage;
}

void GPW::on_pushButtonAfficherScore_clicked()
{

    QString scoreRequest = "GET_PERSONNAGE";
    socketClient->write(scoreRequest.toUtf8());
    qDebug() << "Demande des scores au serveur.";
}

void GPW::onQTcpSocketConnected()
{
    ui->textEditEtat->append("Connecté au serveur");
    ui->pushButtonConnexion->setText("Déconnexion");
    ui->lineEditAdresseIP->setEnabled(false);
    ui->lineEditPort->setEnabled(false);

    // Activer les boutons liés au jeu
    ui->pushButtonEnvoyerScore->setEnabled(true);
    ui->pushButtonAfficherScore->setEnabled(true);

    qDebug() << "Connecté au serveur.";
}

void GPW::onQTcpSocketDisconnected()
{
    ui->textEditEtat->append("Déconnecté du serveur");
    ui->pushButtonConnexion->setText("Connexion");
    ui->lineEditAdresseIP->setEnabled(true);
    ui->lineEditPort->setEnabled(true);

    // Désactiver les boutons liés au jeu
    ui->pushButtonEnvoyerScore->setEnabled(false);
    ui->pushButtonAfficherScore->setEnabled(false);

    qDebug() << "Déconnecté du serveur.";
}

void GPW::onQTcpSocketReadyRead()
{
    QByteArray data;

    if (socketClient->bytesAvailable() > 0) {
        data = socketClient->readAll();
        qDebug() << "Données reçues du serveur :" << QString(data);

        QStringList messages = QString(data).split("\n", Qt::SkipEmptyParts);
        for (const QString &message : messages) {
            if (message.startsWith("PERSONNAGE:")) {
                // Exemple de message: PERSONNAGE:Zorro
                QString character = message.mid(11).trimmed();
                ui->lineEditPersonnage->setText(character);
                ui->textEditEtat->append("Personnage attribué: " + character);
            } else if (message.startsWith("SCORE:")) {
                // Exemple de message: SCORE:NomJoueur,50
                QStringList scoreParts = message.mid(6).split(",");
                if (scoreParts.size() == 2) {
                    QString playerName = scoreParts[0];
                    QString score = scoreParts[1];
                    ui->textEditScores->append(playerName + ": " + score);
                }
            } else {
                // Afficher les autres messages génériques
                ui->textEditScores->append(message);
            }
        }
    }
}

void GPW::onQTcpSocketErrorOccured(QAbstractSocket::SocketError socketError)
{
    QString messageErreur;

    switch (socketError) {
    case QAbstractSocket::HostNotFoundError:
        messageErreur = "Hôte non trouvé. Vérifiez l'adresse du serveur et le port.";
        break;
    case QAbstractSocket::ConnectionRefusedError:
        messageErreur = "Connexion refusée par le serveur.";
        break;
    case QAbstractSocket::RemoteHostClosedError:
        messageErreur = "L'hôte distant a fermé la connexion.";
        break;
    case QAbstractSocket::SocketTimeoutError:
        messageErreur = "La connexion a expiré.";
        break;
    default:
        messageErreur = "Erreur inattendue.";
        break;
    }

    ui->textEditEtat->append(messageErreur);
    qDebug() << messageErreur;
}
