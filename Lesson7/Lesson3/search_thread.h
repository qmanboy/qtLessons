#ifndef SEARCH_THREAD_H
#define SEARCH_THREAD_H

#include <QObject>
#include <QThread>
#include <QDir>
#include <QDebug>
#include <QMutex>
#include <QWaitCondition>

class SearchClass: public QObject
{
    Q_OBJECT
    public:
        void search();
    private:
        QString dirStr{};
        QString fileStr{};
        QString resultPath{};
        bool isFounded{false};

        QString recoursiveSearch(QString dirS);
    public slots:
        void getData(const QString& dir,const QString& filename);
    signals:
        void findedFile(QString);
        void searchSignal();
};

#endif
