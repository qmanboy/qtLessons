#include "chatclient.h"

ChatClient::ChatClient(const QHostAddress &server_addr, const int server_port, QObject* parent)
    : QObject(parent),
      socket_(new QTcpSocket(this))
{
    socket_->bind(server_addr, server_port);
    if (socket_->state() == QTcpSocket::UnconnectedState)
    {
        socket_->connectToHost(server_addr, server_port);
        QTextStream(stdout)  << "Connect to server succesfully\n";
        connect_ = true;
        connect(socket_, &QTcpSocket::readyRead, this, &ChatClient::recvMsg);
        connect(socket_, &QTcpSocket::disconnected, this, &ChatClient::disconnectSlot);
    }

    if (socket_->state() != QTcpSocket::ConnectingState)
    {
        QTextStream(stdout) << "Cannot connect to server " << socket_->errorString() + "\n";
    }

}

void ChatClient::sendMsg(const QString &msg)
{
    QByteArray message = msg.toStdString().c_str();
    socket_->write(message, message.size());
}

void ChatClient::disconnectSlot()
{
    connect_ = false;
    emit disconnectSignal(connect_);
}

void ChatClient::recvMsg()
{
    while (socket_->bytesAvailable() > 0)
    {
        QByteArray data = socket_->readAll();
        emit sendToWindow(QString(data));
    }
}
