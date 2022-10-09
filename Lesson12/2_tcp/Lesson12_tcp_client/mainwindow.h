#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "chatclient.h"

#include <QMainWindow>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void recvMsg(const QString& msg);

signals:
    void sendToClient(const QString& msg);
    void connected(bool);

private slots:
    void sendMsg();
    void connectToServer();

private:
    Ui::MainWindow *ui;
    ChatClient *client_;
    void initUiSet();
};
#endif // MAINWINDOW_H
