#ifndef MYIMAGE_H
#define MYIMAGE_H

#include <QLabel>
#include <QRect>

class MyImage : public QLabel
{
private:
    QRect mBoundingRect;
    bool mHovered;

    Q_OBJECT
protected:
    void paintEvent(QPaintEvent* e);
    void mouseMoveEvent(QMouseEvent* e);

public:
    explicit MyImage(QWidget *parent = 0);

signals:

public slots:

};

#endif // MYIMAGE_H
