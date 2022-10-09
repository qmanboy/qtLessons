#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QObject>
#include <QtNetwork>
#include <QTextStream>
#include <QMutableVectorIterator>
#include <QVectorIterator>
#include "tcpconnection.h"

class ChatServer: public QObject
{
    Q_OBJECT
public:
    ChatServer(int port, QObject* parent = nullptr);
    ~ChatServer();

signals:
    void sendMsg(const QString& msg);
    void quit();

public slots:
    void onNewConnection();
    void onDisconnection();
    void pushToChat(const QString& msg);

    void sendChat(TcpConnection* client);
private:
    QTcpServer *server_{nullptr};
    int port_{};
    QVector <TcpConnection*> clients_;
    QVector<QString> chat_;
};

#endif // CHATSERVER_H
