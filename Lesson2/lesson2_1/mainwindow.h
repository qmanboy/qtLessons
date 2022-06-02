#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class RowData
{
public:
    RowData(QString num_, QString name_, QString ip_, QString mac_)
            : number(num_), name(name_),ip(ip_), mac(mac_)
    {
        list.push_back(number);
        list.push_back(name);
        list.push_back(ip);
        list.push_back(mac);
    };
    size_t size() const {return list.size();}
    std::vector<QString> list;
private:
    QString number;
    QString name;
    QString ip;
    QString mac;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void paintButtonClick();
    //void selectTableRow();

private:
    Ui::MainWindow *ui;
    std::vector<RowData> table;
    QStandardItemModel* model;

    void init();
    void fillModel();
    void initListView();
};
#endif // MAINWINDOW_H
