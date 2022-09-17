#include "mainwindow.h"
#include "search_thread.h"
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
        for (const HotKey& key : std::as_const(hotKeys))
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

    qApp->setPalette(colorTheme.dark);

    pWg = new pathwidget();

    connect(this, &MainWindow::sendDirFilter, pWg, &pathwidget::set_dir_filter);
    connect(pWg, &pathwidget::openFile, this, [this](QString path)
                                                    {
                                                        pathWidgetOpenFileFlag = true;
                                                        filepath = path;
                                                        this->on_click_open();
                                                    });

    QHBoxLayout *hor_layout = new QHBoxLayout(this);
    QHBoxLayout *hor_layout_2 = new QHBoxLayout(this);
    tab = new QTabWidget(this);
    tab->setTabsClosable(true);

    this->createTextEdit();

    ui->verticalLayout_2->addLayout(hor_layout);

    ui->verticalLayout->addWidget(tab);

    hor_layout->addWidget(pWg->getCombo());
    hor_layout->addWidget(pWg->getUpButton());
    pWg->getCombo()->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    pWg->getUpButton()->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

    ui->verticalLayout_2->addWidget(pWg->getList());
    ui->verticalLayout_2->addLayout(hor_layout_2);

    hor_layout_2->addWidget(pWg->getSearchString());
    hor_layout_2->addWidget(pWg->getSearchButton());

    pWg->getSearchButton()->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    ui->verticalLayout_2->addSpacing(10);
    ui->verticalLayout_2->addWidget(pWg->getPathString());

    ui->splitter->setStretchFactor(0,0);
    ui->splitter->setStretchFactor(1,1);

    connect(tab, &QTabWidget::tabBarClicked, this, &MainWindow::set_cur_text_edit_slot);    
    connect(tab, &QTabWidget::tabCloseRequested, this, &MainWindow::remove_tab);

    //connect(this, &MainWindow::sendFilePath, pWg, &pathwidget::rebuild_model);
    connect(this, &MainWindow::sendFilePathToModel, pWg, &pathwidget::rebuild_model);

    connect(this, &MainWindow::hotkeys_open, this, &MainWindow::on_click_open);
    connect(this, &MainWindow::hotkeys_save, this, &MainWindow::on_click_save);
    connect(this, &MainWindow::hotkeys_quit, this, &MainWindow::quit_slot);
    connect(this, &MainWindow::hotkeys_new, this, &MainWindow::new_doc_slot);
    connect(this, &MainWindow::hotkeys_print, this, &MainWindow::print_slot);

    connect(this, &MainWindow::initLang, this, &MainWindow::set_lang);
    connect(this, &MainWindow::updateLang, this, &MainWindow::create_menu);
    connect(this, &MainWindow::updateLang, this, &MainWindow::create_toolbar);

    connect(this, &MainWindow::sendFilePath, this, &MainWindow::set_filepath_to_tab);

    connect(pWg->getSearchButton(), &QPushButton::clicked, this, &MainWindow::search_slot);

    mainWindowLanguage = "ru";

    this-> initText();

    hotKeys.push_back(HotKey(Qt::ControlModifier, Qt::Key_N, &newFileText, Action::newDoc));
    hotKeys.push_back(HotKey(Qt::ControlModifier, Qt::Key_O, &openFileText, Action::open));
    hotKeys.push_back(HotKey(Qt::ControlModifier, Qt::Key_S, &saveFileText, Action::save));    
    hotKeys.push_back(HotKey(Qt::ControlModifier, Qt::Key_P, &printText, Action::print));
    hotKeys.push_back(HotKey(Qt::ControlModifier, Qt::Key_Q, &quitText, Action::quit));

    this->setWindowTitle(tr("NoobTextEditor"));
    newDocFileName = "New_file.txt";

    //dirFilter = "*.txt";
    emit sendDirFilter(dirFilter);

    errorMsg.name = "Error";

    helpFilePath = ":/Help/help_text.txt";

    langFilePath = "D:/GB/QtProjects/from/Lesson3/QtLanguage_";
    //langFilePath = "/home/serge/Документы/qtLessons/tmp/qtLessons-master/Lesson7/Lesson3/QtLanguage_";


    emit initLang(mainWindowLanguage);

    tBar = nullptr;

    this->create_toolbar();

    emit setEmpty(fontBufIsEmpty);

    this->create_menu();

    newFilePath = QDir::currentPath();
}

