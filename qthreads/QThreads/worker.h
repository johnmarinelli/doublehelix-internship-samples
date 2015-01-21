#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject
{
private:
    int mPercentageDone;

    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0);

signals:
    void finished();
    void percentage(int percentage);
    void error(QString err);

public slots:
    void process();

};

#endif // WORKER_H
