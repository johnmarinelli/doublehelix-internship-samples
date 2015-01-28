#include "myimage.h"
#include <QPainter>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <iostream>

MyImage::MyImage(QWidget *parent) :
    QLabel(parent),
    mBoundingRect(0, 0, 50, 50),
    mHovered(false)
{
    setMouseTracking(true);
}

void MyImage::paintEvent(QPaintEvent *e)
{
    qDebug("i'm being painted");
    QLabel::paintEvent(e);

    QPainter painter(this);
    painter.drawRect(mBoundingRect);
    if(mHovered) {
        QImage img(QSize(40, 40), QImage::Format_RGB32);
        img.fill(qRgb(0, 100, 200));

        painter.drawImage(0, 0, img);
    }

    painter.end();
}

void MyImage::mouseMoveEvent(QMouseEvent *e)
{
    int x = e->pos().x();
    int y = e->pos().y();
    int width = 5;
    int height = 5;

    QRect mouseBox(x, y, width, height);
    if(mouseBox.intersects(mBoundingRect)) {
        mHovered = true;
    }
    else mHovered = false;

    update();
}

