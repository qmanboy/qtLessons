#include <QCoreApplication>
#include <QDebug>
#include "chatserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ChatServer chatServer(49999, qApp);

    return a.exec();
}
