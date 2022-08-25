#ifndef SETTINGS_H
#define SETTINGS_H
#include "hotkeys.h"

#include <QDialog>
#include <QStandardItem>
#include <QTranslator>
#include <QDebug>


namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);    
    ~Settings();


    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    void on_click_accept();

public slots:
    void set_lang(const QString& lang);
    void fillHotKeys(QVector<HotKey>* Hkeys);

    void set_dark_scheme();
    void set_light_scheme();


signals:
    void addHotKeys(QVector<QString>& keys);
    void sendLang(const QString& language);
    void updateHostKeysView(QVector<HotKey>* updatedKeysVector);

    void darkScheme();
    void lightScheme();

private:
    void init();
    void initText();
    void translate(const QString& lang);

    Ui::Settings *ui;
    QTranslator translator;

    QString langFilePath{};
    QStandardItemModel *hotkeys;

    void initHotKeysView();

    const QString checkLang();
    void checkColorSchemeSignal();
    void switchLang(const QString& language);
    QVector<QString>& checkHotKeys();
    QVector<HotKey>* hotKeysVector;
    void fillHotKeysVector(size_t position, Qt::KeyboardModifiers modif, Qt::Key key);
};

#endif // SETTINGS_H
