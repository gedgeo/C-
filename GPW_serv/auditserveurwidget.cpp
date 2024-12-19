#include "auditserveurwidget.h"
#include "ui_auditserveurwidget.h"

AuditServeurWidget::AuditServeurWidget(QWidget *parent)

    : QWidget(parent)
    , ui(new Ui::AuditServeurWidget)
    , socketEcouteServeur(new QTcpServer(this))
    , socketDialogueClient(nullptr)
    , process(new QProcess(this))
{
    ui->setupUi(this);
    connect(socketEcouteServeur, &QTcpServer::newConnection, this, &AuditServeurWidget::onQTcpServerNewConnection);
    connect(socketEcouteServeur, &QTcpServer::acceptError, this, &AuditServeurWidget::onQTcpServerAccepError);


    // Connexion à la base de données
    db = QSqlDatabase::addDatabase("QMYSQL"); // Utilisez "QMYSQL" pour MySQL
    db.setHostName("172.18.58.7"); // Adresse IP du serveur
    db.setDatabaseName("gpw"); // Nom de la base de données
    db.setUserName("snir"); // Remplacez par votre nom d'utilisateur
    db.setPassword("snir"); // Remplacez par votre mot de passe
    if (!db.open()) {
        ui->textEditInfo->append("Erreur de connexion à la base de données : " + db.lastError().text());
    }
}

AuditServeurWidget::~AuditServeurWidget()
{
    delete ui;
    socketEcouteServeur->deleteLater();
    delete process;
}



void AuditServeurWidget::on_pushButtonLancement_clicked()
{
    if (ui->pushButtonLancement->text() == "Lancement Serveur") {
        qint16 port = ui->spinBoxPort->value();
        if(!socketEcouteServeur->listen(QHostAddress::Any, port))
            ui->textEditInfo->append("Echec au lancement du serveur : " +socketEcouteServeur->errorString());
        ui->pushButtonLancement->setText("Fermer Serveur");

            ui->textEditInfo->append("Serveur lancé sur le port : " + QString::number(port));
    }else {
        socketEcouteServeur->close();
        ui->textEditInfo->append("Serveur fermé");
        ui->pushButtonLancement->setText("Lancement Serveur");
    }


}

void AuditServeurWidget::onQTcpServerNewConnection()
{
    QTcpSocket *newClient = socketEcouteServeur->nextPendingConnection();

        socketDialogueClient = newClient;
        connect(socketDialogueClient,&QTcpSocket::readyRead,this,&AuditServeurWidget::onQTcpSocketReadyRead);
        connect(socketDialogueClient,&QTcpSocket::disconnected,this,&AuditServeurWidget::onQTcpSocketDisconnected);
        connect(socketDialogueClient,&QTcpSocket::errorOccurred,this,&AuditServeurWidget::onQTcpSocketErrorOccurred);
        connect(socketDialogueClient,&QTcpSocket::connected,this,&AuditServeurWidget::onQTcpSocketConnected);
        connect(socketDialogueClient,&QTcpSocket::hostFound,this,&AuditServeurWidget::onQTcpSocketHostFound);
        connect(socketDialogueClient,&QTcpSocket::stateChanged,this,&AuditServeurWidget::onQTcpSocketStateChanged);
        connect(socketDialogueClient,&QTcpSocket::aboutToClose,this,&AuditServeurWidget::onQTcpSocketAboutToClose);
        ui->textEditInfo->append("Joueur connecter");

}

void AuditServeurWidget::onQTcpServerAccepError()
{
    ui->textEditInfo->append("Echec de connexion du nouveau Joueur");
}

void AuditServeurWidget::onQTcpSocketConnected()
{
    ui->textEditInfo->append("Joueur connecté");
}

void AuditServeurWidget::onQTcpSocketDisconnected()
{
    ui->textEditInfo->append("Joueur déconnecté");
    socketDialogueClient->deleteLater();
    socketDialogueClient = nullptr;
}

void AuditServeurWidget::onQTcpSocketReadyRead()
{
    // Lire les données envoyées par le client
    QByteArray data = socketDialogueClient->readAll();
    QString request = QString::fromUtf8(data).trimmed(); // Convertir en QString et enlever les espaces


    if (request == "GET_PERSONNAGE") {
        // Récupérer les données de la table Scores
        QSqlQuery queryScores("SELECT * FROM personnage");
        if (!queryScores.exec()) {
            ui->textEditInfo->append("Erreur lors de l'exécution de la requête Scores : " + queryScores.lastError().text());
            return;
        }

        QStringList scoresList;
        while (queryScores.next()) {
            QString result = QString("|  Nom: %1  |  Description: %2  |")
                                 .arg(queryScores.value("nom").toString())
                                 .arg(queryScores.value("description").toString());
            scoresList << result; // Ajouter le résultat à la liste
        }

        // Envoyer les scores au client
        if (!scoresList.isEmpty()) {
            socketDialogueClient->write(scoresList.join("\n").toUtf8()); // Joindre les résultats et les envoyer
        } else {
            socketDialogueClient->write("Aucun score trouvé.\n");
        }
    } else {
        ui->textEditInfo->append("Commande non reconnue : " + request);
    }



    if (request == "GET_SCORES") {
        // Récupérer les données de la table Scores
        QSqlQuery queryScores("SELECT * FROM Scores");
        if (!queryScores.exec()) {
            ui->textEditInfo->append("Erreur lors de l'exécution de la requête Scores : " + queryScores.lastError().text());
            return;
        }

        QStringList scoresList;
        while (queryScores.next()) {
            QString result = QString("|  Joueur: %1  |  Score: %2  |")
                                 .arg(queryScores.value("nom_joueur").toString())
                                 .arg(queryScores.value("score").toString());
            scoresList << result; // Ajouter le résultat à la liste
        }

        // Envoyer les scores au client
        if (!scoresList.isEmpty()) {
            socketDialogueClient->write(scoresList.join("\n").toUtf8()); // Joindre les résultats et les envoyer
        } else {
            socketDialogueClient->write("Aucun score trouvé.\n");
        }
    } else {
        ui->textEditInfo->append("Commande non reconnue : " + request);
    }

}

void AuditServeurWidget::onQTcpSocketErrorOccurred(QAbstractSocket::SocketError _socketError)
{
    if(socketDialogueClient)
    {
        QString messageErreur;
        switch (_socketError) {
        case QAbstractSocket::RemoteHostClosedError:
            messageErreur = "Le Joueur a fermé la connexion";
            break;
        default:
            messageErreur = "Erreur inattendue : " + socketDialogueClient->errorString();
            break;
        }
        qDebug() << "Erreur Joueur : " << messageErreur ;
        socketDialogueClient->disconnect();
    }
}

void AuditServeurWidget::onQTcpSocketHostFound()
{
ui->textEditInfo->append("Hôte trouvé");
}

void AuditServeurWidget::onQTcpSocketStateChanged(QAbstractSocket::SocketState _socketState)
{

}

void AuditServeurWidget::onQTcpSocketAboutToClose()
{
ui->textEditInfo->append("La socket vas fermer");
}

void AuditServeurWidget::onQProcessReadyReadStandardOutput()
{
    QString reponse = process->readAllStandardOutput();
    if(!reponse.isEmpty())
        socketDialogueClient->write(reponse.toLatin1());
}


void AuditServeurWidget::on_comboBox_currentTextChanged(const QString &arg1)
{
    QSqlTableModel* model = new QSqlTableModel(this);

    model->setTable(arg1);
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

