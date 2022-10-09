#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initUiSet();
    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::sendMsg);
    connect(ui->connectButton, &QPushButton::clicked, this, &MainWindow::connectToServer);
    connect(this, &MainWindow::connected, ui->sendButton, &QPushButton::setEnabled);
    connect(this, &MainWindow::connected, ui->lineEdit, &QLineEdit::setReadOnly);
    connect(this, &MainWindow::connected, ui->textEdit, &QPushButton::setEnabled);
    connect(this, &MainWindow::connected, ui->connectButton, &QPushButton::setDisabled);
    this->setFixedSize(this->size());
}

void MainWindow::initUiSet()
{
    ui->sendButton->setDisabled(true);
    ui->textEdit->setDisabled(true);
    ui->lineEdit->setFocus();
    ui->label->setText("Name > ");
    ui->sendButton->setText("Send");
    ui->connectButton->setText("Connect");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::recvMsg(const QString &msg)
{
    ui->textBrowser->insertPlainText(msg);
}

void MainWindow::sendMsg()
{
    if (!ui->textEdit->toPlainText().isEmpty())
    {
        QDateTime dTime;
        QString time = dTime.currentDateTime().time().toString();
        QString message = "[" + time + "] " + ui->lineEdit->text() + " >> " + ui->textEdit->toPlainText() + "\n";
        emit sendToClient(message);
        ui->textEdit->clear();
        ui->textEdit->setFocus();
    }
}

void MainWindow::connectToServer()
{

    if (!ui->lineEdit->text().isEmpty())
    {
        client_ = new ChatClient(QHostAddress::LocalHost, 49999, this);
        if (client_->isConnect())
        {
            emit connected(client_->isConnect());
            connect(client_, &ChatClient::disconnectSignal, this, &MainWindow::connected);
            connect(client_, &ChatClient::sendToWindow, this, &MainWindow::recvMsg);
            connect(this, &MainWindow::sendToClient, client_, &ChatClient::sendMsg);
            ui->textEdit->setFocus();
        }
        else
            delete client_;
    }
    else
        ui->lineEdit->setFocus();
}



