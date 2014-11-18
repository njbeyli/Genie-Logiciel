#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QMouseEvent>
#include "MyDock/mybotdock.h"
#include <QLineEdit>
#include <QLabel>
#include <QDebug>
#include "Lists/flight.h"
#include "CentralWidgets/tourdecontrole.h"
#include "CentralWidgets/guichet.h"
#include "CentralWidgets/guichetcheckin.h"
#include "CentralWidgets/guichetonboard.h"
#include "CentralWidgets/takeof.h"
#include "CentralWidgets/directionwidget.h"
#include "CentralWidgets/changementwid.h"
#include "CentralWidgets/maintenancewid.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->setMouseTracking(true);
    setMouseTracking(true);
    creatWidgets();
    setDockWid();
}


void MainWindow::creatWidgets()
{
    _centLayout=new QStackedLayout;
    ui->centroz->setLayout(_centLayout);
    _centWidList.append(new QPushButton("zeinib"));
    _centWidList.append(new GuichetCheckin);
    _centWidList.append(new GuichetOnBoard);
    _centWidList.append(new DirectionWidget);
    _centWidList.append(new ChangementWid);
    _centWidList.append(new TourDeControle);
    _centWidList.append(new TakeOf);
    _centWidList.append(new MaintenanceWid);
    foreach (QWidget *qw, _centWidList) {
        _centLayout->addWidget(qw);
    }
}

void MainWindow::setDockWid()
{
    _myDock= new MyBotDock(_centWidList,this);
    //ui->verticalLayout->addWidget(_myDock);
    connect(static_cast<MyBotDock *>(_myDock),SIGNAL(inElementClicked(int)),_centLayout,SLOT(setCurrentIndex(int)));
    connect(this,SIGNAL(dockNohide(bool)),_myDock,SLOT(setVisible(bool)));
    connect(this,SIGNAL(resized()),static_cast<MyBotDock *>(_myDock),SLOT(sizingEvent()));
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    emit resized();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(e->y()>height()-20)
        emit dockNohide(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// //////////////////////////         BACK THREAD SCRIPT        //////////////////////////////////





