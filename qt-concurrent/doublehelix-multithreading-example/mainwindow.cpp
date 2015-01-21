#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mProgressBar(new QProgressBar(this)),
    mGraphicsScene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    ui->statusBar->addPermanentWidget(mProgressBar);
    ui->graphicsView->setScene(mGraphicsScene);

    mCustomItem = new MyItem();
    mGraphicsScene->addItem(mCustomItem);
}

MainWindow::~MainWindow()
{
    delete ui;
}
