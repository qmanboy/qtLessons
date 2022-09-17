#ifndef PATHWIDGET_H
#define PATHWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QTreeView>
#include <QComboBox>
#include <QPushButton>
#include <QStandardItemModel>
#include <QApplication>
#include <QDir>
#include <QFileSystemModel>
#include <QHeaderView>
#include <QDebug>
#include <QLineEdit>
#include <QListView>
#include <QFileInfoList>
#include <QCommonStyle>
#include <QSize>
#include <QTimer>


class pathwidget : public QWidget
{
    Q_OBJECT
public:
    pathwidget(QWidget *parent = nullptr);
    ~pathwidget(){delete list; list = nullptr;};
    QFileSystemModel *getCurrentFsModel() const {return fsModel;}
    QListView *getList() {return listView;}
    QComboBox *getCombo() {return disckSelBox;}
    QLineEdit *getPathString() {return pathString;}
    QPushButton *getUpButton() {return upButton;}
    QLineEdit *getSearchString() {return searchString;}
    QPushButton *getSearchButton() {return searchButton;}
private:
    QListView *listView{nullptr};
    QComboBox *disckSelBox{nullptr};
    QLineEdit *pathString{nullptr};
    QFileInfoList *list{nullptr};
    QPushButton *upButton{nullptr};
    QPushButton *searchButton{nullptr};
    QLineEdit *searchString{nullptr};

    QFileSystemModel *fsModel{nullptr};
    QString currentPath;
    QString dirFilter{};

signals:
    void openFile(const QString& path);
    void modelRebuilded(const QString& str);

public slots:
    void rebuild_model(const QString& str);
    void set_focus(const QString& str);
    void set_dir_filter(const QString& str);

private slots:
    void chgDisk(int index);
    void on_double_clicked(const QModelIndex &index);
    void on_up_button_clicked();
};


#endif // PATHWIDGET_H
