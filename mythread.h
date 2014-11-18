#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QMainWindow>
#include <iostream>
#include <QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include<QtNetwork/QNetworkReply>
#include<QWidget>
#include<QThread>

class MyThread : public QThread
{
    Q_OBJECT

public:
    MyThread();

protected:
    void run();

signals:
    void trigger();
    void temp();
};

#endif // MYTHREAD_H

