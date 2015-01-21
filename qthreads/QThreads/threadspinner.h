#ifndef THREADSPINNER_H
#define THREADSPINNER_H

#include "worker.h"
#include <QObject>
#include <QThread>

class ThreadSpinner : public QObject
{
    Q_OBJECT
public:
    explicit ThreadSpinner(QObject* parent = 0);

    void initThread(Worker* worker, QThread* thread);

signals:

public slots:
private slots:
    void error(QString err);
};

#endif // THREADSPINNER_H