void MainWindow::initText()
{
    readOnlyTextPath = tr("(read only)");

    this->setWindowTitle("NoobTextEditor");

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
    copyFontText = tr("Copy format");
    pasteFontText = tr("Paste format");
    alignText = tr("Alignment");
    fontText = tr("Font");
    alignLeftText = tr("Left");
    alignRightText = tr("Right");
    alignCenterText = tr("Center");
    searchButtonText = tr("Search");

    pWg->getSearchButton()->setText(searchButtonText);
}

void MainWindow::custom_context(const QPoint& point)
{
    auto context = curTextEdit->createStandardContextMenu();    
    if (!curTextEdit->isReadOnly())
    {
        QMenu *menu = new QMenu("Insert");
        menu->addAction("Date", this, [this]{addDateTime("date");});
        menu->addAction("Time", this, [this]{addDateTime("time");});
        context->addMenu(menu);
    }
    context->addAction("Open file direction in Finder", this, [this]{emit sendFilePathToModel(filepath);});
    context->exec(this->mapToGlobal(point));
}

void MainWindow::remove_tab(int index)
{
    if (tab->count() > 1)
    {
        tab->removeTab(index);
    }
}

void MainWindow::search_slot()
{
    QThread *searchTread = new QThread;
    pWg->getSearchButton()->setText("Searching...");
    pWg->getSearchButton()->setDisabled(true);
    pWg->getSearchString()->setDisabled(true);
    SearchClass *seArcher = new SearchClass();

    seArcher->moveToThread(searchTread);

    connect(this, &MainWindow::senData, seArcher, &SearchClass::getData);
    connect(seArcher, &SearchClass::findedFile, pWg, &pathwidget::rebuild_model);
    connect(pWg, &pathwidget::modelRebuilded, pWg, &pathwidget::set_focus);
    connect(seArcher, &SearchClass::searchSignal, seArcher, &SearchClass::search);

    connect(seArcher, &SearchClass::findedFile, searchTread, &QThread::quit);

    connect(searchTread, &QThread::finished, this, [this, seArcher, searchTread]()
                                                    {
                                                        pWg->getSearchButton()->setText("Search");
                                                        pWg->getSearchButton()->setEnabled(true);
                                                        pWg->getSearchString()->setEnabled(true);
                                                        pWg->getSearchString()->setFocus();
                                                        seArcher->deleteLater();
                                                        searchTread->deleteLater();
                                                    });

    searchTread->start();
    emit senData(pWg->getCombo()->itemText(pWg->getCombo()->currentIndex()), pWg->getSearchString()->text());
}

void MainWindow::set_button_text(bool empty)
{
    if (empty)
        copyFont->setIconText(copyFontText);
    else
        copyFont->setIconText(pasteFontText);
}

void MainWindow::setFontBuf(QTextCharFormat charFormat)
{
    charFormatBuffer = charFormat;
    fontBufIsEmpty = false;
    emit setEmpty(fontBufIsEmpty);
}

void MainWindow::clearFontBuf()
{
    fontBufIsEmpty = true;
    emit setEmpty(fontBufIsEmpty);
}

void MainWindow::createTextEdit()
{
    QTextEdit* textEd = nullptr;
    if (tab->count() == 0)
    {
        textEd = new QTextEdit(tab);
        tab->addTab(textEd, filepath);
        textEd->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
        curTextEdit = textEd;
        tab->setCurrentWidget(curTextEdit);
    }
    else
        if (tab->tabText(tab->currentIndex()).isEmpty())
        {
            curTextEdit = static_cast<QTextEdit*>(tab->currentWidget());
            curTextEdit->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
            return;
        }
        else
        {
            if (!filepath.isEmpty())
            {
                if (!checkTabs(filepath))
                {
                    textEd = new QTextEdit(tab);
                    tab->addTab(textEd, filepath);
                    textEd->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
                    tab->setCurrentWidget(textEd);
                    curTextEdit = textEd;
                }
                else
                {
                    for (int  idx = 0; idx < tab->count(); idx++)
                    {
                        if (tab->tabText(idx) == filepath)
                        {
                            tab->setCurrentIndex(idx);
                            curTextEdit = static_cast<QTextEdit*>(tab->currentWidget());
                        }
                    }

                }
            }
    }
    connect(curTextEdit, &QTextEdit::customContextMenuRequested, this, &MainWindow::custom_context);
}

