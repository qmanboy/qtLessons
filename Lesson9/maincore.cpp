#include "maincore.h"

MainCore::MainCore(const QString& filepath, QObject *parent)
                : QObject(parent), filepath_(filepath)
{
    mode_ = initCore();
    if (mode_ == Mode::FileReady)
        this->readJson();
}

MainCore::~MainCore()
{
    if (mode_ != Mode::Error && tasks_.count() != 0)
    {
        QFile file(filepath_);
        if(file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
        {
            QJsonDocument jsonDocument;
            jsonDocument.setArray(tasks_);
            QByteArray bytes = jsonDocument.toJson(QJsonDocument::Indented);
            QTextStream iStream(&file);
            iStream.setCodec("utf-8");
            iStream << bytes;
            file.close();
        }
    }
}

void MainCore::addTask(const QString &task, const QString &date, const QString &progress)
{
        QJsonObject taskItemObj;
        taskItemObj.insert("task", task);
        taskItemObj.insert("deadline", date);
        taskItemObj.insert("progress", progress);
        tasks_.push_back(taskItemObj);
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

Mode MainCore::initCore()
{
    QFile file(filepath_);
    if (file.open(QIODevice::ReadOnly))
    {
        QString val_from_json = file.readAll();
        if (val_from_json.isEmpty())
        {
            file.close();
            return Mode::FileEmpty;
        }
        file.close();
        return Mode::FileReady;
    }
    else
    {
        if (file.open(QIODevice::WriteOnly))
        {
            file.close();
            return Mode::FileEmpty;
        }
        else
        {
            return Mode::Error;
        }
    }
}

void MainCore::readJson()
{
    QFile file(filepath_);
    if (file.open(QIODevice::ReadOnly))
    {
        QString val_from_json = file.readAll();
        QJsonDocument doc(QJsonDocument::fromJson(val_from_json.toUtf8()));
        tasks_ = doc.array();
    }
}


