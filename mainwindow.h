#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedLayout>
#include <QHBoxLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QStackedLayout * _centLayout;
    QList<QWidget *> _centWidList;
    QWidget * _myDock;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void mouseMoveEvent(QMouseEvent *);
    void resizeEvent(QResizeEvent *);

private:

    void creatWidgets();
    void setDockWid();

signals:

    void dockNohide(bool);
    void resized();

public slots:

    //void setMidWidget(QModelIndex);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

