#include "myitem.h"
#include <QPen>
#include <QBuffer>
#include <QtConcurrent/QtConcurrent>

#include <iostream>

MyItem::MyItem(QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent),
    mPressed(false)
{
    setFlag(ItemIsMovable);
    setPixmap(QPixmap(QString::fromUtf8(":/assets/doge.jpg")));
}

QRectF MyItem::boundingRect() const
{
    return QRectF(0, 0, 300, 200);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsPixmapItem::paint(painter, option, widget);
}

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    mPressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

QPixmap manipulateImage(MyItem* item)
{
    QImage image = item->pixmap().toImage();

    for(quint32 i = 0; i < image.height(); ++i) {
        QRgb* line = (QRgb*)image.scanLine(i);
        for(quint32 j = 0; j < image.width(); ++j) {
            std::cout << qBlue(line[j]) << " from thread " << QThread::currentThreadId() << std::endl;
            line[j] += 20;
        }
    }

    return QPixmap::fromImage(image);
}

void MyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    std::cout << "Calling async function from thread " << QThread::currentThread() << std::endl;

    QFuture<QPixmap> done = QtConcurrent::run(&manipulateImage, this);
    done.waitForFinished();
    this->setPixmap(done.result());

    std::cout << "Finishing up from thread " << QThread::currentThread() << std::endl;

    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
