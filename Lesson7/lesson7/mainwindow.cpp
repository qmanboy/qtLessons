#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QtMath>
#include <QDebug>
#include <QWheelEvent>

constexpr int kEllWidth = 60;
constexpr int kEllHeight = 100;
constexpr int kRectWidth = 100;
constexpr int kRectHeight = 40;
constexpr int kStarRadius = 60;

constexpr double upRatio = 1.1;
constexpr double downRatio = 0.9;

class ItemEventFilter : public QGraphicsItem
{
public:
    QRectF boundingRect() const override {return {};}
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget* = 0) override {}

protected:
    bool sceneEventFilter(QGraphicsItem *watched, QEvent *event) override
    {
        if (move(watched, event))
        {
            return true;
        }
        /*if (rotate(watched, event))
        {
            qDebug() << "rotate" << watched->rotation();
            return true;
        }*/
        return false;
    }
private:
    bool move(QGraphicsItem* item, QEvent *event)
    {
        if (event->type() == QEvent::GraphicsSceneMousePress)
        {
            auto press = static_cast<QGraphicsSceneMouseEvent*>(event);
            if (press->button() == Qt::LeftButton)
            {
                item->setFlag(QGraphicsItem::ItemIsMovable, true);
                item->setCursor(Qt::ClosedHandCursor);
                return true;
            }
        }
        if (event->type() == QEvent::GraphicsSceneMouseRelease)
        {
            auto press = static_cast<QGraphicsSceneMouseEvent*>(event);
            if (press->button() == Qt::LeftButton)
            {
                item->setCursor(QCursor(Qt::ArrowCursor));
                item->setFlag(QGraphicsItem::ItemIsMovable, false);
                return true;
            }
        }
        return false;
    }

    /*bool rotate(QGraphicsItem* item, QEvent *event)
    {
        if (event->type() ==  QEvent::GraphicsSceneMousePress)
        {
            auto wheel = static_cast<QGraphicsSceneMouseEvent*>(event);
            if (wheel->button() == Qt::MiddleButton)
            {
                //item->setFlag(QGraphicsItem::ItemRotationChange);
                item->setFlag(QGraphicsItem::ItemIgnoresTransformations, true);
                item->setCursor(Qt::CursorShape::SizeVerCursor);
                return true;
            }

        }
        if (event->type() ==  QEvent::GraphicsSceneMouseRelease)
        {
            auto wheel = static_cast<QGraphicsSceneMouseEvent*>(event);
            if (wheel->button() == Qt::MiddleButton)
            {
                item->setCursor(QCursor(Qt::ArrowCursor));
                item->setFlag(QGraphicsItem::ItemIgnoresTransformations, false);
                return true;
            }

        }
        return false;
    }*/
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
     scene(this)
{
    ui->setupUi(this);
    QRectF scRect;
    scRect.setSize(ui->graphicsView->size());
    scene.setSceneRect(scRect);
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    ui->graphicsView->installEventFilter(this);

    filter = new ItemEventFilter{};
    scene.addItem(filter);
    setWindowTitle("Lesson 7");


    srand(time(NULL));
}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched != ui->graphicsView)
        return false;

    if (event->type() == QEvent::MouseButtonPress)
    {
        auto mouse_event = static_cast<QMouseEvent*>(event);
        if (mouse_event->button() == Qt::LeftButton)
        {
            QColor randColor = QColor(rand()%256, rand()%256, rand()%256);
            auto x = mouse_event->x();
            auto y = mouse_event->y();
            switch (figure_counter)
            {
                case 0:
                {
                    auto rect = makeRect(x, y);
                    auto item = scene.addRect(rect, QPen{Qt::PenStyle::SolidLine}, randColor);
                    item->installSceneEventFilter(filter);
                    figure_counter++;
                    break;
                }
                case 1:
                {
                    auto rect_1 = makeRectForEllipse(x, y);
                    auto item_1 = scene.addEllipse(rect_1, QPen{Qt::PenStyle::SolidLine}, randColor);
                    item_1->installSceneEventFilter(filter);
                    figure_counter++;
                    break;
                }
                case 2:
                {
                    auto poly = makePolygon(x, y);
                    auto item_2 = scene.addPolygon(poly, QPen{Qt::PenStyle::SolidLine}, randColor);
                    item_2->installSceneEventFilter(filter);
                    figure_counter = 0;
                    break;
                }
            }
            return true;
        }
        if (mouse_event->button() == Qt::RightButton)
        {
            scene.removeItem(scene.itemAt(ui->graphicsView->mapToScene(mouse_event->x(), mouse_event->y()), QTransform()));
            return true;
        }

    }
    if (event->type() ==  QEvent::Wheel)
    {
        auto scroll = static_cast<QWheelEvent*>(event);
        if (scroll->angleDelta().y() > 0)
        {
            this->setRatio(Dir::up);
            return true;
        }
        else
        {
            this->setRatio(Dir::down);
            return true;
        }
    }
    if (event->type() == QEvent::KeyPress)
    {
        auto key = static_cast<QKeyEvent*>(event);
        if (key->key() == Qt::Key::Key_Plus)
        {
            this->setRatio(Dir::up);
            return true;
        }
        if (key->key() == Qt::Key::Key_Minus)
        {
            this->setRatio(Dir::down);
            return true;
        }
    }
    return false;
}

QRectF MainWindow::makeRect(int x, int y)
{
    auto top_left_point = ui->graphicsView->mapToScene(x - kRectWidth / 2 * scaleRatio, y - kRectHeight / 2 * scaleRatio);
    auto bottom_right_point = ui->graphicsView->mapToScene(x + kRectWidth / 2 * scaleRatio, y + kRectHeight / 2 * scaleRatio);
    return QRectF(top_left_point, bottom_right_point);
}

QRectF MainWindow::makeRectForEllipse(int x, int y)
{
    auto top_left_point = ui->graphicsView->mapToScene(x - kEllWidth / 2 * scaleRatio, y - kEllHeight / 2 * scaleRatio);
    auto bottom_right_point = ui->graphicsView->mapToScene(x + kEllWidth / 2 * scaleRatio, y + kEllHeight / 2 * scaleRatio);
    return QRectF(top_left_point, bottom_right_point);
}

QPolygonF MainWindow::makePolygon(int x, int y)
{
    QPolygonF polygon;
    constexpr size_t degrees = 5;

    size_t small_radius = kStarRadius/2;

    double step = M_PI/degrees, angle_deg = 180, rad;
    for (size_t count = 0; count < 2 * degrees; ++count)
    {
        rad = count % 2 == 0 ? small_radius : kStarRadius;
        auto point = ui->graphicsView->mapToScene(x + rad*cos(angle_deg) * scaleRatio, y  + rad*sin(angle_deg) * scaleRatio);
        polygon << point;
        angle_deg += step;

    }
    return polygon;
}

void MainWindow::setRatio(Dir dir)
{

    double ratio{0};
    switch (dir)
    {
        case Dir::up:
        {
            ratio = upRatio;
            break;
        }
        case Dir::down:
        {
            ratio = downRatio;
            break;
        }
    }
    scaleRatio *= ratio;
    ui->graphicsView->scale(ratio, ratio);
}


