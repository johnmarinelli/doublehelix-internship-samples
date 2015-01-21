#include "threadspinner.h"
#include <QObject>

ThreadSpinner::ThreadSpinner(QObject* parent) :
    QObject(parent)
{
}

void ThreadSpinner::initThread(Worker* worker, QThread* thread)
{
    worker->moveToThread(thread);

    /* connect any errors worker gives to main window thread */
    connect(worker, SIGNAL(error(QString)), this, SLOT(error(QString)));

    /* when thread starts, start worker processing */
    connect(thread, SIGNAL(started()), worker, SLOT(process()));

    /* when worker is finished, tell thread to shut down */
    connect(worker, SIGNAL(finished()), thread, SLOT(quit()));

    /* when worker is finished, mark it for deletion */
    connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));

    /* to prevent weird crashes, connect the THREAD's finished signal to its own delete later slot just to be safe */
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
}

void ThreadSpinner::error(QString err)
{
    qDebug(err.toStdString().c_str());
}
