#include "pathwidget.h"

pathwidget::pathwidget(QWidget *parent) : QWidget(parent)
{
    size_t gridSize = 16;
    size_t iconSize = gridSize - 1;
    listView = new QListView(this);
    listView->setIconSize(QSize(iconSize,iconSize));
    listView->setGridSize(QSize(gridSize,gridSize));

    disckSelBox = new QComboBox(this);
    pathString = new QLineEdit(this);
    pathString->setReadOnly(true);

    upButton = new QPushButton(this);
    QCommonStyle style;
    upButton->setIcon(style.standardIcon(QStyle::SP_ArrowUp));
    connect(upButton, &QPushButton::clicked, this, &pathwidget::on_up_button_clicked);

    QFileInfoList list = QDir::drives();
    QFileInfoList::const_iterator listdisk = list.begin();

    int amount = list.count();
    for (int i = 0; i < amount; i++)
    {
        disckSelBox->addItem(listdisk->path());
        listdisk++;
    }
    if (amount > 0)
    {
        rebuild_model(list.at(0).path());
    }
    connect(disckSelBox, SIGNAL(activated(int)), this, SLOT(chgDisk(int)));
    connect(listView, &QListView::doubleClicked, this, &pathwidget::on_double_clicked);
}

void pathwidget::rebuild_model(const QString& str)
{
    int pos{};
    if (!str.isEmpty())
    {
        QString newStr = str.left(str.indexOf('/'))+'/';
        for (int idx = 0; idx < disckSelBox->count(); idx++)
        {
             if (disckSelBox->itemText(idx) == newStr)
             {
                 disckSelBox->setCurrentIndex(idx);
                 continue;
             }
        }
        pos = str.lastIndexOf(QChar('/'));
        currentPath = str.left(pos+1);
    }
    else
        currentPath = disckSelBox->itemText(disckSelBox->currentIndex());

    QString rootPath = disckSelBox->itemText(disckSelBox->currentIndex());
    if (currentPath != rootPath)
        currentPath = str.left(pos);
    fsModel = new QFileSystemModel(this);
    fsModel->setRootPath(rootPath);
    fsModel->setReadOnly(true);

    pathString->setText(currentPath);
    listView->setModel(fsModel);
    listView->setRootIndex(fsModel->index(currentPath));
}

void pathwidget::on_double_clicked(const QModelIndex &index)
{
    if (fsModel->fileInfo(index).isDir())
    {
        currentPath = fsModel->fileInfo(index).absoluteFilePath();
        listView->setRootIndex(fsModel->index(currentPath));
        pathString->setText(currentPath);
    }
}

void pathwidget::on_up_button_clicked()
{
    QString lineEditText = pathString->text();
    QString rootPath = disckSelBox->itemText(disckSelBox->currentIndex());
    int pos = lineEditText.lastIndexOf(QChar('/'));
    currentPath = lineEditText.left(pos+1);
    if (currentPath != rootPath)
        currentPath = lineEditText.left(pos);
    listView->setRootIndex(fsModel->index(currentPath));
    pathString->setText(currentPath);

}

void pathwidget::chgDisk(int index)
{
    QFileInfoList list = QDir::drives();
    rebuild_model(list.at(index).path());
}


