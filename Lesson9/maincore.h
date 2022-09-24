#ifndef MAINCORE_H
#define MAINCORE_H

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QQmlApplicationEngine>

struct Task
{
   QString task_;
   QString date_;
   QString progress_;
   Task(QString task, QString date, QString progress):
       task_(task), date_(date), progress_(progress){};
};

//Q_DECLARE_METATYPE(Task)

enum class Mode
{
    FileReady,
    FileEmpty,
    Error
};

class MainCore : public QObject
{
    Q_OBJECT
public:
    explicit MainCore(const QString& filepath, QObject *parent = nullptr);
    ~MainCore();

    Q_INVOKABLE void addTask(const QString& task, const QString& date, const QString& progress);
    Q_INVOKABLE int getItemCount() const;
    Q_INVOKABLE Mode getMode() const;
    Q_INVOKABLE QString getTask(int index);
    Q_INVOKABLE QString getDeadLine(int index);
    Q_INVOKABLE QString getProgress(int index);

signals:
    void fillModel();

private:
    const QString filepath_{};
    Mode mode_{Mode::Error};
    QJsonDocument json_doc_;
    QJsonArray tasks_;


    Mode initCore();
    void readJson();
    void writeJson();
};

#endif // MAINCORE_H
