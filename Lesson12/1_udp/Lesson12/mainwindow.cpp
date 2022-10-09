#include "mainwindow.h"
#include "network.h"
#include "chatmodel.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->setWindowTitle("BroadChats");

    ui->nameLabel->setText("Name > ");
    ui->sendButton->setText("Send message");
    ui->chatList->setWordWrap(true);
    ui->chatList->setEditTriggers(QAbstractItemView::NoEditTriggers);

    network_ = new TcpConnection(44661);
    chatmodel_ = new ChatModel;

    ui->chatList->setModel(chatmodel_->getModel());

    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::sendMsg);

    connect(network_, &TcpConnection::receivedMsg, chatmodel_, &ChatModel::addItem);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete network_;
    delete chatmodel_;
}

void MainWindow::sendMsg()
{
    if (!ui->nameEdit->text().isEmpty() && !ui->msgEdit->toPlainText().isEmpty())
    {
        network_->sendMessage(ui->nameEdit->text(), ui->msgEdit->toPlainText());
        ui->msgEdit->clear();
        ui->msgEdit->setFocus();
    }
    else
    {
        if (ui->nameEdit->text().isEmpty())
            ui->nameEdit->setFocus();
        else
            ui->msgEdit->setFocus();
    }

}


