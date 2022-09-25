#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include <QDebug>
#include <QTranslator>
#include <QTimer>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

public slots:
    void rec_data(QByteArray const& text);
    void set_lang();

private:
    void init();
    Ui::Dialog *ui;
};

#endif // DIALOG_H
