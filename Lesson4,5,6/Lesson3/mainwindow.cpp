#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "settings.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->init();
    installEventFilter(this);
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == this && event->type() == QEvent::KeyPress)
    {
        auto key_event = static_cast<QKeyEvent*>(event);
        for (const HotKey& key : hotKeys)
        {
            if (key_event->modifiers() == key.getModifier() && key_event->key() == key.getKey())
            {
                switch (key.getAction())
                {
                    case Action::open:
                        emit hotkeys_open();
                        break;
                    case Action::save:
                        emit hotkeys_save();
                        break;
                    case Action::quit:
                        emit hotkeys_quit();
                        break;
                    case Action::newDoc:
                        emit hotkeys_new();
                        break;
                    case Action::print:
                        emit hotkeys_print();
                        break;
                }
                return true;
            }
        }
    }

    return QMainWindow::eventFilter(watched, event);
}

void MainWindow::init()
{
    ui->setupUi(this);

    qApp->setPalette(style()->standardPalette());

    pWg = new pathwidget();

    QHBoxLayout *hor_layout = new QHBoxLayout(this);
    tab = new QTabWidget(this);

    tab->addTab(ui->textEdit, QString(filepath));

    ui->verticalLayout_2->addLayout(hor_layout);

    ui->verticalLayout->addWidget(tab);

    hor_layout->addWidget(pWg->getCombo());
    hor_layout->addWidget(pWg->getUpButton());
    pWg->getCombo()->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    pWg->getUpButton()->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

    ui->verticalLayout_2->addWidget(pWg->getList());
    ui->verticalLayout_2->addWidget(pWg->getPathString());

    ui->splitter->setStretchFactor(0,0);
    ui->splitter->setStretchFactor(1,1);

    connect(this, &MainWindow::sendFilePath, pWg, &pathwidget::rebuild_model);

    connect(this, &MainWindow::hotkeys_open, this, &MainWindow::on_click_open);
    connect(this, &MainWindow::hotkeys_save, this, &MainWindow::on_click_save);
    connect(this, &MainWindow::hotkeys_quit, this, &MainWindow::quit_slot);
    connect(this, &MainWindow::hotkeys_new, this, &MainWindow::new_doc_slot);
    connect(this, &MainWindow::hotkeys_print, this, &MainWindow::print_slot);

    connect(this, &MainWindow::initLang, this, &MainWindow::set_lang);

    connect(this, &MainWindow::sendFilePath, this, &MainWindow::set_filepath_to_tab);

    mainWindowLanguage = "eng";

    this-> initText();

    hotKeys.push_back(HotKey(Qt::ControlModifier, Qt::Key_N, &newFileText, Action::newDoc));
    hotKeys.push_back(HotKey(Qt::ControlModifier, Qt::Key_O, &openFileText, Action::open));
    hotKeys.push_back(HotKey(Qt::ControlModifier, Qt::Key_S, &saveFileText, Action::save));    
    hotKeys.push_back(HotKey(Qt::ControlModifier, Qt::Key_P, &printText, Action::print));
    hotKeys.push_back(HotKey(Qt::ControlModifier, Qt::Key_Q, &quitText, Action::quit));

    this->setWindowTitle(tr("NoobTextEditor"));
    newDocFileName = "New_file.txt";

    dirFilter = "Text(*.txt)";

    errorMsg.name = "Error";

    helpFilePath = ":/Help/help_text.txt";

    langFilePath = "D:/GB/QtProjects/Lesson3/QtLanguage_";
    emit initLang(mainWindowLanguage);

    this->createMenu();

    newFilePath = QDir::currentPath();
}

void MainWindow::initText()
{
    readOnlyTextPath = tr("(read only)");
    if (!ui->textEdit->isReadOnly() && !filepath.isEmpty())
        this->setWindowTitle(filepath);
    else
        if (filepath.isEmpty())
            this->setWindowTitle("NoobTextEditor");
        else
            this->setWindowTitle(filepath+readOnlyTextPath);

    printText = tr("Print");
    readOnlyText = tr("Open Read Only");
    helpText = tr("Help");
    settingsText = tr("Settings");
    fileText = tr("File");
    instrText = tr("Instruments");
    aboutText = tr("About");
    openFileText = tr("Open");
    saveAsFileText = tr("Save as..");
    saveFileText = tr("Save");
    newFileText = tr("New");
    errorMsg.text = tr("Read error");
    quitText = tr("Quit");
}

QKeySequence MainWindow::getHotKey(Action action)
{
    for (const HotKey &key : hotKeys)
    {
        if (key.getAction() == action)
            return (key.getModifier()+key.getKey());
    }
    return (Qt::AltModifier + Qt::Key_0);
}

