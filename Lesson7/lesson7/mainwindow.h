#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <unordered_map>
#include <functional>
#include <ctime>

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QScrollEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum class Dir
{
    up, down
};

class ItemEventFilter;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    QRectF makeRect(int x, int y);
    QRectF makeRectForEllipse(int x, int y);
    QPolygonF makePolygon(int x, int y);

    ItemEventFilter* filter{};

    Ui::MainWindow *ui;
    QGraphicsScene scene;

    size_t figure_counter{0};
    double scaleRatio{1.0};

    void setRatio(Dir dir);
};
#endif // MAINWINDOW_H
