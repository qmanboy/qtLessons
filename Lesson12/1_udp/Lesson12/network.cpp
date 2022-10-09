#include "network.h"

TcpConnection::TcpConnection(int port) : port_(port)
{
    recvSocket4_.bind(QHostAddress::Any, port_, QUdpSocket::ReuseAddressHint);
    connect(&recvSocket4_, &QUdpSocket::readyRead, this, &TcpConnection::receiveMessage);
    QString msg = "Connection is ready on port " + QString::number(port_);
    qDebug() << msg;
}

void TcpConnection::sendMessage(const QString& name, const QString& msg)
{
    QDateTime dTime;
    QString time = dTime.currentDateTime().time().toString();
    QByteArray datagram = ("[" + time + "] " + name +" >> " + msg).toStdString().c_str();
    sendSocket4_.writeDatagram(datagram, QHostAddress::Broadcast, port_);
}

void TcpConnection::receiveMessage()
{
    QByteArray datagram;
    while (recvSocket4_.hasPendingDatagrams())
    {
        datagram.resize(int(recvSocket4_.pendingDatagramSize()));
        recvSocket4_.readDatagram(datagram.data(), datagram.size());
        emit receivedMsg(static_cast<QString>(datagram.constData()));
    }
}
