#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    this->init();
}

void Settings::fillHotKeysVector(size_t position, Qt::KeyboardModifiers modif, Qt::Key key)
{
    (hotKeysVector->begin()+position)->setKey(modif, key);
    emit updateHostKeysView(hotKeysVector);
}

bool Settings::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == this && event->type() == QEvent::KeyPress)
    {
        auto key_event = static_cast<QKeyEvent*>(event);
        QKeySequence qseq = key_event->key() + key_event->modifiers();
        if (key_event->modifiers() == Qt::NoModifier)
        {
            fillHotKeysVector(ui->tableView->selectionModel()->currentIndex().row(), key_event->modifiers(), static_cast<Qt::Key>(key_event->key()));
            this->removeEventFilter(this);
            return true;
        }
    }
    return QDialog::eventFilter(watched, event);
}

void Settings::translate(const QString& lang)
{
    if (translator.load(lang))
    {
        qApp->installTranslator(&translator);
        ui->retranslateUi(this);
        this->initText();
    }
}

void Settings::init()
{
    ui->setupUi(this);

    connect(ui->pushButtonOk, &QPushButton::clicked, this, &Settings::on_click_accept);
    connect(this, &Settings::updateHostKeysView, this, &Settings::fill_hotkeys);

    this->setFixedSize(this->size());
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->radioButtonEng->setChecked(true);

    if (qApp->palette() == colorTheme.light)
        ui->radioButtonLight->setChecked(true);
    else
        ui->radioButtonDark->setChecked(true);

    connect(this, &Settings::lightScheme, this, &Settings::set_light_scheme);
    connect(this, &Settings::darkScheme, this, &Settings::set_dark_scheme);

    hotkeys = new QStandardItemModel(this);
    ui->tableView->setModel(hotkeys);
    connect(ui->tableView, &QTableView::doubleClicked, this, [&]()
            {
                installEventFilter(this);
                hotkeys->setData(ui->tableView->selectionModel()->currentIndex(), "", Qt::EditRole);
            });
    this->initText();    
}

void Settings::set_lang(const QString& lang)
{
    if (ui->groupBoxLang->isEnabled())
    {
        langFilePath = lang;
        auto l = lang.mid(lang.lastIndexOf('_')+1, lang.count());
        l == "ru" ? ui->radioButtonRu->setChecked(true) : ui->radioButtonEng->setChecked(true);
        this->translate(lang);
    }
    else
        ui->radioButtonEng->setChecked(true);
}

void Settings::initText()
{
    ui->labelHotKeys->setText(tr("Hot Keys"));
    this->setWindowTitle(tr("Settings"));
    ui->pushButtonOk->setText(tr("Accept"));
    ui->radioButtonRu->setText(tr("Russian"));
    ui->radioButtonEng->setText(tr("English"));
    ui->groupBoxScheme->setTitle(tr("Color scheme"));
    ui->groupBoxLang->setTitle(tr("Language"));
    ui->radioButtonDark->setText(tr("Dark"));
    ui->radioButtonLight->setText(tr("Light"));

    this->initHotKeysView();
}

void Settings::initHotKeysView()
{
    QStringList header_labels{tr("Hot Key"),tr("Description")};
    hotkeys->setHorizontalHeaderLabels(header_labels);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->resizeContentsPrecision();
    ui->tableView->verticalHeader()->hide();
}

void Settings::fill_hotkeys(QVector<HotKey>* Hkeys)
{
    hotkeys->clear();
    initHotKeysView();
    size_t row = 0;
    for (const HotKey &key : std::as_const(*Hkeys))
    {

        QList<QStandardItem*> list;
        for(size_t column = 0; column < 2; column++)
        {
            QStandardItem* item = new QStandardItem(row++,column);
            if (column == 0)
                item->setText(key.getName());
            else
                item->setText(key.getDescription());
            list.push_back(item);
        }
        hotkeys->appendRow(list);
    }
    hotKeysVector = Hkeys;
}


const QString Settings::checkLang()
{
    if (ui->groupBoxLang->isEnabled())
    {
        if (ui->radioButtonRu->isChecked())
            return "ru";
        else
            return "eng";
    }
    else
        return NULL;
}

void Settings::checkColorSchemeSignal()
{
    if (ui->radioButtonLight->isChecked())
        emit lightScheme();
    else
        emit darkScheme();
}

void Settings::set_dark_scheme()
{
    qApp->setPalette(colorTheme.dark);
}

void Settings::set_light_scheme()
{
    qApp->setPalette(colorTheme.light);
}

void Settings::disable_lang()
{
    ui->groupBoxLang->setDisabled(true);
}


void Settings::on_click_accept()
{
    checkColorSchemeSignal();
    const QString lang = this->checkLang();
    if (!lang.isEmpty())
    {
        auto langPath = langFilePath.mid(0, langFilePath.lastIndexOf('_')+1) + lang;
        emit sendLang(lang);
        this->translate(langPath);
        emit sendLang(lang);
        emit updateHostKeysView(hotKeysVector);
    }
}


Settings::~Settings()
{
    delete ui;
}
