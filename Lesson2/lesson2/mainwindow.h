#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QAbstractItemModel>
#include <QAbstractItemView>
#include <memory>

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
    void add_line_click();                                                          //добавление новой позиции
    void remove_line_click();                                                       //удаление выбранной позиции
    void up_line_click();                                                           //сдвиг вверх/влево выбранной позиции
    void down_line_click();                                                         //сдвиг вниз/вправо выбранной позиции
    void checkbox_checked();                                                        //Icon Mode

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;                                                      //модель для ListView
    std::vector<QStandardItem*> list;                                               //список для заполнения модели
    QString IconDir;                                                                //директория расположения иконок

    void init();                                                                    //инициализация окна(fillModel, добавление названий кнопок, очищение Linedit, setListView, setUpDownButtonView)
    void set_icon_dir(QString dirpath);                                             //задание директории расположения иконок
    QString get_icon_dir(){return this->IconDir;}                                   //геттер получения директории иконок
    void setListView(bool state, QAbstractItemView* listView);                      //установка вида ListView в соответсвии с Icon Mode
    QModelIndex get_current_index(int value, QStandardItemModel* model);            //получение корректного индекса строки для перемещения
    void setUpDownButtonView(bool state, QWidget* upButton, QWidget* downButton);   //установка отображения названий кнопок перемещения в соответствии с Icon Mode
    void fillModel();                                                               //заполнение модели данными из list
};
#endif // MAINWINDOW_H
