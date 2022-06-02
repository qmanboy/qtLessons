#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size()); //установка фиксированного размера главного окна
    this->init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    this->fillModel();

    ui->listView->setModel(model);
    setListView(ui->IconModeCheckBox->checkState(), ui->listView);

    ui->IconModeCheckBox->setText("Icon Mode");
    connect(ui->IconModeCheckBox, &QCheckBox::clicked, this, &MainWindow::checkbox_checked);

    ui->AddpushButton->setText("Add");
    connect(ui->AddpushButton, &QPushButton::clicked, this, &MainWindow::add_line_click);

    ui->AddlineEdit->clear();

    ui->RemovepushButton->setText("Remove");
    connect(ui->RemovepushButton, &QPushButton::clicked, this, &MainWindow::remove_line_click);

    setUpDownButtonView(ui->IconModeCheckBox->checkState(), ui->upButton, ui->downButton);

    connect(ui->upButton, &QPushButton::clicked, this, &MainWindow::up_line_click);

    connect(ui->downButton, &QPushButton::clicked, this, &MainWindow::down_line_click);
}

void MainWindow::set_icon_dir(QString dirpath)
{
    this->IconDir = dirpath;
}

void MainWindow::fillModel()
{
    this->set_icon_dir("C:/Users/kuchur_sv/lesson2/img/");

    list.push_back(std::unique_ptr<QStandardItem>(new QStandardItem(QIcon(this->get_icon_dir()+"js.png"),  "Javascript")).release());
    list.push_back(std::unique_ptr<QStandardItem>(new QStandardItem(QIcon(this->get_icon_dir()+"c#.png"),  "C#")).release());
    list.push_back(std::unique_ptr<QStandardItem>(new QStandardItem(QIcon(this->get_icon_dir()+"php.png"), "PHP")).release());
    list.push_back(std::unique_ptr<QStandardItem>(new QStandardItem(QIcon(this->get_icon_dir()+"java.png"),"Java")).release());
    list.push_back(std::unique_ptr<QStandardItem>(new QStandardItem(QIcon(this->get_icon_dir()+"py.png"),  "Python")).release());

    model = std::unique_ptr<QStandardItemModel>(new QStandardItemModel(this)).release();


    for (const auto &el : list)
    {
        model->appendRow(el);
    }
}

void MainWindow::setUpDownButtonView(bool state, QWidget* upButton, QWidget* downButton)
{
    if (state)
    {
        static_cast<QPushButton*>(upButton)->setText("<");
        static_cast<QPushButton*>(downButton)->setText(">");
    }
    else
    {
        static_cast<QPushButton*>(upButton)->setText("/\\");
        static_cast<QPushButton*>(downButton)->setText("\\/");
    }
}

void MainWindow::setListView(bool state, QAbstractItemView* listView)
{
    if (state)
        static_cast<QListView*>(listView)->setViewMode(QListView::ViewMode::IconMode);
    else
        static_cast<QListView*>(listView)->setViewMode(QListView::ViewMode::ListMode);
}

QModelIndex MainWindow::get_current_index(int value, QStandardItemModel* model)
{
    if (value < 0)
    {
        value = model->rowCount() - 1;
    }
    if (value > model->rowCount() - 1)
    {
        value = 0;
    }
    return (model->index(value, 0));
}

void MainWindow::add_line_click()
{
    if (!ui->AddlineEdit->text().isEmpty()) {
        model->appendRow(std::unique_ptr<QStandardItem>(new QStandardItem(QIcon(this->get_icon_dir()+"default.png"), ui->AddlineEdit->text())).release());
        ui->AddlineEdit->clear();
    }
}

void MainWindow::remove_line_click()
{
    auto selection_model = ui->listView->selectionModel();
    if (selection_model->hasSelection())
    {
        auto select_index = selection_model->currentIndex();
        if (select_index.isValid())
        {
            model->removeRow(select_index.row());
        }
    }
}

void MainWindow::up_line_click()
{
    auto selection_model = ui->listView->selectionModel();
    if (selection_model->hasSelection())
    {
        auto select_index = selection_model->currentIndex();
        if (select_index.isValid())
        {
            QModelIndex index = get_current_index(select_index.row() - 1, model);
            model->insertRow(index.row(), model->takeRow(select_index.row()));
            selection_model->setCurrentIndex(index, QItemSelectionModel::ClearAndSelect);
        }
        ui->listView->setSelectionModel(selection_model);

    }
}

void MainWindow::down_line_click()
{
    auto selection_model = ui->listView->selectionModel();
    if (selection_model->hasSelection())
    {
        auto select_index = selection_model->currentIndex();
        if (select_index.isValid())
        {
            QModelIndex index = get_current_index(select_index.row() + 1, model);
            model->insertRow(index.row(), model->takeRow(select_index.row()));
            selection_model->setCurrentIndex(index, QItemSelectionModel::ClearAndSelect);
        }
        ui->listView->setSelectionModel(selection_model);

    }
}

void MainWindow::checkbox_checked()
{
    setListView(ui->IconModeCheckBox->checkState(), ui->listView);
    setUpDownButtonView(ui->IconModeCheckBox->checkState(), ui->upButton, ui->downButton);
}



