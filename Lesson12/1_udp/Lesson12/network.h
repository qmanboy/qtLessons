#ifndef NETWORK_H
#define NETWORK_H

#include <QtCore>
#include <QtNetwork>
#include <QDateTime>


class TcpConnection: public QObject
{
    Q_OBJECT
public:
    TcpConnection(int port);

public slots:
    void sendMessage(const QString& name, const QString& msg);

private slots:
    void receiveMessage();

signals:
    void receivedMsg(const QString&);

private:
    int port_;
    QUdpSocket sendSocket4_;
    QUdpSocket recvSocket4_;
};

#endif // NETWORK_H
