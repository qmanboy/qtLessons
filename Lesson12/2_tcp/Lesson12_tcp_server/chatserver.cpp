#include "chatserver.h"

ChatServer::ChatServer(int port, QObject* parent)
    : QObject(parent),
      server_(new QTcpServer(this)),
      port_(port)
{
    connect(server_, &QTcpServer::newConnection, this, &ChatServer::onNewConnection);
    if (!server_->listen(QHostAddress::LocalHost, port_))
    {
        server_->close();
        throw server_->errorString();
    }
    QTextStream(stdout)  << "Server is listening: " << QVariant(server_->isListening()).toString() << "\nAddress: " << server_->serverAddress().toString() << "\nPort: " << server_->serverPort() << "\n";
    connect(this, &ChatServer::quit, qApp, &QCoreApplication::quit);
}

ChatServer::~ChatServer()
{
    server_->close();
    emit quit();
}

void ChatServer::onNewConnection()
{
    TcpConnection *client = new TcpConnection(server_->nextPendingConnection(), this);
    auto connection = client->getSocket();
    QTextStream(stdout) << connection->peerAddress().toString() + " "
                        << connection->peerPort()
                        << " connected!\n";
    this->sendChat(client);
    clients_.push_back(client);
    connect(client, &TcpConnection::recvMsg, this, &ChatServer::sendMsg);
    connect(client, &TcpConnection::recvMsg, this, &ChatServer::pushToChat);
    connect(this, &ChatServer::sendMsg, client, &TcpConnection::sendMsg);
    /*connect(client->getSocket(), &QTcpSocket::disconnected, this, [client]
    {
        auto connection = client->getSocket();
        QTextStream(stdout) << connection->peerAddress().toString() + " "
                            << connection->peerPort()
                            << " disconnected!\n";
    });*/
    connect(client, &TcpConnection::disconnected, this, &ChatServer::onDisconnection);

}

void ChatServer::onDisconnection()
{
    TcpConnection *client = (TcpConnection*)sender();
    auto connection = client->getSocket();
    QTextStream(stdout) << connection->peerAddress().toString() + " "
                        << connection->peerPort()
                        << " disconnected!\n";

    QMutableVectorIterator<TcpConnection*> client_it(clients_);
    while(client_it.hasNext())
    {
      TcpConnection* currentValue = client_it.next();
      if (currentValue == client)
        client_it.remove();
    }
}

void ChatServer::pushToChat(const QString &msg)
{
    chat_.push_back(msg);
}

/*void ChatServer::recvMsg(const QString &msg)
{

}*/

/*void ChatServer::sendMsg(const QString &msg)
{
    if (clients_.size() > 0)
    {
        for (TcpConnection* client : qAsConst(clients_))
        {
            client->sendMsg(msg);
        }
    }
}*/

void ChatServer::sendChat(TcpConnection *client)
{
    if (chat_.size() > 0)
    {
        if (chat_.size() > 10)
        {
            for (int idx = chat_.size() - 10; idx < chat_.size(); idx++)
            {
                 client->sendMsg(chat_[idx]);
            }
        }
        else
            for (const QString& item : qAsConst(chat_))
            {
                client->sendMsg(item);
            }
    }
}
