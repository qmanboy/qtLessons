#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include <QtCore>
#include <QtNetwork>
#include <QDateTime>


class TcpConnection: public QObject
{
    Q_OBJECT
public:
    TcpConnection(QTcpSocket* socket, QObject* parent = nullptr);
    QTcpSocket* getSocket(){ return socket_; };

public slots:
    void sendMsg(const QString& msg);


private slots:
    void readData();
    //void disconnectSlot();

signals:
    void recvMsg(const QString& msg);
    void disconnected();

private:
    QTcpSocket *socket_{nullptr};
};

#endif // TCPCONNECTION_H
