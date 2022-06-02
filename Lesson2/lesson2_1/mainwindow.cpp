#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    ui->paintButton->setText("Paint");
    connect(ui->paintButton, &QPushButton::clicked, this, &MainWindow::paintButtonClick);

    model = new QStandardItemModel(this);
    ui->tableView->setModel(model);
    this->initListView();
    connect(ui->tableView, &QTableView::clicked, this, [&](){
            ui->tableView->selectRow(ui->tableView->selectionModel()->currentIndex().row());
            });
}

void MainWindow::fillModel()
{
    table.push_back(RowData("1", "Acer", "192.168.1.120","00:26:57:00:1f:02"));
    table.push_back(RowData("2", "Asus", "192.168.1.121","00:26:57:00:1d:03"));
    table.push_back(RowData("3", "Lenovo", "192.168.1.122","00:26:57:00:4a:01"));
    table.push_back(RowData("4", "HP", "192.168.1.123","00:26:57:00:dc:42"));

    for(size_t row = 0; row < table.size(); row++)
    {
        QList<QStandardItem*> list;
        for(size_t column = 0; column< table[0].size(); column++)
        {
            QStandardItem* item = new QStandardItem(row,column);
            item->setText(table[row].list[column]);
            list.push_back(item);
        }
        model->appendRow(list);
    }

}

void MainWindow::initListView()
{
    QStringList header_labels{"№","Name","IP","MAC"};
    model->setHorizontalHeaderLabels(header_labels);
    ui->tableView->verticalHeader()->hide();
    fillModel();
}


void MainWindow::paintButtonClick()
{

    QModelIndexList index_list = ui->tableView->selectionModel()->selectedRows();
    for (auto el : qAsConst(index_list))
    {
        for(size_t idx = 0; idx < (size_t)ui->tableView->model()->columnCount(); ++idx)
        {
            ui->tableView->model()->setData(ui->tableView->model()->index(el.row(), idx), QColor(Qt::green), Qt::BackgroundRole);
        }
    }
    ui->tableView->selectionModel()->clear();
}


