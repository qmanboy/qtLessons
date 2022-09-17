#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    this->init();
}

void Dialog::rec_data(QByteArray const& text)
{
    ui->textBrowser->setText(text);
}

void Dialog::init()
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->setWindowTitle(tr("Help"));
    ui->textBrowser->setFixedSize(this->size());
}

void Dialog::set_lang()
{
    this->setWindowTitle(tr("Help"));
}

Dialog::~Dialog()
{
    delete ui;
}