void MainWindow::set_filepath_to_tab(const QString& str)
{
    this->tab->setTabText(tab->currentIndex(), str);
}

void MainWindow::createMenu()
{
    menuBar()->clear();
    auto menu = new QMenu{fileText};
    menu->addAction(newFileText, [this] {new_doc_slot();}, getHotKey(Action::newDoc));
    menu->addAction(openFileText, [this] {on_click_open();}, getHotKey(Action::open));
    menu->addAction(readOnlyText, [this] {on_click_read_only();});
    menu->addAction(saveFileText, [this] {on_click_save();}, getHotKey(Action::save));
    menu->addAction(saveAsFileText, [this] {on_click_save_as();});
    menu->addAction(printText, [this] {print_slot();}, getHotKey(Action::print));
    menu->addSeparator();
    menu->addAction(quitText, [this] {quit_slot();}, getHotKey(Action::quit));
    menuBar()->addMenu(menu);

    menu = new QMenu{instrText};
    menu->addAction(settingsText, [this] {on_click_settings();});
    menuBar()->addMenu(menu);

    menu = new QMenu{aboutText};
    menu->addAction(helpText, [this] {on_click_help();});
    menuBar()->addMenu(menu);
}

void MainWindow::new_doc_slot()
{
    ui->textEdit->clear();
    QString buf = filepath;
    filepath = newFilePath + "/" + newDocFileName;
    QFile file(filepath);
    if (!filepath.isEmpty())
    {

        ui->textEdit->setReadOnly(false);
        //ui->pushButtonSave->setEnabled(true);
        QFile file(filepath);
        if (file.open(QIODevice::WriteOnly))
        {
            QString text = ui->textEdit->toPlainText();
            QByteArray textData = text.toUtf8();
            file.write(textData, textData.length());
            file.close();
        }
        if (file.open(QIODevice::ReadOnly))
        {
            QByteArray byteArray = file.readAll();
            ui->textEdit->setText(byteArray.data());
            this->setWindowTitle(filepath);
            file.close();
        }
    }
    else
        filepath = buf;
    emit sendFilePath(filepath);

}

void MainWindow::quit_slot()
{
    qApp->closeAllWindows();
}

void MainWindow::on_click_settings()
{
    //ui->pushButtonSettings->setDisabled(true);
    Settings *sett = new Settings(this);
    connect(sett, &Settings::sendLang, this, &MainWindow::set_lang);
    connect(sett, &Settings::finished, this, &MainWindow::enable_settings_button);
    connect(this, &MainWindow::sendLang, sett, &Settings::set_lang);
    connect(this, &MainWindow::sendHotKeys, sett, &Settings::fillHotKeys);
    connect(sett, &Settings::sendLang, this, &MainWindow::createMenu);
    emit sendHotKeys(&hotKeys);
    emit sendLang(mainWindowLanguage);
    sett->show();
}

QStringList MainWindow::printPage(QString &str)
{
    QChar *list = str.data();
    QStringList strlst;
    int separator = 125;
    int cursor = 0;

    if (str.size() >= separator)
    {
        if (str.indexOf('\n', cursor) == -1)
        {
            str.insert(str.size(), '\n');
            for (int idx = separator; idx < str.size(); idx+=separator)
            {
                str.insert(idx, '\n');
            }
        }
        else
            for (bool getst = true; getst;)
            {
                int index = str.indexOf('\n', cursor);
                if (index == -1)
                {
                    getst = false;
                }
                else
                    for (int idx = cursor; idx < index; idx+=separator)
                    {
                        str.insert(idx, '\n');
                    }
                cursor = index + 1;
            }
    }

    for (bool getst = true; getst;)
    {
        int index = str.indexOf('\n', cursor); // Ищем перевод каретки на новую строк

        QString s = "";
        if (index == -1)
        {
            getst = false;
            s.append(&list[cursor], str.length() - cursor);
        }
        else
            s.append(&list[cursor], index - cursor);
        cursor = index + 1;
        strlst << s;
    }
    return strlst;
}

