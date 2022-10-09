#ifndef CHATMODEL_H
#define CHATMODEL_H

#include <QStandardItemModel>


class ChatModel: public QObject
{
    Q_OBJECT
public:
    ChatModel();
    ~ChatModel();
    QStandardItemModel* getModel();

public slots:
    void addItem(const QString& msg);

private:
    QStandardItemModel* model_;
};

#endif // CHATMODEL_H
