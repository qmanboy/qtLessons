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
    void on_click();
    void on_click_2();
    void on_click_3();
    void on_click_4();
    void on_click_5();

private:
    void init();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
