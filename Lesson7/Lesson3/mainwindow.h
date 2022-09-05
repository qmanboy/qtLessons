#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "hotkeys.h"
#include "pathwidget.h"

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTranslator>
#include <QKeyEvent>
#include <QHBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QTabWidget>
#include <QToolBar>
#include <QTextDocumentFragment>
#include <QTextEdit>
#include <QFontDialog>

enum class Align
{
    left, center, right
};

struct ResourseReadErrorMsg
{
    QString name;
    QString text;
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    bool eventFilter(QObject *watched, QEvent *event) override;

signals:
    void sendData(QByteArray const& text);
    void sendLang(const QString& lang);    
    void sendHotKeys(QVector<HotKey>* hotkeys);
    void initLang(const QString& lang);
    void sendFilePath(const QString& path);
    void sendFilePathToModel(const QString& path);


    void hotkeys_open();
    void hotkeys_save();
    void hotkeys_new();
    void hotkeys_quit();
    void hotkeys_print();

    void setEmpty(bool empty);

public slots:
    void create_menu();
    void create_toolbar();
    void font_slot();

private slots:
    void on_click_open();
    void on_click_save();
    void on_click_save_as();
    void on_click_help();
    void on_click_read_only();
    void on_click_settings();

    void print_slot();
    void quit_slot();
    void new_doc_slot();
    void enable_help_button();
    void enable_settings_button();
    void set_lang(const QString& lang);
    void set_filepath_to_tab(const QString& str);

    void update_tabs_slot();
    void set_cur_text_edit_slot(int index);
    void set_button_text(bool empty);
    void set_font();
    void set_align(Align align);

private:
    void init();
    void initText();
    bool checkTabs(const QString& path);
    void setFontBuf(QTextCharFormat charFormat);
    void clearFontBuf();

    QKeySequence getHotKey(Action action);
    QTextCharFormat charFormatBuffer;
    Ui::MainWindow *ui;    
    QTranslator translator;
    pathwidget* pWg;
    QTabWidget* tab;
    QTextEdit* curTextEdit;
    QAction *copyFont;
    QToolBar * tBar;


    bool fontBufIsEmpty{true};
    QString filepath{};
    QString dirFilter{};
    QString helpFilePath{};
    QString openFileText{};
    QString saveFileText{};
    QString saveAsFileText{};
    QString readOnlyTextPath{};
    QString winTitle{};
    QString langFilePath{};
    QString newDocFileName{};
    QString quitText{};
    QString newFileText{};
    QString newFilePath{};

    QString fileText{};
    QString instrText{};
    QString aboutText{};

    QString helpText{};
    QString settingsText{};
    QString readOnlyText{};
    QString printText{};

    QString copyFontText{};
    QString pasteFontText{};
    QString alignText{};
    QString fontText{};
    QString alignLeftText{};
    QString alignRightText{};
    QString alignCenterText{};

    ResourseReadErrorMsg errorMsg;
    QString mainWindowLanguage{};
    QVector<HotKey> hotKeys;
};
#endif // MAINWINDOW_H
