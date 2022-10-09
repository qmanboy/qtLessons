#include "tcpconnection.h"

TcpConnection::TcpConnection(QTcpSocket* socket, QObject* parent)
    : QObject(parent),
      socket_(socket)
{
    connect(socket_, &QTcpSocket::readyRead, this, &TcpConnection::readData);
    //connect(socket_, &QTcpSocket::disconnected, this, [this]{emit disconnect();});
    connect(socket_, &QTcpSocket::disconnected, this, &TcpConnection::disconnected);
}

void TcpConnection::sendMsg(const QString& msg)
{
    QByteArray message = msg.toStdString().c_str();
    socket_->write(message, message.size());
}

void TcpConnection::readData()
{
    while (socket_->bytesAvailable() > 0)
    {
        QByteArray data = socket_->readAll();
        emit recvMsg(QString(data));
    }
}

/*void TcpConnection::disconnectSlot()
{
    emit disconnect(socket_);
}*/
