#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myitem.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mGraphicsScene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(mGraphicsScene);

    MyItem* item = new MyItem();
    mGraphicsScene->addItem(item);

    connect(item, SIGNAL(sendRegionOfInterest(QPixmap)), this, SLOT(setRegionOfInterest(QPixmap)));
}

void MainWindow::setRegionOfInterest(const QPixmap &roi)
{
    ui->label->setPixmap(roi);
}

MainWindow::~MainWindow()
{
    delete ui;
}
