#include "NetConnection.h"
#include "ILog.h"
#include <QHostAddress>

NetConnection::NetConnection(QObject *parent) :
    QObject(parent)
{

}

NetConnection::~NetConnection()
{
    qDebug()<< __FUNCTION__;
//    delete pTimer;
//    delete pTcpSocket;
}

void NetConnection::connectToHost(QString hostName, quint16 port)
{
    if(!pTcpSocket)
    {
        return;
    }
    pHostName = hostName;
    pPort = port;
    pTcpSocket->connectToHost(pHostName , pPort);
}

void NetConnection::init()
{
    connect(this , &NetConnection::sigConnectToHost , this , &NetConnection::connectToHost);

    pTcpSocket = new QTcpSocket();
    connect(pTcpSocket , &QTcpSocket::connected , this , &NetConnection::onConnected);
    connect(pTcpSocket , &QTcpSocket::disconnected , this , &NetConnection::onDisconnected);
    connect(pTcpSocket , &QTcpSocket::readyRead , this , &NetConnection::onReadyRead);
    connect(pTcpSocket , QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::error) , this , &NetConnection::onError);

    pTimer = new QTimer();
    pTimer->setSingleShot(true);
    pTimer->setInterval(10000);
    connect(pTimer , &QTimer::timeout , this , [=](){
        pTcpSocket->connectToHost(pHostName , pPort);
    });
}

void NetConnection::initConnection(QString hostName, quint16 port)
{
    emit sigConnectToHost(hostName , port);
}

void NetConnection::write(const QByteArray &data)
{
    if( pTcpSocket->write(data) == -1)
    {
        LOG_WARN()<< "Socket write data error," << pTcpSocket->errorString();
        return;
    }
}

void NetConnection::onConnected()
{
    LOG_INFO()<< "Socket Connected to " << pTcpSocket->peerAddress();
    emit connected();
}

void NetConnection::onDisconnected()
{
    LOG_INFO()<< "Socket DisConnected";
    emit disconnected();
}

void NetConnection::onError(QAbstractSocket::SocketError socketError)
{
    LOG_WARN()<< socketError;
    pTimer->start();
    emit error(socketError);
}

void NetConnection::onReadyRead()
{
    QByteArray data  = pTcpSocket->readAll();
    qDebug()<< "Socket Receive data:" << data.toHex().toUpper();
    emit receiveData( data );
}

void NetConnection::stopTimer()
{
    pTimer->stop();
}
