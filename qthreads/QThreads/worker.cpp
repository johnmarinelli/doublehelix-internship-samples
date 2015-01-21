#include "worker.h"
#include <cmath>
#include <iostream>

Worker::Worker(QObject *parent) :
    QObject(parent),
    mPercentageDone(0)
{
    /*
     * never allocate using new in this
     * b/c allocation will be performed in main thread,
     * not the QThread this Worker will be moved to.
     */
}

/*
 * main threaded function
 * allocate using new here if needed
 */
void Worker::process()
{
    qDebug("Sup");
    int percentageDone = 0;

    for(int i = 0; i < 100000; ++i) {
        percentageDone = std::floor(i / 1000);
        if(percentageDone != mPercentageDone) {
            mPercentageDone = percentageDone;
            emit percentage(mPercentageDone);
        }
    }

    emit finished();
}
