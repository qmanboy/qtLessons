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

    searchString = new QLineEdit(this);
    searchButton = new QPushButton(this);

    upButton = new QPushButton(this);
    QCommonStyle style;
    upButton->setIcon(style.standardIcon(QStyle::SP_ArrowUp));
    connect(upButton, &QPushButton::clicked, this, &pathwidget::on_up_button_clicked);

    QFileInfoList list = QDir::drives();
    QFileInfoList::iterator listdisk = list.begin();

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

        QString rootPath = disckSelBox->itemText(disckSelBox->currentIndex());
        if (currentPath != rootPath)
            currentPath = str.left(pos);
        fsModel = new QFileSystemModel(this);
        fsModel->setRootPath(rootPath);
        fsModel->setReadOnly(true);

        pathString->setText(currentPath);
        listView->setModel(fsModel);
        listView->setRootIndex(fsModel->index(currentPath));
        emit modelRebuilded(str);
    }
}

void pathwidget::set_focus(const QString &str)
{
    auto model = static_cast<QFileSystemModel*>(listView->model());
    listView->setCurrentIndex(model->index(str));
    QTimer::singleShot(20, this, [this]{listView->scrollTo(listView->currentIndex());});
}

void pathwidget::set_dir_filter(const QString &str)
{
    if (!str.isEmpty())
        dirFilter = str.mid(str.lastIndexOf('.')+1, str.count());
}

void pathwidget::on_double_clicked(const QModelIndex &index)
{
    if (fsModel->fileInfo(index).isDir())
    {
        currentPath = fsModel->fileInfo(index).absoluteFilePath();
        listView->setRootIndex(fsModel->index(currentPath));
        pathString->setText(currentPath);
    }
    if (fsModel->fileInfo(index).isFile())
    {
        auto file = fsModel->fileInfo(index);
        if (!dirFilter.isEmpty())
        {
            if (file.suffix() == dirFilter)
                emit openFile(file.absoluteFilePath());
        }
        else
            emit openFile(file.absoluteFilePath());

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


