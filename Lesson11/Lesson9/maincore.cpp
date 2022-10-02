#include "maincore.h"

MainCore::MainCore(const QString& filepath, QObject *parent)
                : QObject(parent), filepath_(filepath)
{
    mode_ = initCore();
    this->updateState();
}

MainCore::~MainCore()
{
    delete model_;
    model_ = nullptr;
}

void MainCore::addTask(const QString &task, const QString &date, const QString &progress)
{
    QSqlQuery query;
    if (query.exec("insert into " + tablename_ + " values(" + QString::number(last_index_ + 1)
                                + ", '" + task + "', '" + date + "', '" + progress + "')"))
    {
        last_index_++;
        mode_ = Mode::FileReady;
    }
    this->updateState();
}

int MainCore::getItemCount() const
{
    return tasks_.count();
}

Mode MainCore::getMode() const
{
    return mode_;
}

QString MainCore::getTask(int index)
{
    return (tasks_.at(index).toObject().value("task").toString());
}

QString MainCore::getDeadLine(int index)
{
    return (tasks_.at(index).toObject().value("deadline").toString());
}

QString MainCore::getProgress(int index)
{
    return (tasks_.at(index).toObject().value("progress").toString());
}

void MainCore::openTable()
{
    if (mode_ == Mode::FileReady)
    {
        QDialog *dialog = new QDialog();
        dialog->setWindowTitle("Текущие задачи");
        dialog->setFixedSize(640,480);
        QTableView *view = new QTableView(dialog);
        view->setModel(model_);
        view->resizeRowsToContents();
        view->resizeColumnsToContents();
        view->verticalHeader()->hide();
        view->horizontalHeader()->setStretchLastSection(true);
        view->setColumnWidth(1, dialog->width()/2);
        view->hideColumn(0);
        view->resize(dialog->size());
        view->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        connect(dialog, &QDialog::finished, dialog, &QDialog::deleteLater);
        dialog->show();
    }
    if (mode_ == Mode::FileEmpty)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Текущие задачи");
        msgBox.setText("Текущие задачи отсутствуют");
        msgBox.exec();
    }
}

Mode MainCore::initCore()
{
    tablename_ = "tasks";
    db_ = QSqlDatabase::addDatabase("QSQLITE");
    db_.setDatabaseName(QDir::currentPath() +"/TasksDataBase.db");
    if (!db_.open())
    {
        return Mode::Error;
    }
    QSqlQuery query;
    if (query.exec("create table if not exists " + tablename_ +" (id int primary key, "
               "task varchar(200), deadline varchar(20), progress varchar(2))"))
    {
        query.exec("select count(*) from " + tablename_);
        if (query.next())
        {
            last_index_ = query.value(0).toInt();
            if (query.value(0).toInt() == 0)
                return Mode::FileEmpty;
        }
    }
    return Mode::FileReady;
}

void MainCore::setModel()
{
    model_ = new QSqlTableModel;
    model_->setTable(tablename_);
    model_->select();
    model_->setHeaderData(1, Qt::Horizontal, tr("Задача"));
    model_->setHeaderData(2, Qt::Horizontal, tr("Срок окончания выполнения"));
    model_->setHeaderData(3, Qt::Horizontal, tr("Прогресс"));
}

void MainCore::updateState()
{
    if (mode_ == Mode::FileReady)
        this->setModel();
}


