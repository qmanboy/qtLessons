#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_click_open();
    void on_click_save();
    void on_click_help();
    void on_click_help_close();

private:
    void init();
    Ui::MainWindow *ui;
    QString dirFilter{};
    QString helpFilePath{};
    QString textBuffer{};
};
#endif // MAINWINDOW_H
