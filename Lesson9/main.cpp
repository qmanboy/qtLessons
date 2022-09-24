#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QDir>
#include <QQuickView>
#include <maincore.h>


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    auto filepath = QDir::currentPath() + "/tasks.json";

    MainCore core(filepath, qApp);

    engine.rootContext()->setContextProperty("MainCore", &core);

    if (core.getMode() == Mode::FileReady)
        QMetaObject::invokeMethod(engine.rootObjects().at(0), "createModel");


    return app.exec();
}
