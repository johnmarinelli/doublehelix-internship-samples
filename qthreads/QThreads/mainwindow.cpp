#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "threadspinner.h"
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mProgressBar(new QProgressBar(this))
{
    ui->setupUi(this);

    /* add mProgressBar to our status bar, and stretch it */
    ui->statusBar->addPermanentWidget(mProgressBar, 1);

    QThread* thread = new QThread;
    Worker* worker = new Worker;

    ThreadSpinner ts;
    ts.initThread(worker, thread);
    thread->start();

    /*
     * connect using a queued connection since worker is on different thread
     * note: connect will automatically do this if QT senses receiver thread is different
     * than emitting thread
     */
    connect(worker, SIGNAL(percentage(int)), this, SLOT(showPercentage(int)), Qt::QueuedConnection);
}

void MainWindow::showPercentage(int percent)
{
    mProgressBar->setValue(percent);
    qDebug(std::to_string(percent).c_str());
}

MainWindow::~MainWindow()
{
    delete ui;
}
