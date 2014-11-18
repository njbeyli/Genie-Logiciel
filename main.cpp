#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QFile>
#include "mythread.h"
#include "treatthread.h"
#include "QObject"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    MyThread thread;
    TreatThread Tthread;
    QObject::connect( & thread, SIGNAL( trigger() ),
            & Tthread, SLOT( tempDeVol() ) );
    QObject::connect(& thread, SIGNAL( temp() ),
                     & Tthread, SLOT( voirTemps() ) );

    QFile file("/Users/nicolasjbeyli/build-Projet-Desktop_Qt_5_2_1_clang_64bit-Debug/MyStyle.qss");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug()<<"MaZabat";

    QTextStream in(&file);
    QString s("");
    while (!in.atEnd()) {
       s+= in.readLine();
    }

    w.setStyleSheet(s);

    thread.start();
    return a.exec();
}

