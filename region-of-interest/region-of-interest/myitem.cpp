#include "myitem.h"
#include <iostream>
#include <QGraphicsSceneMouseEvent>

MyItem::MyItem(QObject *parent) :
    QObject(parent),
    QGraphicsPixmapItem(new QGraphicsPixmapItem()),
    mStartX(0),
    mStartY(0),
    mEndX(0),
    mEndY(0)
{
    setFlag(ItemIsSelectable);
    setPixmap(QPixmap(QString::fromUtf8(":/assets/doge.jpg")));
}

QRectF MyItem::boundingRect() const
{
    return QGraphicsPixmapItem::boundingRect();
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsPixmapItem::paint(painter, option, widget);
}

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    mStartX = event->pos().x();
    mStartY = event->pos().y();

    update();
    QGraphicsItem::mousePressEvent(event);
}

void MyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    mEndX = event->pos().x();
    mEndY = event->pos().y();

    int rectX = std::min(mStartX, mEndX);
    int rectY = std::min(mStartY, mEndY);
    QRect roi(rectX, rectY, std::abs(mEndX - mStartX), std::abs(mEndY - mStartY));

    std::cout << roi.x() << " " << roi.y() << " " << roi.width() << " " << roi.height() << std::endl;
    QPixmap roiPixmap = this->pixmap().copy(roi);

    emit sendRegionOfInterest(roiPixmap);

    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
