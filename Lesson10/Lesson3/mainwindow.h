#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "hotkeys.h"
#include "pathwidget.h"
#include "search_thread.h"

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
#include <QDateTime>
#include <QStyle>

struct ColorTheme: public QWidget
{
    Q_OBJECT
public:
    ColorTheme()
    {
        light = this->style()->standardPalette();
        dark.setColor(QPalette::Window, QColor(53, 53, 53));
        dark.setColor(QPalette::WindowText, Qt::white);
        dark.setColor(QPalette::Base, QColor(25, 25, 25));
        dark.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
        dark.setColor(QPalette::ToolTipBase, Qt::white);
        dark.setColor(QPalette::ToolTipText, Qt::white);
        dark.setColor(QPalette::Text, Qt::white);
        dark.setColor(QPalette::Button, QColor(53, 53, 53));
        dark.setColor(QPalette::ButtonText, Qt::white);
        dark.setColor(QPalette::BrightText, Qt::red);
        dark.setColor(QPalette::Link, QColor(42, 130, 218));
        dark.setColor(QPalette::Highlight, QColor(42, 130, 218));
        dark.setColor(QPalette::HighlightedText, Qt::black);
    }
    QPalette dark;
    QPalette light;
};

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
    void newSendLang();
    void sendLangToSet(const QString& lang);
    void disableLang();
    void sendHotKeys(QVector<HotKey>* hotkeys);
    void initLang(const QString& lang);
    void sendFilePath(const QString& path);
    void sendFilePathToModel(const QString& path);
    void updateLang();


    void hotkeys_open();
    void hotkeys_save();
    void hotkeys_new();
    void hotkeys_quit();
    void hotkeys_print();

    void setEmpty(bool empty);
    void indexSignal(int index);

    void senData(const QString& dir, const QString& file);
    void searchSignal();
    void sendDirFilter(const QString& filter);

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
    void close_help();
    void close_settings();
    void set_lang(const QString& lang);
    void update_lang(const QString& lang);
    void set_filepath_to_tab(const QString& str);

    void update_tabs_slot();
    void set_cur_text_edit_slot(int index);
    void set_button_text(bool empty);
    void set_font();
    void set_align(Align align);

    void custom_context(const QPoint& point);
    void remove_tab(int index);    

    void search_slot() ;

private:
    void init();
    void initText();
    bool checkTabs(const QString& path);
    bool pathWidgetOpenFileFlag{false};
    bool helpIsOpen{false};
    bool settIsOpen{false};
    bool langIsEnabled{true};
    void setFontBuf(QTextCharFormat charFormat);
    void clearFontBuf();
    void createTextEdit();
    void addDateTime(const QString& type);


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
    QString searchButtonText{};

    ResourseReadErrorMsg errorMsg;
    QString mainWindowLanguage{};
    QVector<HotKey> hotKeys;
    ColorTheme colorTheme;
};
#endif // MAINWINDOW_H
