#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->init();
}

void MainWindow::init()
{
    ui->setupUi(this);

    this->setFixedSize(this->size());

    ui->pushButtonOpen->setText("Open");
    connect(ui->pushButtonOpen,&QPushButton::clicked, this, &MainWindow::on_click_open);

    ui->pushButtonSave->setText("Save");
    connect(ui->pushButtonSave,&QPushButton::clicked, this, &MainWindow::on_click_save);

    ui->pushButtonHelp->setText("Help");
    connect(ui->pushButtonHelp,&QPushButton::clicked, this, &MainWindow::on_click_help);

    ui->pushButtonHelpClose->setText("Close Help");
    connect(ui->pushButtonHelpClose,&QPushButton::clicked, this, &MainWindow::on_click_help_close);
    ui->pushButtonHelpClose->setHidden(true);


    dirFilter = "Text(*.txt)";
    helpFilePath = ":/Help/help_text.txt";

}

void MainWindow::on_click_open()
{
    QFile file(QFileDialog::getOpenFileName(this, "Open file", QDir::currentPath(), dirFilter));
    if (file.open(QIODevice::ReadOnly))
    {
        QByteArray byteArray = file.readAll();
        ui->textEdit->setText(tr(byteArray.data()));
    }
}

void MainWindow::on_click_save()
{
    QFile file(QFileDialog::getSaveFileName(this, "Save file", QDir::currentPath(), dirFilter));
    if (file.open(QIODevice::WriteOnly))
    {
        QString text = ui->textEdit->toPlainText();
        QByteArray textData = text.toUtf8();
        file.write(textData, textData.length());
    }
}

void MainWindow::on_click_help()
{
    QFile file(helpFilePath);
    if (file.open(QIODevice::ReadOnly))
    {
        textBuffer = ui->textEdit->toPlainText();
        QByteArray byteArray = file.readAll();
        ui->textEdit->setText(tr(byteArray.data()));
        ui->textEdit->setReadOnly(true);
        ui->pushButtonOpen->setDisabled(true);
        ui->pushButtonSave->setDisabled(true);
        ui->pushButtonHelp->setHidden(true);
        ui->pushButtonHelpClose->setHidden(false);
    }
}

void MainWindow::on_click_help_close()
{
    ui->textEdit->setText(textBuffer);
    ui->textEdit->setReadOnly(false);
    ui->pushButtonOpen->setDisabled(false);
    ui->pushButtonSave->setDisabled(false);
    ui->pushButtonHelp->setHidden(false);
    ui->pushButtonHelpClose->setHidden(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

