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


class pathwidget : public QWidget
{
    Q_OBJECT
public:
    pathwidget(QWidget *parent = nullptr);
    ~pathwidget(){delete list; list = nullptr;};
    //void clearTree();
    QFileSystemModel *getCurrentFsModel() const {return fsModel;}
    //QTreeView *getTree() {return tree;}
    QListView *getList() {return listView;}
    QComboBox *getCombo() {return disckSelBox;}
    QLineEdit *getPathString() {return pathString;}
    QPushButton *getUpButton() {return upButton;}
private:
    //QTreeView *tree;
    QListView *listView{nullptr};
    QComboBox *disckSelBox{nullptr};
    QLineEdit *pathString{nullptr};
    QFileInfoList *list{nullptr};
    QPushButton *upButton{nullptr};

    //QStandardItemModel *model{nullptr};
    QFileSystemModel *fsModel{nullptr};
    QString currentPath;
    //QQueue<QString> pathParser(const QString& str);


public slots:
    void rebuild_model(const QString& str);

private slots:
    void chgDisk(int index);
    void on_double_clicked(const QModelIndex &index);
    void on_up_button_clicked();
};


#endif // PATHWIDGET_H