void MainWindow::addDateTime(const QString& type)
{
    QDateTime dTime = QDateTime::currentDateTime();
    if (type == "date")
    {
        curTextEdit->insertPlainText(' ' + dTime.date().toString(Qt::DateFormat::LocalDate));
        return;
    }
    if (type == "time")
    {
        curTextEdit->insertPlainText(' ' + dTime.time().toString());
        return;
    }
}


void MainWindow::font_slot()
{
    if (curTextEdit != nullptr)
    {
        if (fontBufIsEmpty)
        {
            if (!curTextEdit->textCursor().selectedText().isEmpty())
            {
                QTextCharFormat fmt = curTextEdit->textCursor().charFormat();
                QTextCursor cursor = curTextEdit->textCursor();
                cursor.clearSelection();
                curTextEdit->setTextCursor(cursor);
                setFontBuf(fmt);
            }

        }
        else
        {
            if (!curTextEdit->textCursor().selectedText().isEmpty())
            {
                curTextEdit->textCursor().setCharFormat(charFormatBuffer);
                clearFontBuf();
            }
        }
    }
}

void MainWindow::set_font()
{
    if (curTextEdit != nullptr)
    {
        if (!curTextEdit->textCursor().selectedText().isEmpty())
        {
            QFont font = curTextEdit->textCursor().charFormat().font();
            QFontDialog fntDlg(font,this);
            bool b[] = {true};
            font = fntDlg.getFont(b);
            if (b[0])
            {
                QTextCharFormat fmt;
                fmt.setFont(font);
                curTextEdit->textCursor().setCharFormat(fmt);
            }
        }
        else
        {
            QFont font = curTextEdit->font();
            QFontDialog fntDlg(font,this);
            bool b[] = {true};
            font = fntDlg.getFont(b);
            if (b[0])
            {
                QTextCharFormat fmt;
                fmt.setFont(font);
                curTextEdit->setCurrentCharFormat(fmt);
            }
        }
    }
}

