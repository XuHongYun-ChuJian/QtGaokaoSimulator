/**********************************************
* @projectName   QtGaokaoSimulator
* @brief         网络通信类
* @param         void
* @return        void
* @author
* @date          2023-04-04
**********************************************/

#ifndef NETCONNECTION_H
#define NETCONNECTION_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>

class NetConnection : public QObject
{
    Q_OBJECT
public:
    explicit NetConnection(QObject *parent = nullptr);
    ~NetConnection() override;

Q_SLOT void connectToHost(QString hostName , quint16 port);

Q_SLOT void init();
    void initConnection(QString hostName , quint16 port);

signals:
    void sigConnectToHost(QString hostName , quint16 port);
    void connected();
    void disconnected();
    void error(QAbstractSocket::SocketError socketError);
    void receiveData(const QByteArray &data);

public slots:
    void write(const QByteArray &data);
    void stopTimer();

private slots:
    void onConnected();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError socketError);
    void onReadyRead();

private:
    QTcpSocket *pTcpSocket{nullptr};
    QTimer *pTimer;
    QString pHostName;
    quint16 pPort;
};

#endif // NETCONNECTION_H
