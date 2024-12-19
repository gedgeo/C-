#ifndef AUDITSERVEURWIDGET_H
#define AUDITSERVEURWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QProcess>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include<QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class AuditServeurWidget;
}
QT_END_NAMESPACE

class AuditServeurWidget : public QWidget
{
    Q_OBJECT

public:
    AuditServeurWidget(QWidget *parent = nullptr);
    ~AuditServeurWidget();

private slots:
    void on_pushButtonLancement_clicked();
    void onQTcpServerNewConnection();
    void onQTcpServerAccepError();
    void onQTcpSocketConnected();
    void onQTcpSocketDisconnected();
    void onQTcpSocketReadyRead();
    void onQTcpSocketErrorOccurred(QAbstractSocket::SocketError _socketError);
    void onQTcpSocketHostFound();
    void onQTcpSocketStateChanged(QAbstractSocket::SocketState _socketState);
    void onQTcpSocketAboutToClose();
    void onQProcessReadyReadStandardOutput();

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::AuditServeurWidget *ui;

    QTcpServer *socketEcouteServeur;
    QTcpSocket *socketDialogueClient;
    QProcess *process;


    QSqlDatabase db; // Pour la connexion à la base de données

};
#endif // AUDITSERVEURWIDGET_H