void MainWindow::print_slot()
{
    QPrinter printer;
    QPrintDialog dlg(&printer, this);
    dlg.setWindowTitle(printText);
    if (dlg.exec() != QDialog::Accepted)
        return;

    QString printStr = ui->textEdit->toPlainText();
    QStringList strlst = this->printPage(printStr);
    int line = 50;

    QPainter painter;
    painter.begin(&printer);
    int w = painter.window().width();
    int h = painter.window().height();
    int amount = strlst.count();
    qDebug() << "w-" <<  w << "h-" <<  h << amount;
    QFont font = painter.font();
    QFontMetrics fmetrics(font);

    for (int i = 0; i < amount; i++)
    {
        QPointF pf;
        pf.setX(50);
        pf.setY(line);
        painter.drawText(pf, strlst.at(i));
        line += fmetrics.height();
        if (h - line <= fmetrics.height())
        {
            printer.newPage();
            line = 0;
        }
    }
    painter.end();
}

void MainWindow::on_click_read_only()
{
    QString buf = filepath;
    filepath = QFileDialog::getOpenFileName(this, openFileText, QDir::currentPath(), dirFilter);
    if (!filepath.isEmpty())
    {
        QFile file(filepath);
        if (file.open(QIODevice::ReadOnly))
        {
            QByteArray byteArray = file.readAll();
            ui->textEdit->setText(byteArray.data());
            this->setWindowTitle(filepath+readOnlyTextPath);
            ui->textEdit->setReadOnly(true);
            //ui->pushButtonSave->setDisabled(true);
            file.close();
        }
    }
    else
        filepath = buf;    
    emit sendFilePath(filepath);
}

void MainWindow::on_click_open()
{
    QString buf = filepath;
    filepath = QFileDialog::getOpenFileName(this, openFileText, QDir::currentPath(), dirFilter);
    if (!filepath.isEmpty())
    {

        ui->textEdit->setReadOnly(false);
       // ui->pushButtonSave->setEnabled(true);
        QFile file(filepath);
        if (file.open(QIODevice::ReadOnly))
        {
            QByteArray byteArray = file.readAll();
            ui->textEdit->setText(byteArray.data());
            this->setWindowTitle(filepath);
            file.close();
        }
    }
    else
        filepath = buf;    
    emit sendFilePath(filepath);
}

void MainWindow::enable_help_button()
{
    //ui->pushButtonHelp->setEnabled(true);
}

void MainWindow::enable_settings_button()
{
    //ui->pushButtonSettings->setEnabled(true);
}

void MainWindow::on_click_save()
{   
    QString buf = filepath;
    filepath = filepath.isEmpty() ? QFileDialog::getSaveFileName(this, saveAsFileText, QDir::currentPath(), dirFilter) : filepath;
    if (!filepath.isEmpty() && !ui->textEdit->isReadOnly())
    {
        //ui->textEdit->setReadOnly(false);
        //ui->pushButtonSave->setEnabled(true);
        QFile file(filepath);
        if (file.open(QIODevice::WriteOnly))
        {
            QString text = ui->textEdit->toPlainText();
            QByteArray textData = text.toUtf8();
            file.write(textData, textData.length());
            this->setWindowTitle(filepath);
            file.close();
        }
    }
    else
        filepath = buf;
}

void MainWindow::on_click_save_as()
{
    QString buf = filepath;
    filepath = QFileDialog::getSaveFileName(this, saveAsFileText, QDir::currentPath(), dirFilter);
    if (!filepath.isEmpty())
    {        
        ui->textEdit->setReadOnly(false);
        //ui->pushButtonSave->setEnabled(true);
        QFile file(filepath);
        if (file.open(QIODevice::WriteOnly))
        {
            QString text = ui->textEdit->toPlainText();
            QByteArray textData = text.toUtf8();
            file.write(textData, textData.length());
            this->setWindowTitle(filepath);
            file.close();
        }
    }
    else
        filepath = buf;    
    emit sendFilePath(filepath);
}

void MainWindow::on_click_help()
{
    QFile file(helpFilePath);
    if (file.open(QIODevice::ReadOnly))
    {
        //ui->pushButtonHelp->setDisabled(true);
        QByteArray byteArray = file.readAll();
        Dialog *dial = new Dialog(this);
        connect(this, &MainWindow::sendData, dial, &Dialog::rec_data);
        connect(dial, &Dialog::finished, this, &MainWindow::enable_help_button);
        connect(this, &MainWindow::sendLang, dial, &Dialog::set_lang);
        emit sendData(byteArray);
        emit sendLang(mainWindowLanguage);
        dial->show();
        file.close();
    }
    else
    {
        QMessageBox::critical(this, errorMsg.name, errorMsg.text);
    }
}

void MainWindow::set_lang(const QString& lang)
{
    translator.load(langFilePath+lang);
    qApp->installTranslator(&translator);
    mainWindowLanguage = lang;
    emit sendLang(lang);
    ui->retranslateUi(this);
    this->initText();
}

MainWindow::~MainWindow()
{
    delete ui;
}

