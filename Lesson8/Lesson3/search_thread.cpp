#include "search_thread.h"

QString SearchClass::recoursiveSearch(QString dirS)
{
    if (fileStr.isEmpty())
        return fileStr;
    QDir dir;
    dir.setPath(dirS);
    QFileInfoList listDir = dir.entryInfoList(QDir::Filter::Dirs);
    QStringList listDirNames = dir.entryList(QDir::Filter::Dirs);
    QStringList listFiles = dir.entryList(QDir::Filter::Files);
    if (listFiles.count() > 0)
    {
        for (auto const& file : std::as_const(listFiles))
        {
            if (file.toUpper() == fileStr.toUpper())
            {
                resultPath = dir.path()+ ((dir.path().at(dir.path().count()-1) == '/') ? "" : "/") + file;
                isFounded = true;
                return resultPath;
            }
        }
    }
    if (listDirNames.count() > 0)
    {
        for (auto const& direct : std::as_const(listDirNames))
        {
            if (direct.toUpper() == fileStr.toUpper())
            {
                resultPath = dir.path()+ ((dir.path().at(dir.path().count()-1) == '/') ? "" : "/") + direct;
                isFounded = true;
                return resultPath;
            }
        }
    }
    for (auto const& direct : std::as_const(listDir))
    {        
        if (isFounded)
            return resultPath;
        if (direct.filePath() == dirS + "/." || direct.filePath() == dirS + "/..")
            continue;
        recoursiveSearch(direct.filePath());
    }
    return NULL;
}

void SearchClass::getData(const QString& dir,const QString& file)
{
    dirStr = dir;
    fileStr = file;
    emit searchSignal();
}


void SearchClass::search()
{
    auto file = this->recoursiveSearch(dirStr);
    emit findedFile(file);
}


