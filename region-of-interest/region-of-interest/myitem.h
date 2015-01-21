#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsPixmapItem>

class MyItem : public QObject, public QGraphicsPixmapItem
{
private:
    int mStartX, mStartY;
    int mEndX, mEndY;

    Q_OBJECT

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public:
    explicit MyItem(QObject* parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
    void sendRegionOfInterest(const QPixmap& roi);

public slots:

};

#endif // MYITEM_H

