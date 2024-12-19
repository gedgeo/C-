#ifndef GPW_H
#define GPW_H

#include <QWidget>
#include <QTcpSocket>
#include <QAbstractSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class GPW;
}
QT_END_NAMESPACE

class GPW : public QWidget
{
    Q_OBJECT

public:
    GPW(QWidget *parent = nullptr);
    ~GPW();

private slots:
    // Boutons principaux
    void on_pushButtonConnexion_clicked();          // Connexion/Déconnexion au serveur
    void on_pushButtonEnvoyerScore_clicked();       // Envoi du score au serveur
    void on_pushButtonAfficherScore_clicked();      // Demande des scores au serveur

    // Gestion des événements réseau
    void onQTcpSocketConnected();                   // Événement: connecté au serveur
    void onQTcpSocketDisconnected();                // Événement: déconnecté du serveur
    void onQTcpSocketReadyRead();                   // Événement: données disponibles
    void onQTcpSocketErrorOccured(QAbstractSocket::SocketError _socketError);

private:
    Ui::GPW *ui;                                    // Interface utilisateur
    QTcpSocket *socketClient;                       // Socket pour la communication avec le serveur
};

#endif // GPW_H
