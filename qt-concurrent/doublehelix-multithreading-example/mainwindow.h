#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QGraphicsScene>

#include "myitem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QProgressBar* mProgressBar;
    QGraphicsScene* mGraphicsScene;
    MyItem* mCustomItem;
};

#endif // MAINWINDOW_H
