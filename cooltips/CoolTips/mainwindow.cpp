#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myimage.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MyImage* img = new MyImage(ui->frame);
    img->setPixmap(QPixmap(":/assets/doge.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
