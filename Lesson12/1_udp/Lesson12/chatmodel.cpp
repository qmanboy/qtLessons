#include "chatmodel.h"

ChatModel::ChatModel()
{
    model_ = new QStandardItemModel;
}

void ChatModel::addItem(const QString &msg)
{
    QStandardItem* item = new QStandardItem();
    item->setText(msg);
    model_->appendRow(item);
}

ChatModel::~ChatModel()
{
    delete model_;
}

QStandardItemModel* ChatModel::getModel()
{
    return model_;
}
