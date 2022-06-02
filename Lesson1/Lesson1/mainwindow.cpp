#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmath.h"
#include "qfont.h"
#include "qcolor.h"

void setTextAndSize(const QString& str, QLabel* label) //изменение длины label под содержимое
{
    label->clear();
    QFont font = QFont::substitute(str);
    label->resize(qPow(font.weight(), 2), label->height());
    label->setText(str);
}

QString calculate(double a, double b, double c) //расчет квадратного уравнения
{
    QString result;
    if (a != 0)
    {
        double D = qPow(b,2) - 4*a*c;
        if (D < 0)
        {
            result = "Нет корней";
        } else if (D > 0)
        {
            double x1 = (-b - qSqrt(D))/(2*a);
            double x2 = (-b + qSqrt(D))/(2*a);
            result = "x1 = " + QString::number(x1) + ", x2 = " + QString::number(x2);
        } else
        {
            double x = -b/(2*a);
            result = "x = " + QString::number(x);
        }
    }
    else
    {
        double y = -c/b;
        result = "x = " + QString::number(y);
    }

    return result;
}

QString calculateTriangle(double a, double b, double c, bool rad) //расчет стороны трегольника
{
    QString result;
    float y;
    if (!rad)
        y = qDegreesToRadians(c);
    else
        y = c;
    double x = qSqrt(qPow(a,2)+qPow(b,2) - 2*a*b*qCos(y));
    result = "Сторона С = " + QString::number(x);

    return result;
}




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
        this->init();
}

void MainWindow::init()
{
    // Задание 1 инит
    ui->setupUi(this);
    ui->CalculateButton->setText("Рассчитать");
    ui->ResultLabel->setAlignment(Qt::AlignVCenter);
    ui->ResultLabel->setText("");
    ui->label_2->setText(QString::fromStdWString(L"x\u00B2 + x = 0"));
    ui->label_3->setText("x +");
    ui->label_4->setText("= 0");
    connect(ui->CalculateButton, &QPushButton::clicked, this, &MainWindow::on_click);

    // Задание 2 инит
    ui->label_7->setText("Сторона А");
    ui->label_8->setText("Сторона В");
    ui->label_9->setText("Угол АВ");
    ui->DegressRadio->setText("Градусы");
    ui->DegressRadio->setChecked(1);
    ui->RadiansRadio->setText("Радианы");
    ui->CalculateButton_2->setText("Рассчитать");
    ui->ResultLabel_2->setAlignment(Qt::AlignVCenter);
    ui->ResultLabel_2->setText("");
    connect(ui->CalculateButton_2, &QPushButton::clicked, this, &MainWindow::on_click_2);

     // Задание 3 инит
     ui->Button_3->setText("Первая");
     connect(ui->Button_3, &QPushButton::clicked, this, &MainWindow::on_click_3);
     ui->Button_4->setText("Вторая");
     connect(ui->Button_4, &QPushButton::clicked, this, &MainWindow::on_click_4);
     ui->Button_5->setText("Третья");
     connect(ui->Button_5, &QPushButton::clicked, this, &MainWindow::on_click_5);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_click()
{
    if (ui->numAedit->toPlainText() != "" ||
        ui->numBedit->toPlainText() != "" ||
        ui->numCedit->toPlainText() != "")
    {
        setTextAndSize(calculate(ui->numAedit->toPlainText().toInt(),
                                    ui->numBedit->toPlainText().toInt(),
                                    ui->numCedit->toPlainText().toInt()),
                        ui->ResultLabel);
    }
    else
    {
        setTextAndSize("Ошибка ввода", ui->ResultLabel);
    }
}

void MainWindow::on_click_2()
{
    if (ui->sideAedit->toPlainText() != "" ||
        ui->sideBedit->toPlainText() != "" ||
        ui->angleABedit->toPlainText() != "")
    {
       setTextAndSize(calculateTriangle(ui->sideAedit->toPlainText().toInt(),
                                        ui->sideBedit->toPlainText().toInt(),
                                        ui->angleABedit->toPlainText().toInt(),
                                        ui->RadiansRadio->isChecked()),
                      ui->ResultLabel_2);
    }
    else
    {
        setTextAndSize("Ошибка ввода", ui->ResultLabel_2);
    }
}

void MainWindow::on_click_3()
{
    if (ui->textEdit_1->toPlainText() != "")
    {
        ui->textEdit_2->setText(ui->textEdit_1->toPlainText());
    }
}

void MainWindow::on_click_4()
{
    if (ui->textEdit_1->toPlainText() != "" ||
        ui->textEdit_2->toPlainText() != "")
    {

        QString buffer =  ui->textEdit_2->toPlainText();
        ui->textEdit_2->setText(ui->textEdit_1->toPlainText());
        ui->textEdit_1->setText(buffer);
    }
}

void MainWindow::on_click_5()
{
    ui->textEdit_1->setHtml("<font color='red'>Hello</font>");
    ui->textEdit_2->setHtml("<font color='blue'>world</font>");
}



