#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QObject>
#include <QtNetwork>

class ChatClient: public QObject
{
    Q_OBJECT
public:
    ChatClient(const QHostAddress &server_addr, const int server_port, QObject* parent = nullptr);
    bool isConnect() const { return connect_;};

public slots:
    void sendMsg(const QString& msg);
    void disconnectSlot();

signals:
    void sendToWindow(const QString& msg);
    void disconnectSignal(bool);

private slots:
    void recvMsg();

private:
    QTcpSocket* socket_;
    bool connect_{false};
};

#endif // CHATCLIENT_H