QKeySequence MainWindow::getHotKey(Action action)
{
    for (const HotKey &key : std::as_const(hotKeys))
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

void MainWindow::set_cur_text_edit_slot(int index)
{
    curTextEdit = static_cast<QTextEdit*>(tab->widget(index));
    filepath = tab->tabText(index);
    //emit sendFilePathToModel(filepath);
}

void MainWindow::create_toolbar()
{
    if (tBar != nullptr)
        this->removeToolBar(tBar);
    tBar = new QToolBar(this);
    this->addToolBar(tBar);
    copyFont = new QAction(tBar);
    copyFont->setIconText(copyFontText);
    tBar->addAction(copyFont);

    QAction *font = new QAction(tBar);
    font->setIconText(fontText);
    tBar->addAction(font);

    QMenu *align = new QMenu(tBar);
    align->setTitle(alignText);
    align->addAction(alignLeftText,     this, [this] {set_align(Align::left);});
    align->addAction(alignCenterText,   this, [this] {set_align(Align::center);});
    align->addAction(alignRightText,    this, [this] {set_align(Align::right);});

    QPushButton *menuButton = new QPushButton(tBar);
    menuButton->setText(alignText);
    menuButton->setMenu(align);
    tBar->addWidget(menuButton);


    connect(this, &MainWindow::setEmpty, this, &MainWindow::set_button_text);

    connect(copyFont, &QAction::triggered, this, &MainWindow::font_slot);
    connect(font, &QAction::triggered, this, &MainWindow::set_font);
}

void MainWindow::create_menu()
{
    menuBar()->clear();
    auto menu = new QMenu{fileText};
    menu->addAction(newFileText,    this, [this] {new_doc_slot();}, getHotKey(Action::newDoc));
    menu->addAction(openFileText,   this, [this] {on_click_open();}, getHotKey(Action::open));
    menu->addAction(readOnlyText,   this, [this] {on_click_read_only();});
    menu->addAction(saveFileText,   this, [this] {on_click_save();}, getHotKey(Action::save));
    menu->addAction(saveAsFileText, this, [this] {on_click_save_as();});
    menu->addAction(printText,      this, [this] {print_slot();}, getHotKey(Action::print));
    menu->addSeparator();
    menu->addAction(quitText,       this, [this] {quit_slot();}, getHotKey(Action::quit));
    menuBar()->addMenu(menu);

    menu = new QMenu{instrText};
    menu->addAction(settingsText,   this, [this] {on_click_settings();});
    menuBar()->addMenu(menu);

    menu = new QMenu{aboutText};
    menu->addAction(helpText,       this, [this] {on_click_help();});
    menuBar()->addMenu(menu);
}

void MainWindow::set_align(Align align)
{
    if (curTextEdit != nullptr)
    {
        switch (align)
        {
            case Align::left:
                curTextEdit->setAlignment(Qt::AlignLeft);
                break;
            case Align::center:
                curTextEdit->setAlignment(Qt::AlignHCenter);
                break;
            case Align::right:
                curTextEdit->setAlignment(Qt::AlignRight);
                break;
        }
    }
}

bool MainWindow::checkTabs(const QString& path)
{
    auto count = tab->count();
    for (int idx = 0; idx < count; idx++)
    {
        if (tab->tabText(idx) == path)
            return true;
    }
    return false;
}

void MainWindow::update_tabs_slot()
{
    /*auto count = tab->count();
    for (int idx = 0; idx < count; idx++)
    {
        tab->tabText(idx) = tab->tabText(idx);
    }*/
}

void MainWindow::new_doc_slot()
{
    QString buf = filepath;
    filepath = newFilePath + "/" + newDocFileName;

    this->createTextEdit();


    if (!filepath.isEmpty() && curTextEdit != nullptr)
    {
        QFile file(filepath);
        if (file.open(QIODevice::WriteOnly))
        {
            QString text = curTextEdit->toPlainText();
            QByteArray textData = text.toUtf8();
            file.write(textData, textData.length());
            file.close();
        }
        if (file.open(QIODevice::ReadOnly))
        {
            QByteArray byteArray = file.readAll();
            curTextEdit->setText(byteArray.data());
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
    if (!settIsOpen)
    {
        Settings *sett = new Settings(this);
        connect(this, &MainWindow::disableLang, sett,  &Settings::disable_lang);
        if (!langIsEnabled)
            emit disableLang();
        connect(sett, &Settings::sendLang, this, &MainWindow::update_lang);
        connect(this, &MainWindow::sendLangToSet, sett, &Settings::set_lang);
        connect(this, &MainWindow::sendHotKeys, sett, &Settings::fill_hotkeys);
        //connect(sett, &Settings::sendLang, this, &MainWindow::update_tabs_slot);
        connect(sett, &Settings::finished, this, &MainWindow::close_settings);
        connect(sett, &Settings::finished, sett, &Settings::deleteLater);
        emit sendHotKeys(&hotKeys);
        emit sendLangToSet(langFilePath+mainWindowLanguage);
        sett->show();
        settIsOpen = true;
    }
}

void MainWindow::print_slot()
{
    QPrinter printer;
    QPrintDialog dlg(&printer, this);
    dlg.setWindowTitle(printText);
    if (dlg.exec() != QDialog::Accepted)
        return;
    if (curTextEdit != nullptr)
        curTextEdit->print(&printer);
}

void MainWindow::on_click_read_only()
{
    QString buf = filepath;
    filepath = QFileDialog::getOpenFileName(this, openFileText, QDir::currentPath(), dirFilter);

    this->createTextEdit();

    if (!filepath.isEmpty() && curTextEdit != nullptr)
    {
        QFile file(filepath);
        if (file.open(QIODevice::ReadOnly))
        {
            QByteArray byteArray = file.readAll();

            curTextEdit->setText(byteArray.data());
            curTextEdit->setReadOnly(true);
            file.close();
        }        
        tab->setTabText(tab->currentIndex(), filepath+readOnlyTextPath);
    }
    else
        filepath = buf;
    emit sendFilePath(filepath);
}

void MainWindow::on_click_open()
{    
    QString buf = filepath;
    if (!pathWidgetOpenFileFlag)
        filepath = QFileDialog::getOpenFileName(this, openFileText, QDir::currentPath(), dirFilter);
    else
        pathWidgetOpenFileFlag = false;

    this->createTextEdit();

    if (!filepath.isEmpty() && curTextEdit != nullptr)
    {
        QFile file(filepath);
        if (file.open(QIODevice::ReadOnly))
        {
            QByteArray byteArray = file.readAll();
            curTextEdit->setText(byteArray.data());
            file.close();
        }
    }
    else
        filepath = buf;
    emit sendFilePath(filepath);
}

void MainWindow::close_help()
{
    helpIsOpen = false;
}

void MainWindow::close_settings()
{
    settIsOpen = false;
}

void MainWindow::on_click_save()
{   
    QString buf = filepath;
    filepath = filepath.isEmpty() ? QFileDialog::getSaveFileName(this, saveAsFileText, QDir::currentPath(), dirFilter) : filepath;
    if (!filepath.isEmpty())
    {
        if (curTextEdit != nullptr)
        {
            if (!curTextEdit->isReadOnly())
            {
                QFile file(filepath);
                if (file.open(QIODevice::WriteOnly))
                {
                    QString text = curTextEdit->toPlainText();
                    QByteArray textData = text.toUtf8();
                    file.write(textData, textData.length());
                    file.close();
                }
            }
        }
    }
    else
        filepath = buf;
    if (tab->tabText(tab->currentIndex()).isEmpty())
        emit sendFilePath(filepath);
}

void MainWindow::on_click_save_as()
{
    QString buf = filepath;
    filepath = QFileDialog::getSaveFileName(this, saveAsFileText, QDir::currentPath(), dirFilter);
    if (!filepath.isEmpty() && curTextEdit != nullptr)
    {
        QFile file(filepath);
        if (file.open(QIODevice::WriteOnly))
        {
            QString text =  curTextEdit->toPlainText();
            QByteArray textData = text.toUtf8();
            file.write(textData, textData.length());
            file.close();
        }
    }
    else
        filepath = buf;    
    emit sendFilePath(filepath);
}

void MainWindow::on_click_help()
{
    if (!helpIsOpen)
    {
        QFile file(helpFilePath);
        if (file.open(QIODevice::ReadOnly))
        {
            QByteArray byteArray = file.readAll();
            Dialog *dial = new Dialog(this);
            connect(this, &MainWindow::sendData, dial, &Dialog::rec_data);
            connect(dial, &Dialog::finished, this, &MainWindow::close_help);
            connect(dial, &Dialog::finished, dial, &Dialog::deleteLater);
            connect(this, &MainWindow::sendLang, dial, &Dialog::set_lang);
            emit sendData(byteArray);
            emit sendLang(langFilePath+mainWindowLanguage);
            dial->show();
            file.close();
        }
        else
        {
            QMessageBox::critical(this, errorMsg.name, errorMsg.text);
        }
        helpIsOpen = true;
    }
}

void MainWindow::set_lang(const QString& lang)
{
    if(translator.load(langFilePath+lang))
    {
        qApp->installTranslator(&translator);
        mainWindowLanguage = lang;
        emit sendLang(langFilePath+lang);
        ui->retranslateUi(this);
        this->initText();
    }
    else
    {
        QMessageBox::about(this, "Language settings not found...", "The programm will start with default language settings.");
        langIsEnabled = false;
    }
}

void MainWindow::update_lang(const QString& lang)
{
    mainWindowLanguage = lang;
    emit initLang(lang);
    emit updateLang();
    //ui->retranslateUi(this);
    //this->initText();
    //emit updateLang();
}

MainWindow::~MainWindow()
{
    delete ui;
}

