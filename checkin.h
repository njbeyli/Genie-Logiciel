#ifndef CHECKIN_H
#define CHECKIN_H

#include "passager.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include<QtNetwork/QNetworkReply>
#include <QDialog>
#include <QWidget>
#include <iostream>
#include <QUrl>
#include<QThread>
#include<QtGui>
#include"counter.h"
#include "vol.h"
#include"obcounter.h"
#include"chi.h"
#include "direction.h"
#include "item.h"
#include "maintenance.h"
#include "update.h"
#include "fly.h"
#include "mainwindow.h"


namespace Ui {
class CheckIn;
}

class CheckIn : public QDialog
{
    Q_OBJECT

public:
    explicit CheckIn(QWidget *parent = 0);
    ~CheckIn();

public slots:
    void selected();
    void checked();

private:
    Ui::CheckIn *ui;
    MainWindow *MW;
    OBCounter* C;
    Fly * F;
    CHI* T;
    Direction *D;
    Maintenance *M;
    Update *U;


};

#endif // CHECKIN_H
