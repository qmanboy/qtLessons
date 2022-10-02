#ifndef MAINCORE_H
#define MAINCORE_H

#include <QGuiApplication>
#include <QAbstractItemDelegate>
#include <QMessageBox>
#include <QObject>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QQmlApplicationEngine>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>
#include <QHeaderView>
#include <QDialog>

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

    Q_INVOKABLE void openTable();

signals:
    void fillModel();

private:
    const QString filepath_{};
    Mode mode_{Mode::Error};
    QJsonDocument json_doc_;
    QJsonArray tasks_;
    int last_index_{};

    QSqlDatabase db_;
    QString tablename_{};
    QSqlTableModel* model_{nullptr};


    Mode initCore();
    void setModel();
    void writeJson();
    void updateState();
};

#endif // MAINCORE_H
